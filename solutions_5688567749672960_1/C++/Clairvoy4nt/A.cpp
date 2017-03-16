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

const int maxn = 1000005;
ll memo[maxn];
ll p[maxn];


ll ninv(ll n){
	ll ans = 0;
	while(n){
		int r = n%10;
		n /= 10;
		ans = 10*ans + r;
	}
	return ans;
}
ll len(ll n){
	ll ans= 0;
	while(n){
		n/=10;
		ans++;
	}
	return ans;
}


void solve(int caso){
	ll N;
	cin  >> N;
	if(N==1){
		printf("Case #%d: %lld\n",caso, N);
		return;
	}
	ll temp = N;
	ll ans = 0;
	//while(N!=0){
	//	cout << N  <<" ";
		//N = p[N];
	//}
	//cout<<endl;
	N=temp;
	//cout << N << " ";

	while(N != 1) {
		ll zeros = len(N)-2;
		zeros = ceil(zeros/2.0);
		ll div = pow(10,zeros+1);
		if(N <= 500){
			ans += memo[N];
			N = 1;
			//cout << N << " ";
			continue;
		}

		ll x = N/div;
		x = x*div+1;
		if(x<N){
			//for(int i=N-1;i>=x;i--) cout << i <<" ";
			ans += N-x;
			N = ninv(x);
			if(x!=ninv(x)){
				//cout << N <<" ";
				ans++;
			}
		}
		else if( N <= ninv(x) or N%10==0){
			N--;
			ans+=1;
			//cout << N <<" ";
			continue;
		}
		else {
			ans++;
			N = ninv(N);
			//cout << N <<" ";
		}
		//cout << N <<" "<<endl;

	}
	//cout << endl;
	//cout << memo[temp] <<endl;
	printf("Case #%d: %lld\n",caso, ans);
	//printf("Case #%d: %lld\n",caso, memo[temp]);
}

int main(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif	
	
	int T;
	cin >> T;
	REP(i,1,20) memo[i] = i, p[i]=i-1;
	REP(i,20,1000004){
		ll p1,p2;
		if(ninv(i)>=i or i%10==0) p1 =I;
		else p1 = 1 + memo[ninv(i)];
		p2 = 1 + memo[i-1];
		if(p1 < p2){
			memo[i] = p1;
			p[i] = ninv(i);
		}
		else{
			memo[i] = p2;
			p[i] = i-1;
		}
	}
	REP(i,1,T+1){
		solve(i);
	}
		
	return 0;
}






