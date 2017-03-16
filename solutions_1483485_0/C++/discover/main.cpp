#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <cstring>
#include <string>
#include <vector>
#include <ctime>
#include <map>
#include <set>
#include <queue>
using namespace std;

#define rep(i,a,b) for(int i = a; i < b; ++i)
#define pb(x) push_back(x)
#define sz size()
typedef long long ll;
const int N = 1000 + 11;

char dic[26];
int main() {
    int cas,tcas = 0;
    char a[] = {"ejp mysljylc kd kxveddknmc re jsicpdrysirbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcdde kr kd eoya kw aej tysr re ujdr lkgc jv"};
    char b[] = {"our language is impossible to understandthere are twenty six factorial possibilitiesso it is okay if you want to just give up"};
    memset(dic,'A',sizeof(dic));
    for (int i = 0; i < strlen(a); ++i) if (a[i] >='a' && a[i] <='z'){
       if (dic[a[i]-'a'] == 'A') dic[a[i] - 'a'] = b[i]; 
       else if (dic[a[i]-'a'] != b[i]) puts("ERROR");
    }
    dic['z'-'a'] = 'q';
    dic['q'-'a'] = 'z';
    for (int i = 0; i < 26; ++i) if (dic[i] == 'A') printf("%c\n",i + 'a');
    freopen("in","r",stdin);
    freopen("out","w",stdout);
    for (cin >> cas,getchar(); cas; --cas){
        printf("Case #%d: ",++tcas);
        char ch;
        while ((ch = getchar())!=EOF && ch != '\n'){
            if (ch >= 'a' && ch <= 'z') putchar(dic[ch - 'a']);
            else putchar(ch);
        }
        puts("");
    }
}