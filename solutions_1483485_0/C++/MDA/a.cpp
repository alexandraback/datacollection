#include <string>
#include <stdio.h>
#include <iostream>
#include <algorithm>

std::string googlerese = "zyeqejp mysljylc kd kxveddknmc re jsicpdrysirbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcdde kr kd eoya kw aej tysr re ujdr lkgc jv";
std::string english =    "qaozour language is impossible to understandthere are twenty six factorial possibilitiesso it is okay if you want to just give up";
char map[255];


void solve() {
    std::string s;
    std::getline(std::cin, s);
    for (int i = 0; i < s.length(); ++i)
        s[i] = map[s[i]];
    printf("%s\n", s.c_str());
}

int main() {
    freopen("a_inp.txt", "r", stdin);
    freopen("a_out.txt", "w", stdout);
    for (int i = 0; i < 255; ++i)
        map[i] = i;
    for (int l = googlerese.length(), i = 0; i < l; ++i) 
        map[googlerese[i]] = english[i];
   /* std::sort(english.begin(), english.end());
    int l = std::unique(english.begin(), english.end()) - english.begin();
    for (int i = 1; i < l; ++i)
        if (english[i] != i - 1 + 'a') {
            printf("%c\n", (char)(i - 1 + 'a'));
            break;
        }*/
    int t = 0;
    scanf("%d\n", &t);
    for (int i = 1; i <= t; ++i) {
        printf("Case #%d: ", i);
        solve();
    }
}
