#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <queue>
#include <ctime>
#include <stdio.h>
#include <memory.h>
#include <windows.h>
using namespace std;
int R,N,M,K;
int product[20];
int A[15];
bool vis[10];
bool check(int A[])
{
    int i,j;
    for(i=1;i<=K;i++)
    {
        int X=product[i];
        for(j=1;j<=N;j++)
        {
            if(X%A[j]==0) X/=A[j];
        }
        if(X!=1) return false;
    }
    return true;
}
int flag;
void dfs(int p)
{
    if(flag) return;
    if(p>N)
    {
        if(check(A))
        {
            flag=1;
        }
        return;
    }
    int i;
    for(i=2;i<=8;i++) A[p]=i;
    dfs(p+1);
}
int main()
{
    freopen("C2.in","r",stdin);freopen("out.txt","w",stdout);
    int T,cas=0;
    cin>>T;
    while(T--)
    {
        cas++;
        printf("Case #%d:\n",cas);
        cin>>R>>N>>M>>K;
        int i,j,k;
        while(R--)
        {
            for(i=1;i<=K;i++) {scanf("%d",&product[i]);}
            memset(vis,false,sizeof(vis));
            for(i=1;i<=K;i++)
            {
                if(product[i]==1) continue;
                if(product[i]%2==0 && product[i]%4!=0) vis[2]=true;
                if(product[i]%3==0) vis[3]=true;
                if(product[i]%5==0) vis[5]=true;
                if(product[i]%7==0) vis[7]=true;
            }
            int c=0;
            for(i=2;i<=8;i++) if(vis[i]) c++;
            if(c<3) {printf("222222222222\n");continue;}
            A[1]=2;A[2]=3;A[3]=5;A[4]=7;
            flag=0;
            dfs(5);
            for(i=1;i<=N;i++) cout<<A[i];
            cout<<endl;
        }
    }
    return 0;
}
