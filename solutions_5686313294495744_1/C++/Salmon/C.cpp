#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <deque>
#include <map>
using namespace std;
map<string,int> mx;
map<string,int> my;
vector<int> e[3000];
vector<int> c[3000];
vector<int> f[3000];
vector<int> r[3000];
int vs[3000];
void ade(int x,int y,int cf,int cy)
{
    e[x].push_back(y);
    e[y].push_back(x);
    f[x].push_back(0);
    f[y].push_back(0);
    c[x].push_back(cf);
    c[y].push_back(cy);
    r[x].push_back(c[y].size()-1);
    r[y].push_back(c[x].size()-1);
}
int fd(int x,int cf)
{
    if(cf==0)
        return 0;
    if(vs[x])
        return 0;
    if(x==2400)
        return 1;
    vs[x]=1;
    for(int i=0;i<e[x].size();i++)
    {
        if(c[x][i]>f[x][i]&&fd(e[x][i],c[x][i]-f[x][i])==1)
        {
            f[x][i]++;
            f[e[x][i]][r[x][i]]--;
            return 1;
        }
    }
    return 0;
}
void wk(int t)
{
    int n;
    scanf("%d",&n);
    mx.clear();
    my.clear();
    for(int i=0;i<=2599;i++)
        e[i].clear(),c[i].clear(),f[i].clear(),r[i].clear();
    int px=2;
    int py=1010;
    int ct=0;
    for(int i=1;i<=n;i++)
    {
        string a,b;
        cin>>a>>b;
        if(mx.find(a)==mx.end())
            mx[a]=px++,ct++,ade(0,mx[a],1,0);
        if(my.find(b)==my.end())
            my[b]=py++,ct++,ade(my[b],2400,1,0);
        ade(mx[a],my[b],1,0);
    }
    int ca=0,cc=0;
    while(1)
    {
        for(int i=0;i<=2500;i++)
            vs[i]=0;
        //printf("FLOW %d\n",cc+1);
        int vv=fd(0,1);
        if(vv==0)
            break;
        ca+=2;
        cc++;
    }
    //printf("HI %d %d %d\n",ct,ca,cc);
    int an=n-(ct-ca+cc);
    printf("Case #%d: %d\n",t,an);
}
int main()
{
    freopen("C-large.in","r",stdin);
    freopen("C.out","w",stdout);
    int t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++)
    {
        wk(i);
    }
}
