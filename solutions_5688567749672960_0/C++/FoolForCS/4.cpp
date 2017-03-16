#include<bits/stdc++.h>

#define gcd __gcd
#define bitcount __builtin_popcountll
#define getcx getchar
#define rep(i,j,n) for(i=j;i<n;i++)
#define tr(it,c) for(auto it=(c).begin();it!=(c).end();it++)
#define pb push_back
#define mp make_pair
#define hell 1000000007
#define uset unordered_set
#define umap unordered_map

using namespace std;

typedef pair<int,int> pi;
typedef long long ll;
const int MAXN = 1e6;

bool p(int x, int N)
{
    return true;
}
int bin_search(int low, int high, int N)
{
    int mid;
    while(low<high)
    {
        mid = low + (high-low)/2;
        if(p(mid,N))
            high=mid;
        else
            low=mid+1;
    }
    if(!p(low,N))
        return -1;
    return low;
}
int dp[MAXN+1];
int rev(int n)
{
    int res = 0;
    while(n>0)
    {
        res = (res*10 + n%10);
        n/=10;
    }
    return res;
}
void precompute()
{
    int i;
    rep(i,1,MAXN+1)
        dp[i] = i;
    dp[1] = 1;
    rep(i,2,MAXN+1)
    {
        dp[i] = min(dp[i], dp[i-1]+1);
        if(rev(i)>i)
            dp[rev(i)]=min(dp[i]+1,dp[rev(i)]);
    }
}
int main()
{
    freopen("A-small-attempt0.in","r",stdin);
    freopen("out_A.txt","w",stdout);

   int T,i,res;
   precompute();
   cin>>T;
   for(int tt=1;tt<=T;tt++)
   {
       cout<<"Case #"<<tt<<": ";
       cin>>i;
       cout<<dp[i]<<endl;
   }
}
