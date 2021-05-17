#include <fstream> 
#include <iostream>
#include <string>
#include <conio.h>
#include <windows.h>
using namespace std;
class univ {
public: char imput[50];
      string line;
      string newline;
      bool check = true;
      void disciplines(int& i)
      {
          setlocale(LC_ALL, "rus"); // русский язык
          ifstream claim1;
         
          ofstream claim;
         
          if (i == 1) { goto start; }
          else
          {
              cout << "a - Готовые притензии" << endl;            
              switch (_getch()) {
              case 'a': case 'A':
                  cout << endl;
                  claim1.open("claim.txt");
                  if (claim1.is_open())
                  {
                      while (getline(claim1, line))
                      {
                          cout << line << endl;
                      }
                      cout << endl;
                      claim1.close();     // закрываем файл(это все цикл для чтения всех строк в файле да)
                      return;
                  }
              
              default: printf("Ошибка, повторите \n");
              }
          start:
                  claim.open("claim.txt", ios_base::app);
                  cout << "Новая притензия - ";
                  getline(cin, newline);
                  claim << endl << newline;
                  return;              
          }
      }
};
int main()
{
    SetConsoleCP(1251); // Ввод с консоли в кодировке 1251
    SetConsoleOutputCP(1251); // Вывод на консоль в кодировке 1251.
    bool check = true;
    setlocale(LC_ALL, "rus"); // русский язык
    bool work = true;
    univ univer;
    int i;
    while (work)
    {
        cout << "-------------------------------------------------" << endl;
        cout << "Вход в систему" << endl;
        cout << "-------------------------------------------------" << endl;
        cout << "a - просмотр" << endl;
        cout << "b - Напишите" << endl;
        cout << "-------------------------------------------------" << endl;
        switch (_getch()) {
        case 'a': case 'A':
            i = 0;
            goto choise;
        case 'b': case 'B':
            i = 1;
            goto choise;
        }
    choise:
        cout << "-------------------------------------------------" << endl;
        cout << "a - Притензии" << endl;
        cout << "b - выход из программы" << endl;
        cout << "-------------------------------------------------" << endl;
        switch (_getch()) {
        case 'a': case 'A':
            univer.disciplines(i);
            break;
        default: printf("Ошибка, повторите \n");
        }
    }
    return 0;
}
