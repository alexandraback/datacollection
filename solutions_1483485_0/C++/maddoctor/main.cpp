/*
ID: CUGB-wwj
PROG:
LANG: C++
*/
#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <cmath>
#include <ctime>
#define INF 1LL<<60
#define MAXN 1005
#define MAXM 1005
#define L(x) x<<1
#define R(x) x<<1|1
#define eps 1e-4
using namespace std;
char s[111];
char a[] = "ejp mysljylc kd kxveddknmc re jsicpdrysi";
char aa[] = "our language is impossible to understand";
char b[] = "rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd";
char bb[] = "there are twenty six factorial possibilities";
char c[] = "de kr kd eoya kw aej tysr re ujdr lkgc jv";
char cc[] = "so it is okay if you want to just give up";
int mp[333];
void init()
{
    int lena = strlen(a);
    int lenb = strlen(b);
    int lenc = strlen(c);
    for(int i = 0; i < lena; i++) mp[a[i]] = aa[i];
    for(int i = 0; i < lenb; i++) mp[b[i]] = bb[i];
    for(int i = 0; i < lenc; i++) mp[c[i]] = cc[i];
    mp['q'] = 'z';
    mp['z'] = 'q';
}
int main()
{
    freopen("D:/A-small-attempt1.in","r",stdin);
    freopen("D:/A-small-attempt1.out","w",stdout);
    int T;
    int cas = 0;
    init();
    scanf("%d", &T);
    getchar();
    while(T--)
    {
        printf("Case #%d: ", ++cas);
        gets(s);
        int len = strlen(s);
        for(int i = 0; i < len; i++)
        {
            if(!isalpha(s[i])) printf("%c", s[i]);
            else
            printf("%c", mp[s[i]]);
        }
        printf("\n");
    }
    return 0;
}
