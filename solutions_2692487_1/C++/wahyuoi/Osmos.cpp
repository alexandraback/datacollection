//
// Gede Wahyu Adi Pramana

#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <stack>
#include <set>
#include <cmath>
using namespace std;
#define ll long long
#define INF 1000000000
#define debug puts("DEBUUGG")
#define vi vector<ll>
#define pii pair<ll,ll>
#define vii vector<pii>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define rep(a,b,c) for(a=b;a<c;a++)
#define repe(a,b,c) for(a=b;a<=c;a++)
#define repd(a,b,c) for(a=b-1;a>=c;a--)
#define ALL(a) a.begin(),a.end()
ll n;
struct job {
	ll s;
};
class compjob
{
	public:
       bool operator()( job j11,job j22)
       {
			ll j1,j2;
			j2 = j11.s; j1 = j22.s;
			if (j1>=n && j2>=n){
				return j1<j2;
			}
			if (j1>=n) return false;
			if (j2>=n) return true;
			return j1>j2;
       }
};
void solve(ll tc){
	ll m,n,t;
	scanf("%lld %lld",&n,&m);
	priority_queue<job,vector<job>,compjob> pq;
	for (ll i=0;i<m;++i){
		scanf("%lld",&t);
		pq.push((job){t});
	}
	ll ret=0;
	ll temp=INF;
	while(!pq.empty()){
		ll x = pq.top().s; pq.pop();
		
		if (n>x) n+=x;
		else {
			if (n+n-1>x){
				n+=n-1+x;
			} else {
				temp = min(temp,ret+pq.size()+1);
				n+=n-1;
				pq.push((job){x});
				if (n+n-1<=n){
					ret=INF;
					while(!pq.empty()) pq.pop();
				}
			}
			++ret;
		}
	}
	printf("Case #%lld: %lld\n",tc,min(temp,ret));
}
int main(){
		ll tc;
	scanf("%lld",&tc);
	for (ll tcc=1;tcc<=tc;++tcc){
		solve(tcc);
	}

}