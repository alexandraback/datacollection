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
typedef vector<vector<ll> > mat;

int main()
{ios_base::sync_with_stdio(false);
freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout);
int t,t1=0;
gl(t);
while(t--)
{
	t1++;
	ol("Case #");ol(t1);ol(": ");	
	int n;
	cin>>n;
	string a[1005],b[1005];
	rep(i,0,n-1)cin>>a[i]>>b[i];
	int dp[1<<17]={0};
	
	rep(msk,0,(1<<n)-1)
	{
		rep(i,0,n-1)
		{
			if((msk&(1<<i))==0)
			{
				int f1=0,f2=0,kk=0;
				rep(j,0,n-1)
				{
					if(msk&(1<<j))
					{
						if(a[i]==a[j])
						f1=1;
						if(b[i]==b[j])
						f2=1;
					}
				}
				if(f1==1&&f2==1)kk=1;
				dp[msk|(1<<i)]=max(dp[msk|(1<<i)],dp[msk]+kk);
			}
		}
	}
	ol(dp[(1<<n)-1]);on;
	
}
return 0;
}
