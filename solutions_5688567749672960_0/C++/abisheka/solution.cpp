#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
#include<utility>
#include<set>
#include<stack>
#include<list>
#include<deque>
#include<bitset>
#include<iomanip>
#include<cstring>
#include<sstream>
#include<cstdio>
#include<cstdlib>
#include<climits>
#include<cmath>
#include<cctype>


#define pb push_back
#define mp make_pair
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define ren(i,a,b) for(int i=a;i>=b;i--)
#define ff first
#define ss second
#define pll pair<long long int,long long int>
#define pii pair<int,int>
#define vll vector<long long int>  
#define vii vector<int>
#define gi(n) scanf("%d",&n)
#define gll(n) scanf("%lld",&n)
#define gstr(n) scanf("%s",n)
#define gl(n) cin >> n
#define oi(n) printf("%d",n)
#define oll(n) printf("%lld",n)
#define ostr(n) printf("%s",n)
#define ol(n) cout << n
#define os cout<<" "
#define on cout<<"\n"
#define o2(a,b) cout<<a<<" "<<b
#define all(n) n.begin(),n.end()
#define present(s,x) (s.find(x) != s.end()) 
#define cpresent(s,x) (find(all(s),x) != s.end()) 
#define tr(container, it) for(__typeof(container.begin()) it = container.begin(); it != container.end(); it++) 
using namespace std;
 
typedef unsigned long long int ull;
typedef long long int ll;
ll dp[1000005]={0};
ll rev(ll n)
{
	ll x=0;
	while(n)
	{
		x=x*10+n%10;
		n/=10;
	}
	return x;
}
int main()
{ios_base::sync_with_stdio(false);
freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout);
int t,t1=0;
gl(t);
rep(i,1,9)
dp[i]=i;
ll k=9;
rep(i,10,1000004)
{
	k=min(k+1,dp[i-1]+1);
	if(!dp[i])
	dp[i]=k;
	ll y=rev(i);
	
	if(y<i)
	{
	if((int)log10l(y)==(int)log10l(i))
	{
	 dp[i]=min(dp[i],dp[y]+1);
     //if(i==21)
	 //ol(dp[y]);
	 }
    }
    /*else if(y>i)
    {
    	if(y<=1e6+3)
		dp[y]=dp[i]+1;
	}*/
}
//ol(rev(21));on;
//o2(log10l(21),log10l(12));on;
while(t--)
{
  t1++;
  ol("Case #");ol(t1);ol(": ");	
  ll n;
  gl(n);
  ol(dp[n]);on;
}
return 0;
}
