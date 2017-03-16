#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<queue>
#include<cstring>
#include<cmath>
using namespace std;
char s[2001];
main()
{
    freopen("A-small-attempt0.in","r",stdin);
    freopen("A-small-attempt0.out","w",stdout);
    int T;scanf("%d",&T);
    for(int cas=1;cas<=T;cas++)
    {
        int m;
        scanf("%d%s",&m,s);
        int now=s[0]-'0';
        int ans=0;
        for(int i=1;i<=m;i++)
        {
            int t=s[i]-'0';
            if(now<i) {ans+=(i-now);now=i;}
            now+=t;
        }
        printf("Case #%d: %d\n",cas,ans);
    }
}
