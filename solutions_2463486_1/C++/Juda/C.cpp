#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<vector>
using namespace std;
#define DEBUG 0
#define debug(cc) if(DEBUG)cout<<#cc<<" : "<<cc<<endl;
#define REP(i,n) for(i=0;i<n;++i)
#define FOR(i,j,k) for(i=j;i<=k;++i)
#define FORD(i,j,k) for(i=j;i>=k;--i)
#define met(i,j) memset(i,j,sizeof(i))
#define PB push_back
#define MK make_pair
#define sz(x) ((int)x.size())
#define IOopen ios_base::sync_with_stdio(false)
const int inf=2147483647;
typedef pair<int, int> PII;
typedef long long LL;
typedef unsigned long long ULL;
vector<LL> ans;
int a[100];

bool isPalindromes(LL x)
{
    int n=0,i;
    for(;x;x/=10)
    {
        a[++n]=x%10;
    }
    FOR(i,1,n)if(a[i]!=a[n+1-i])return 0;
    return 1;
}

void init()
{
    LL i;
    FOR(i,1,10000000)
    {
        if(isPalindromes(i) && isPalindromes(i*i))ans.PB(i*i);
    }
}

void work()
{
    int i,T;
    LL a,b,t1,t2;
    cin>>T;
    FOR(i,1,T)
    {
        cin>>a>>b;
        cout<<"Case #"<<i<<": ";
        t1=upper_bound(ans.begin(),ans.end(),a-1)-ans.begin();
        t2=upper_bound(ans.begin(),ans.end(),b)-ans.begin();
        cout<<t2-t1<<endl;
    }
}

int main()
{
    init();
    work();
}
