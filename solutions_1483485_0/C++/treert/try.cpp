#include <iostream>
#include <math.h>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <map>
#include <string.h>
using namespace std;

#define OK puts("OK")
const int N = 2012;
char t[27] = "yhesocvxduiglbkrztnwjpfmaq";
char s[110];
int main() {
    freopen("A-small-attempt0.in", "r", stdin);
    freopen("out", "w", stdout);
    int len;
    int cas;
    scanf("%d",&cas);
    gets(s);
    for(int k = 1; k <= cas; k++){
        gets(s);
        len = strlen(s);
        for(int i = 0; i < len; i++){
            if(s[i] == ' ') continue;
            s[i] = t[s[i]-'a'];
        }
        printf("Case #%d: %s\n",k,s);
    }
}