#include <iostream>
#include <cstdio>
#include <string>
#include <map>

using namespace std;

map<char, char> m;
string a[3][2];

void init()
{
    a[0][0] = "ejp mysljylc kd kxveddknmc re jsicpdrysi" ;
    a[0][1] = "our language is impossible to understand" ;
    a[1][0] = "rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd" ;
    a[1][1] = "there are twenty six factorial possibilities" ;
    a[2][0] = "de kr kd eoya kw aej tysr re ujdr lkgc jv" ;
    a[2][1] = "so it is okay if you want to just give up" ;
    m['z'] = 'q';
    m['q'] = 'z';
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < a[i][0].size(); j++)
            m[a[i][0][j]] = a[i][1][j];
    }
    return;
}

int main()
{
    freopen("A-small-attempt0.in", "r", stdin);
    freopen("A-small-attempt0.out", "w", stdout);
    init();
    int t;
    cin >> t;
    getchar();
    for(int cs = 1; cs <= t; cs++)
    {
        string s;
        getline(cin, s);
        printf("Case #%d: ", cs);
        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] == ' ')
                putchar(' ');
            else
                cout << m[s[i]];
        }
        cout << endl;
    }
    return 0;
}
