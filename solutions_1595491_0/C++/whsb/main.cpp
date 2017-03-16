#include <stdio.h>
#include <string.h>
#include<stdio.h>
#include<iostream>
using namespace std;

int main()
{
    //freopen("B-small-attempt0.in","r",stdin);
    //freopen("out","w",stdout);
    int Case,Ans,N,s,p,t[110];
    scanf("%d",&Case);
    for(int Cas=1; Cas<=Case; ++Cas)
    {

        Ans=0;
        scanf("%d%d%d",&N,&s,&p);
        for(int i=0; i<N; ++i)
        {
            scanf("%d",&t[i]);
            int Tmp1=t[i]-p;
            if(Tmp1>=0)
            {
                int Tmp2=Tmp1/2;
                if(Tmp2>=p-1)
                {
                    Ans++;
                }
                if((s>0)&&(Tmp2==p-2))
                {
                    s--;
                    Ans++;
                }
            }
        }
        printf("Case #%d: %d\n",Cas,Ans);
    }
}
