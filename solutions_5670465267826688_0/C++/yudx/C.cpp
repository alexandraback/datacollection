#include<stdio.h>
#include<algorithm>
#include<vector>
#include<math.h>
#include<string.h>
#include<vector>
#include<map>
#include<set>
#include<iostream>

using namespace std;

typedef long long ll;

int pr[5][5]={{},{0,1,2,3,4},{0,2,-1,4,-3},{0,3,-4,-1,2},{0,4,3,-2,-1}};

int p(int a)
{
    return a>=0?a:-a;
}

int mul(int a,int b)
{
    int r=pr[p(a)][p(b)];
    if(a*b<0) r=-r;
    return r;
}

int ksm(int te,ll k)
{
    int r=1;
    while(k>0)
    {
        if(k&1) r=mul(r,te);
        te=mul(te,te);
        k>>=1;
    }
    return r;
}

char c[10005];
int a[10005],b[10005];
int l;
ll x;
vector<int> pos[20];

void solve()
{
    int i,j;b[0]=1;pos[6].push_back(0);
    for(i=0;i<l;i++) {b[i+1]=mul(b[i],a[i]);pos[b[i+1]+5].push_back(i+1);}
    if(l*x<3||ksm(b[l],x)!=-1) {printf("NO\n");return;}
    int cur=1;
    ll p1=-1,p2=-1;
    for(i=0;i<x&&i<4;i++)
    {
        int te=mul(ksm(cur,3),2)+5;
        if(!pos[te].empty()) {p1=ll(i)*l+pos[te][0];break;}
        cur=mul(cur,b[l]);
    }
    if(p1<0) {printf("NO\n");return;}
    cur=1;
    for(i=0;i<x&&i<8;i++)
    {
        int te=mul(ksm(cur,3),4)+5;
        if(!pos[te].empty())
        {
            p2=ll(i)*l+pos[te][pos[te].size()-1];
            if(p2<=p1) {p2=-1;continue;}
            else break;
        }
        cur=mul(cur,b[l]);
    }
    if(p2<0) {printf("NO\n");return;}
    printf("YES\n");return;
}

int main()
{
    freopen("C-small-attempt0.in","r",stdin);
    freopen("C-small-attempt0.out","w",stdout);
    int T,I=1,i,j;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d %lld",&l,&x);
        scanf("%s",c);
        for(i=0;i<20;i++) pos[i].clear();memset(b,0,sizeof(b));
        for(i=0;i<l;i++) a[i]=(c[i]-'i'+2);
        printf("Case #%d: ",I++);
        solve();
    }
    return 0;
}
