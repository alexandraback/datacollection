#include <iostream>
#include <fstream>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <queue>
#include <set>
#include <vector>
#include <map>
#include <sstream>

#define pb push_back
#define mp make_pair
#define ll long long
#define ull unsigned long long

using namespace std;

const int nm=52;
const int x[8]={-1,-1,-1,0,0,1,1,1};
const int y[8]={-1,0,1,-1,1,-1,0,1};

int m,n,k;
char kq[nm][nm];
bool found;
bool fr[nm*nm];
int a[nm*nm];
bool bks[nm][nm];
bool reached[nm][nm];
int l,r,q[nm*nm][2];

bool hople(int i,int j)
{
    return i>0 && i<=m && j>0 && j<=n;
}

void kt()
{
    int u,v,h;
    for(u=1;u<=m;++u)
    {
        for(v=1;v<=n;++v)
        {
            if (!bks[u][v]) break;
        }
        if (v<=n) break;
    }
    if (u>m) return;
    memset(reached,0,sizeof(reached));
    l=r=1;q[1][0]=u;q[1][1]=v;
    while (l<=r)
    {
        u=q[l][0];v=q[l][1];l++;
        for(h=0;h<8;++h)
        {
            if (hople(u+x[h],v+y[h]) && kq[u+x[h]-1][v+y[h]-1]=='.' && !reached[u+x[h]][v+y[h]])
            {
                reached[u+x[h]][v+y[h]]=1;
                if (!bks[u+x[h]][v+y[h]])
                {
                    r++;q[r][0]=u+x[h];q[r][1]=v+y[h];
                }
            }
        }
    }
    for(u=1;u<=m;++u)
    {
        for(v=1;v<=n;++v)
        {
            if (kq[u-1][v-1]=='.' && bks[u][v] && !reached[u][v]) return;
        }
    }
    found=1;
}

void thu(int i)
{
    int j,u,v,h;vector<pair<int,int> > hi;
    for(j=a[i-1]+1;j+k-i<=m*n;++j)
    {
        if (fr[j])
        {
            a[i]=j;fr[j]=0;
            u=a[i]/n;if (a[i]%n) u++;
            v=a[i]-(u-1)*n;
            kq[u-1][v-1]='*';
            for(h=0;h<8;++h) if (hople(u+x[h],v+y[h]) && !bks[u+x[h]][v+y[h]])
            {
                hi.pb(mp(u+x[h],v+y[h]));bks[u+x[h]][v+y[h]]=1;
            }
            if (!bks[u][v])
            {
                hi.pb(mp(u,v));bks[u][v]=1;
            }
            if (i==k) kt();
            else thu(i+1);
            if (found) return;
            fr[j]=1;
            kq[u-1][v-1]='.';
            for(h=0;h<int(hi.size());++h) bks[hi[h].first][hi[h].second]=0;
        }
    }
}

void xuli()
{
    int i,j;
    for(i=0;i<m;++i)
    {
        for(j=0;j<n;++j) kq[i][j]='.';
        kq[i][n]=0;
    }
    if (k==0)
    {
        kq[0][0]='c';
        found=1;
        return;
    }
    if (m==1)
    {
        for(j=1;j<=k;++j) kq[0][j-1]='*';
        kq[0][n-1]='c';
        found=1;
        return;
    }
    if (n==1)
    {
        for(j=1;j<=k;++j) kq[j-1][0]='*';
        kq[m-1][0]='c';
        found=1;
        return;
    }
    if (k==m*n-1)
    {
        for(i=0;i<m;++i)
        {
            for(j=0;j<n;++j) kq[i][j]='*';
            kq[i][n]=0;
        }
        kq[0][0]='c';
        found=1;
        return;
    }
    memset(fr,1,sizeof(fr));
    memset(bks,0,sizeof(bks));
    found=0;
    thu(1);
    if (found)
    {
        for(i=1;i<=m;++i)
        {
            for(j=1;j<=n;++j) if (!bks[i][j])
            {
                kq[i-1][j-1]='c';return;
            }
        }
    }
}

int main()
{
    freopen("C-small-attempt8.in","r",stdin);
    freopen("vd.out","w",stdout);
    int t,it,i;
    scanf("%d",&t);
    for(it=1;it<=t;++it)
    {
        scanf("%d%d%d",&m,&n,&k);
        xuli();
        printf("Case #%d:\n",it);
        if (!found) printf("Impossible\n");
        else
        {
            for(i=0;i<m;++i) printf("%s\n",kq[i]);
        }
    }
}
