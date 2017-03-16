#include<bits/stdc++.h>
using namespace std;


char s[5000];
int main()
{
    freopen("1.in","r",stdin);
    freopen("2.out","w",stdout);
    int ti=1,t;scanf("%d",&t);
    while(t--)
    {
        int k,now=0,sum=0;scanf("%d%s",&k,s);
        for(int i=0;i<=k;i++)
        {
            sum+=max(0,i-now);
            now+=s[i]-'0'+max(0,i-now);
        }
        printf("Case #%d: %d\n",ti++,sum);
    }
    return 0;
}
