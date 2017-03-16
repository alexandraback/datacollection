#include<cstdio>
#include<cstring>
#include<cctype>
#include<cmath>
#include<cstdlib>
#include<ctime>	// srand( time(NULL) )
#include<iostream>
#include<iomanip>
#include<sstream>
#include<vector>
#include<string>
#include<queue>
#include<stack>
#include<utility>
#include<algorithm>
#include<map>
#include<set>
#include<bitset>
#include<climits>

using namespace std;

// Typedefs
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<double> vd;
typedef vector<string> vs;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef pair< int, pair<int, int> > iii;
typedef vector<iii> viii;
typedef vector< vector<int> > vvi;
typedef vector< vector<ii> > vvii;
typedef vector< vector<iii> > vviii;

// Macros
#define FOR(i, a, b) for(int i = a; i < b; ++i)
#define FORR(i, a) for(int i = 0; i < a; ++i)
#define FORE(i, a, b) for(int i = a; i >= b; --i)
#define all(v) v.begin(), v.end()
#define sz(A) int((A).size())
#define pb push_back
#define present(c,x) ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define LSOne(S) (S & (-S)) // bit menos significativo
#define first(x) x.first	// lidam com triplas
#define second(x) x.second.first
#define third(x) x.second.second
#define CLR(x, a) memset(x, a, sizeof(x))

// Constantes
const double PI = 2*asin(1.0);
const int INF = 1000000000;	// 9 zeros
const double EPS = 1e-10;

// Matematica basica
inline int cmp(double x, double y = 0, double tol = EPS) {
	return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1; }
inline ll gcd(ll n1, ll n2) {return n2==0? abs(n1) : gcd(n2,n1%n2);}	// MUDAR PARA O PKU!
inline ll lcm(ll n1, ll n2) {return n1==0||n2==0? 0 : abs(n1*(n2/gcd(n1,n2)));}	// MUDAR PARA O PKU!

bool can(ll n, ll r, ll t) {
	return (( ( ( 2LL*r + 1LL ) + (2LL*r + 4LL*n - 3LL) ) * n ) / 2LL <= t);
}

ll solve(ll r, ll t) {
	if(t / (r * r) <= 10000) {
		ll acum = 0LL;
		FOR(i, 1, 10000) {
			ll aux = 2LL*r + 4LL*i - 3LL;
			if(acum + aux <= t) acum += aux;
			else return i-1;
		}
		return 10000;
	}

	ll ini = 0, fim = 1000000001;
	while(fim - ini > 1) {
		ll mid = (ini + fim) / 2;
		if(can(mid, r, t)) ini = mid;
		else fim = mid;
	}
	return ini;
}

int main() {
	int tests = 0;
	scanf("%d ", &tests);
	
	FORR(caseNum, tests) {
		printf("Case #%d: ", caseNum+1);
		ll r = 0, t = 0;
		scanf("%lld %lld ", &r, &t);
		
		printf("%lld\n", solve(r, t));
	}

	return 0;
}
