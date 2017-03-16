#include<stdio.h>
#include<algorithm>
#define maxn 1005
using namespace std;

int T,n,nr,sol;
char s[maxn];

int main()
{
    freopen("date.in","r",stdin);
    freopen("date.out","w",stdout);

    scanf("%d\n",&T);
    for(int it=1;it<=T;it++)
    {
        scanf("%d %s\n",&n,s);

        nr=sol=0;
        for(int i=0;i<=n;i++)
         if(nr>=i) nr=nr+s[i]-'0';
         else
         {
             sol=sol+i-nr;
             nr=i+s[i]-'0';
         }

        printf("Case #%d: %d\n",it,sol);
    }

    return 0;
}
