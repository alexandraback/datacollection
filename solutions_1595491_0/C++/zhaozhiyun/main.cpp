#include <iostream>
#include <fstream>
#include <string.h>
#include <stdio.h>

using namespace std;

int main()
{
    freopen("B-small-attempt0.in","r",stdin);
    freopen("out.txt","w",stdout);
    int T,N,S,p;
    int a[200];
    int temp[200];
    int ans;
    cin>>T;
    for(int t=1;t<=T;t++)
    {
        ans=0;
        memset(temp,0,sizeof(temp));
        scanf("%d%d%d",&N,&S,&p);
        for(int i=0;i<N;i++)
        {
            scanf("%d",&a[i]);
            if(a[i]>=3*p-2) temp[i]=1;
            else if(a[i]>=3*p-4) temp[i]=2;
        }
        if(p==0) { printf("Case #%d: %d\n",t,N); continue;}
        for(int i=0;i<N;i++)
        {
            if(temp[i]==1) ans++;
            if(temp[i]==2&&S>0&&p>1) {ans++; S--;}
        }
        printf("Case #%d: %d\n",t,ans);
    }
    return 0;
}
