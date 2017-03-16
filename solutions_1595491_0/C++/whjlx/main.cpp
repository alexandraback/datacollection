#include<stdio.h>
#include<iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

int main()
{
   // freopen("B-small-attempt0.in","r",stdin);
   //freopen("out","w",stdout);
    int cases,ans;
    scanf("%d",&cases);
    for(int k=1; k<=cases; ++k)
    {
        int n,s,p;
        int t[110];
        ans=0;
        scanf("%d%d%d",&n,&s,&p);
        for(int i=0; i<n; ++i)
        {
            scanf("%d",&t[i]);
            int x=t[i]-p;
            if(x>=0)
            {
                int y=x/2;
                if(y>=p-1)
                {
                    ans++;
                }
                if(y==p-2&&s>0)
                {
                    ans++;
                    s--;
                }
            }
        }
        printf("Case #%d: %d\n",k,ans);
    }
}
