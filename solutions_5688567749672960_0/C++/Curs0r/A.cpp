#include <bits/stdc++.h>
#include <ext/hash_map>
#include <ext/hash_set>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/priority_queue.hpp>
using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;
#define XINF INT_MAX
#define INF 0x3F3F3F3F
#define MP(X,Y) make_pair(X,Y)
#define PB(X) push_back(X)
#define REP(X,N) for(int X=0;X<N;X++)
#define REP2(X,L,R) for(int X=L;X<=R;X++)
#define DEP(X,R,L) for(int X=R;X>=L;X--)
#define CLR(A,X) memset(A,X,sizeof(A))
#define IT iterator
#define RIT reverse_iterator
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> PII;
typedef vector<PII> VII;
typedef vector<int> VI;
typedef tree<int, null_type, greater<int>, rb_tree_tag, tree_order_statistics_node_update > rb_tree_set;
typedef tree<int, int, greater<int>, rb_tree_tag, tree_order_statistics_node_update > rb_tree;
#define PQ std::priority_queue
#define HEAP __gnu_pbds::priority_queue
#define X first
#define Y second
#define lson(X) ((X)<<1)
#define rson(X) ((X)<<1|1)


ll rev(ll n) {
	ll r=0;
	while(n) {
		r=r*10+n%10;
		n=n/10;
	}
	return r;
}


map<ll, ll> mp;
ll solve(ll n) {
	//cout<<n<<endl;
	if(n==0) return LLONG_MAX/2;
	if(n==1) return 1;
	//if(n>1e15) return LLONG_MAX/2;
	if(mp.count(n)) return mp[n];
	mp[n]=LLONG_MAX/2;
	ll nx=n, c=0;
	nx--;
	while(nx%10!=1) nx--, c++;
	ll ans = solve(nx) + c;
	if(n%10==1 && rev(n) < n) {
		ans = min(ans, solve(rev(n)));
	}
	return mp[n] = ans+1;
}


int main()
{  
	ios::sync_with_stdio(false);
#ifdef LOCAL
	freopen("A-small-attempt2.in.txt","r",stdin);
	freopen("A-small-attempt2.out","w",stdout);
#endif
	ll ten[20];
	ten[0]=1;
	REP(i,19) ten[i+1]=ten[i]*10;
	int t,cs=1;
	cin>>t;
	while(t--){
		ll n;
		cin>>n;
		//mp.clear();
		//ll ans = solve(n);
		
		ll c=1;
		
		if(n%10==0) {
			n--;c++;
		}
		while(n!=-1) {
			//cout<<n<<endl;
			int l = 0;
			ll tn = n;
			int x=0;
			while(tn) {
				x++;
				tn/=10;
			}
			c+=n%ten[(x+1)/2]-1;
			n-=n%ten[(x+1)/2]-1;
			if(rev(n) < n) {
				n=rev(n);
				c++;
			}
			c+=n%ten[(x+1)/2];
			n-=n%ten[(x+1)/2];
			//if(n!=1) {
				n--;c++;
			//}
		}
		c-=2;
		cout<<"Case #"<<cs++<<": "<<c<<endl;//<<' '<<ans<<endl;
	}
	return 0;
}


