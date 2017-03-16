#include <cstring>
#include <map>
#include <numeric>
#include <sstream>
#include <cmath>
#include <stack>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <iostream>
#include <set>
#include <queue>
#include <string>
#include <cctype>

using namespace std;

#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define pb(x) push_back((x))
#define REP(i,x,y) for(int i = x; i < int(y); i++)
#define FOR(it,A) for(typeof (A.begin()) it = A.begin(); it!= A.end(); it++)
#define CUA(x) (x) * (x)
#define mp(x,y) make_pair((x),(y))
#define clr(x, y) memset(x, y, sizeof x)
#define fst first
#define snd second
#define I (1LL << 40)
#define sz size()
#define oo (1<<30)
#define EPS (1e-9)

#define forn(i,n) for(int i=0;i<(int)(n);i++)
#define si(c) ((int)(c).size())
#define forsn(i,s,n) for(int i = (int)(s); i<((int)n); i++)
#define dforsn(i,s,n) for(int i = (int)(n)-1; i>=((int)s); i--)
#define decl(v, c) typeof(c) v = c
#define forall(i, c) for(decl(i, c.begin()); i!=c.end(); ++i)
#define dforall(i, c) for(decl(i, c.rbegin()); i!=c.rend(); ++i)
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()

typedef pair<int, int> pii;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef vector<pii> vii;
typedef vector<string> vs;
typedef vector<int> vi;

ll memo[1000005];



ll ninv(ll n){
	ll ans = 0;
	while(n){
		int r = n%10;
		n /= 10;
		ans = 10*ans + r;
	}
	return ans;
}

ll dp(int n){
	ll &ret = memo[n];
	//cout << n << endl;
	if(ret != -1) return ret;
	if(n == 1) return ret = 1;
	ll c1,c2;
	c1 = 1 + dp(n-1);
	if(ninv(n) >= n or n%10==0) c2 = I;
	else c2 = 1 + dp(ninv(n));
	//cout<< "return: "<<min(c1,c2)<<endl;
	return ret = min(c1, c2);
}

void solve(int caso){
	int N;
	cin  >> N;
	ll ans = 1;
	//cout << memo[N]<<endl;
	/*
	while(N != 1) {
		if(N <= 20){
			ans += N-1;
			N = 1;
			//cout << ans << " " << N << endl;
			continue;
		}
		if ( N %10==0 or N<=ninv(N)){
			N--;
			ans++;
			//cout << ans << " " << N << endl;
			continue;
		}
		if( N%10==1) {
			N = ninv(N);
		}
		else {
			N--;
		}
		ans ++;
		//cout << ans << " " << N << endl;
	}*/

	printf("Case #%d: %lld\n",caso, memo[N]);
}

int main(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif	
	
	int T;
	cin >> T;
	REP(i,0,20) memo[i] = i;
	REP(i,20,1000004){
		ll p1,p2;
		if(ninv(i)>=i or i%10==0) p1 =I;
		else p1 = 1 + memo[ninv(i)];
		p2 = 1 + memo[i-1];
		memo[i] = min(p1,p2);
	}
	REP(i,1,T+1){
		solve(i);
	}
		
	return 0;
}






