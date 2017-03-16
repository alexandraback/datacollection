#include <iostream>
#include <stdio.h>
#include <memory.h>
using namespace std;
const int N=256;
char dp[N],s[N];

int main()
{
    freopen("A-small-attempt2.in","r",stdin);
    freopen("A-small-attempt2.out","w",stdout);
    for(int i='a';i<='z';++i)
        dp[i]=i;
    char *p1="ejp mysljylc kd kxveddknmc re jsicpdrysirbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcdde kr kd eoya kw aej tysr re ujdr lkgc jv",
         *p2="our language is impossible to understandthere are twenty six factorial possibilitiesso it is okay if you want to just give up";
    for(int i=0;p1[i];++i)
        dp[ p1[i] ] = p2[i];
    dp['q']='z';
    dp['z']='q';
    int tt,kk=1;
    for(scanf("%d",&tt),gets(s);tt--;)
    {
        printf("Case #%d: ",kk++);
        gets(s);
        for(int i=0;s[i];++i)
            putchar(dp [ s[i] ]);
        puts("");
    }
    return 0;
}
