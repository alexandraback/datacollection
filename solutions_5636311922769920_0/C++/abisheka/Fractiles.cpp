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
#define rep(i,a,b) for(long long i=a;i<=b;i++)
#define ren(i,a,b) for(long long i=a;i>=b;i--)
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

ll p(ll a,ll b)
{
	ll r=1;
	while(b)
	{
		if(b%2)
		r*=a;
		a*=a;
		b/=2;
	}
	return r;
}

ll logg(ll a,ll b)
{
	ll kk=a;
	if(b==1)
	return a;
	if(a==1)
	return 1;
	ll r=0;
	while(a>1)
	{
		r++;
		a/=b;
	}
	if(p(b,r)<kk)
	r++;
	return r;
}

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
	ll k,c,s,lim;
	cin>>k>>c>>s;
	lim=k/c+(k%c!=0);
	if(s<lim)
	{
		ol("IMPOSSIBLE\n");
	}
	else
	{
		vll ans;
		ll idx=1;
		rep(i,1,lim)
		{
			ll lo=1,hi=p(k,c);
			rep(i,1,c-1)
			{
				lo=(idx-1)*p(k,c-i)+lo;
				hi=lo+p(k,c-i)-1;
				if(idx<k)
				idx++;
			}
			ans.pb(lo+idx-1);
			if(idx<k)
			idx++;
		}
		tr(ans,it)
		{
			ol(*it);os;
		}
		on;
	}	
}
return 0;
}
