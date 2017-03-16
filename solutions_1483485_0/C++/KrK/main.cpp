#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

const string inG = "abcdefghijklmnopqrstuvwxyz";
const string inE = "yhesocvxduiglbkrztnwjpfmaq";

int t;
string s;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    scanf("%d", &t); getline(cin, s);
    for (int tc = 1; tc <= t; tc++) {
        getline(cin, s);
        printf("Case #%d: ", tc);
        for (int i = 0; i < s.length(); i++)
            if (s[i] == ' ') printf(" ");
            else printf("%c", inE[inG.find(s[i])]);
        printf("\n");
    }
    return 0;
}
