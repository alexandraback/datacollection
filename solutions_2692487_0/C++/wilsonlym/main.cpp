#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<algorithm>

using namespace std;

int c[200];

int main()
{
    freopen("x.in","r",stdin);
    freopen("x.txt","w",stdout);
    int T,A,n;
    scanf("%d",&T);
    for(int K=1;K<=T;K++)
    {
        scanf("%d%d",&A,&n);
        int ans=1000000,pre=0,res=n;
        for(int i=0;i<n;i++)
          scanf("%d",&c[i]);
        sort(c,c+n);
        if(A==1)
        {
            printf("Case #%d: %d\n",K,n);
            continue;
        }
        int i=0;
        while(i<n)
        {
            ans=min(ans,pre+res);
            if(A<=c[i]){A=2*A-1;pre++;continue;}
            A+=c[i];
            i++;
            res--;
        }
        ans=min(ans,pre+res);
        printf("Case #%d: %d\n",K,ans);
    }




    return 0;
}
