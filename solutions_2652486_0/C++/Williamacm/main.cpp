#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
int r,n,m,k;
int a[109][10],no[3];
bool check(int v)
{
    if(v==1) return 1;
    for(int i=0;i<n;i++)
    if(no[i]==v) return 1;
    for(int i=0;i<n;i++)
    for(int j=i+1;j<n;j++)
    if(no[i]*no[j]==v) return 1;
    if(n==3&&no[0]*no[1]*no[2]==v) return 1;
    return 0;
}
bool fin;
void dfs(int ca,int p)
{
    if(p==n)
    {
        for(int i=0;i<k;i++)
        if(!check(a[ca][i])) return;

        fin=1;
        for(int i=0;i<n;i++)
        {
            printf("%d",no[i]);
        }
        return;
    }
    for(int i=2;i<=m;i++)
    {
        no[p]=i;
        dfs(ca,p+1);
        if(fin) return;
    }
}
void init()
{
    cin>>r>>n>>m>>k;
    for(int i=0;i<r;i++)
    for(int j=0;j<k;j++) scanf("%d",&a[i][j]);
    for(int i=0;i<r;i++)
    {
        fin=0;
        dfs(i,0);
        puts("");
    }
}
int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int w;
    cin>>w;
    for(int id=1;id<=w;id++)
    {
        printf("Case #%d:\n",id);
        init();
    }
    //    cout << "Hello world!" << endl;
    return 0;
}
