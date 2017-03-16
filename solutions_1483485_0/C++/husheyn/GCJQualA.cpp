#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;

int t;
string s;
char mapping[200];

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    mapping['a'] = 'y';
    mapping['o'] = 'e';
    mapping['z'] = 'q';
    mapping['q'] = 'z';
    string s1 = "ejp mysljylc kd kxveddknmc re jsicpdrysi rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd de kr kd eoya kw aej tysr re ujdr lkgc jv";
    string s2 = "our language is impossible to understand there are twenty six factorial possibilities so it is okay if you want to just give up";
    for(int i = 0; i < s1.size(); i++) if (s1[i] != ' ') mapping[s1[i]] = s2[i];
    scanf("%d\n", &t);
    for(int i = 1; i <= t; i++)
    {
        getline(cin, s);
        string ans = "";
        for(int j = 0; j < s.size(); j++)
            if (s[j] == ' ') ans += ' ';
            else ans += mapping[s[j]];
        cout << "Case #" << i << ": " << ans << endl;
    }
    return 0;
}
