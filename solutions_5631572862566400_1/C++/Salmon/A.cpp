#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
int n;
int ct[2000];
vector<int> tc[2000];
int vt[2000];
int cy[2000];
int ug[2000];
int vs(int x,int d)
{
    if(vt[x]!=-1)
    {
        if(cy[x]==-1)
            cy[x]=d-vt[x];
        return cy[x];
    }
    vt[x]=d;
    return vs(ct[x],d+1);
}
int ss;
int ls;
int df(int x)
{

    int re=0;
    for(int j=0;j<tc[x].size();j++)
    {
        ls=x;
        re=max(df(tc[x][j]),re);
    }
    return re+1;
}
int wk(int t)
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        tc[i].clear();
    for(int i=1;i<=n;i++)
    {
        cin>>ct[i];
        tc[ct[i]].push_back(i);
        vt[i]=-1;
        cy[i]=-1;
        ug[i]=0;
    }
    int an=0;
    for(int i=1;i<=n;i++)
    {
        an=max(an,vs(i,1));
    }
    int pp=0;
    int aa=0;
    int ab=0;
    for(int i=1;i<=n;i++)
        vt[i]=0;
    for(int i=1;i<=n;i++)
    {
        if(ct[ct[i]]==i&&i<ct[i])
        {
            aa=0;
            ab=0;
            ug[i]=i;
            ug[ct[i]]=i;
            for(int j=0;j<tc[i].size();j++)
            {
                if(tc[i][j]==ct[i])
                    continue;
                aa=max(aa,df(tc[i][j]));
            }
            for(int j=0;j<tc[ct[i]].size();j++)
            {
                if(tc[ct[i]][j]==i)
                    continue;
                ab=max(ab,df(tc[ct[i]][j]));
            }
            pp+=aa+ab+2;
        }
    }
    an=max(an,pp);
    cout<<"Case #"<<t<<": "<<an<<endl;
}
int main()
{
    string s;
    int T;
    freopen("C-large.in","r",stdin);
    freopen("C.out","w",stdout);
    cin>>T;
    for(int tt=1;tt<=T;tt++)
    {
        wk(tt);
    }
}
