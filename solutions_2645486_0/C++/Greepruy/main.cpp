#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <cstring>
using namespace std;
int e,r,n;
int num[50];
bool cmp(int a,int b)
{
    return a>b;
}
int ans;
void DFS(int now,int left,int value)
{
    if(now>n)
    {
        ans=max(ans,value);
        return;
    }
    for(int i=0;i<=left;i++)
    {
        //ans=max(value+num[now]*i,ans);
        DFS(now+1,min(left-i+r,e),value+num[now]*i);
    }
}
int main()
{
    freopen("B-small-attempt2.in","r",stdin);
    //freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int cas;
    scanf("%d",&cas);
    for(int ci=1;ci<=cas;ci++)
    {
        scanf("%d%d%d",&e,&r,&n);
        for(int i=0;i<n;i++)
        {
            scanf("%d",&num[i]);
        }
        sort(num,num+n,cmp);
        //for(int i=0;i<n;i++) cout << num[i] << ' ' ;
        //cout << endl;
        ans=0;
        DFS(0,e,0);
        while(next_permutation(num,num+n))
        {
            DFS(0,e,0);
        }
        cout <<"Case #" << ci << ": " << ans << endl;
    }
}
