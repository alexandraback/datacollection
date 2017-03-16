#include <iostream>
#include <map>

using namespace std;

void func(char line[], map<char, char> &datas) {
    for(int i = 0; line[i]; i++)
    {
        cout << datas[line[i]];
    }
}

int main() 
{
    map<char, char> datas;
    char origin[] = "ejp mysljylc kd kxveddknmc re jsicpdrysi"
    "rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd"
    "de kr kd eoya kw aej tysr re ujdr lkgc jv";
    char trans[] = "our language is impossible to understand"
    "there are twenty six factorial possibilities"
    "so it is okay if you want to just give up";
    datas['z'] = 'q';
    datas['q'] = 'z';
    for(int i = 0; origin[i]; i++)
    {
        datas[origin[i]] = trans[i];
        //datas[trans[i]] = origin[i];
    }
    int n;
    cin >> n;
    getchar();
    char line[102];
    for(int i = 0; i < n; i++)
    {
        cin.getline(line, 102);
        cout << "Case #" << (i + 1) << ": ";
        func(line, datas);
        cout << endl;
    }
    return 0;
}
