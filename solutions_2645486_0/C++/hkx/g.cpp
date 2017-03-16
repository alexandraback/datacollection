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
int V[10+1];
int E,R,N;
int ans=0;
void dfs(int k,int e,int s)
{
    if(k>N)
    {
        if(s>ans) ans=s;
        return;
    }
    int i;
    for(i=0;i<=e;i++) dfs(k+1,min(E,e-i+R),s+i*V[k]);
}
int main()
{
    freopen("B.in","r",stdin);freopen("out.txt","w",stdout);
    int T,cas=0;
    cin>>T;
    while(T--)
    {
        cas++;
        printf("Case #%d: ",cas);
        int i,j;
        cin>>E>>R>>N;
        for(i=1;i<=N;i++) scanf("%d",&V[i]);
        ans=0;
        dfs(1,E,0);
        cout<<ans<<endl;
    }
    return 0;
}
