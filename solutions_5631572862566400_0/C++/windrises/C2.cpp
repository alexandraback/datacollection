#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<string>
#include<stack>
#include<queue>
#include<vector>
#include<set>
#include<map>
#include<bitset>
#include<ctime>
#include<complex>
#define ft first
#define sd second
#define pb push_back
#define mkp make_pair
#define Min(a,b) ((a)<(b)?(a):(b))
#define Max(a,b) ((a)<(b)?(b):(a))
using namespace std;
typedef long long LL;
typedef pair<int,int> Pair;
const int inf=0x3f3f3f3f;
const double eps=1e-6;
const int mod=1e9+7;
const int maxn=1010;
int n;
int a[maxn];
bool f[maxn];
int ans;
int b[maxn];
bool ok(int m)
{
    bool yes=1;
    for(int i=0;i<m;i++)
    {
        int p=b[i],q=a[p];
        int l=(i+m-1)%m,r=(i+1)%m;
        if(q!=b[l]&&q!=b[r])
        {
            yes=0;
            break;
        }
    }
    if(yes) return 1;
    while(next_permutation(b,b+m))
    {
        yes=1;
        for(int i=0;i<m;i++)
        {
            int p=b[i],q=a[p];
            int l=(i+m-1)%m,r=(i+1)%m;
            if(q!=b[l]&&q!=b[r])
            {
                yes=0;
                break;
            }
        }
        if(yes) return 1;
    }
    return 0;
}
void dfs(int p)
{
    if(p>n)
    {
        int cnt=0;
        for(int i=1;i<=n;i++)
            if(f[i])
            {
                b[cnt++]=i;
            }
        //cout<<cnt<<endl;
        if(ok(cnt))
        {
            ans=max(ans,cnt);
        }
        return;
    }
    f[p]=1;
    dfs(p+1);
    f[p]=0;
    dfs(p+1);
}
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    //freopen("C-small-attempt1.in","r",stdin);
    //freopen("C-small-attempt1.out","w",stdout);
    int T;
    scanf("%d",&T);
    for(int kase=1;kase<=T;kase++)
    {
        cin>>n;
        for(int i=1;i<=n;i++)
            cin>>a[i];
        memset(f,0,sizeof(f));
        ans=0;
        dfs(1);
        printf("Case #%d: %d\n",kase,ans);
    }
}
