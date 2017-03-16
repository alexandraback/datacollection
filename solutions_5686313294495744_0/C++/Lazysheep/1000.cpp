#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<queue>
#include<stack>
#include<map>
#include<time.h>
#include<cmath>
#include<vector>
#include <iomanip>
#define PB(u)  push_back(u);
#define AA   first
#define BB   second
#define inf 0x3f3f3f3f
using namespace std ;
#define MAX 2005
#define sz size()
typedef long long ll ;
typedef pair<int,int> PII ;
const double eps=1e-8;
const double pi=acos(-1.0);

map<string,int > m ;
int d[MAX][2];
char s[MAX];
int u[MAX],v[MAX];

int ans,n ;

bool used[MAX];

bool  check()
{
    memset(d,0,sizeof(d));
    for(int i=0; i<n; i++)
    {
        if(used[i])
        {
            d[u[i]][0]++;
            d[v[i]][1]++;
        }
    }
    for(int i=0; i<n; i++)
    {
        if(d[u[i]][0]>1&&d[v[i]][1]>1||d[u[i]][0]==0||d[v[i]][1]==0)
            return false ;
    }
    return true ;
}

void dfs(int id,int num)
{
    if(id==n)
    {
        if(check())
            ans=max(ans,num);
        return ;
    }
    int temp=used[id];
    used[id]=0;
    dfs(id+1,num+1);
    used[id]=1;
    dfs(id+1,num);
    used[id]=temp;
}

int main()
{
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
    int T;
    cin>>T;
    int cas=1;
    while(T--)
    {
        memset(d,0,sizeof(d));
        memset(used,0,sizeof(used));
        m.clear();
        scanf("%d",&n);
        int cnt=1;
        for(int i=0; i<n; i++)
        {
            scanf(" %s",s);
            string str(s);
            if(m[s]==0)
                m[s]=cnt++;
            u[i]=m[s];
            scanf(" %s",s);
            str=s;
            if(m[s]==0)
                m[s]=cnt++;
            v[i]=m[s];
        }
        ans=0;
        dfs(0,0);
        printf("Case #%d: %d\n",cas++,ans);
    }
    return 0 ;
}
