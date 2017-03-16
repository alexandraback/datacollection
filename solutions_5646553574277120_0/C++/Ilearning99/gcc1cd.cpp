#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;

int val[33];

int num[6];

int main()
{
    int j,T,casn=0,C,D,V,i,state;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d%d",&C,&D,&V);
        for(i=0;i<D;i++)
            scanf("%d", num+i);
        for(i=0;i<=V;i++)
            val[i]=0;
        state=(1<<D);
        for(i=1;i<state;i++)
        {
            int tempsum=0;
            for(j=0;j<D;j++){
                if(i&(1<<j))
                    tempsum+=num[j];
            }
            val[tempsum]++;
        }
        int ans=0;
        for(i=1;i<=V;i++)
           if(val[i]==0)
               ans++;
        printf("Case #%d: %d\n", ++casn, ans);
    }
    return 0;
}
