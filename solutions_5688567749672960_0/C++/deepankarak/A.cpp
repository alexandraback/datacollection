#include<bits/stdc++.h>

using namespace std;

#define vi vector < int >
#define pii pair < int , int >
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define foreach(it,v) for( __typeof((v).begin())it = (v).begin() ; it != (v).end() ; it++ )
#define ll long long
#define llu unsigned long long
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define dbg(x) { cout<< #x << ": " << (x) << endl; }
#define dbg2(x,y) { cout<< #x << ": " << (x) << " , " << #y << ": " << (y) << endl; }
#define all(x) x.begin(),x.end()
#define mset(x,v) memset(x, v, sizeof(x))
#define sz(x) (int)x.size()

int dp[1000006];

int rev(int n)
{
    int x = 0;
    int N = n;
    while(n>0)
    {
        x = 10*x + n%10;
        n /= 10;
    }
    if(x < N && N%10 != 0)
    {
        return x;
    }
    return N-1;
}

int solve(int n)
{
    if(n == 1)
        return 1;
    if(dp[n]!=-1)
        return dp[n];
    int ret = min(solve(n-1),solve(rev(n)))+1;
    return dp[n] = ret;
}


int main()
{
    freopen("A.in","r",stdin);
    freopen("A.out","w",stdout);
    int t,tc=1;
    mset(dp,-1);
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        printf("Case #%d: %d\n",tc++,solve(n));
    }
    return 0;
}

