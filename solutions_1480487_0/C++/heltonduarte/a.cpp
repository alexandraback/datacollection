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

// Constantes
const double PI = 2*asin(1.0);
const int INF = 1000000000;	// 9 zeros
const double EPS = 1e-10;

// Matematica basica
inline int cmp(double x, double y = 0, double tol = EPS) {
	return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}
inline ll gcd(ll n1, ll n2) {return n2==0? abs(n1) : gcd(n2,n1%n2);}
inline ll lcm(ll n1, ll n2) {return n1==0||n2==0? 0 : abs(n1*(n2/gcd(n1,n2)));}

vi p;

void solve() {
	int sum = 0;
	FORR(i, sz(p)) sum += p[i];

	FORR(i, sz(p)) {
		int rem = sum;
		vi pa = p;

		FORR(j, sz(pa)) {
			if(j == i) continue;
			if(pa[j] < p[i]) {
				rem -= (p[i]-pa[j]);
				pa[j] = p[i];
			}
		}

		if(rem <= 0) printf(" %.6lf", 0.0);
		else {
			int maior = pa[i];

			while(maior != INF) {
				int aux = pa[i], aux2 = rem, cnt = 0;
				FORR(j, sz(pa)) {
					if(pa[j] == aux) {
						rem -= (maior-pa[j]);
						pa[j] = maior;
						cnt ++;
					}
				}

				if(rem < 0) {
					printf(" %.6lf", (100.0*(double(aux-p[i])+double(aux2)/double(cnt)))/double(sum));
					break;
				}
		
				maior = INF;
				FORR(j, sz(pa)) if(pa[j] > pa[i] && pa[j] < maior) maior = pa[j];
			}

			if(maior == INF) {
				printf(" %.6lf", (100.0*(double(pa[i]-p[i])+double(rem)/double(sz(p))))/double(sum));
			}
		}
	}
	printf("\n");
}

int main() {
	int tests = 0;
	scanf("%d", &tests);

	FORR(caseNum, tests) {
		int s;
		scanf("%d", &s);
		p.resize(s);

		FORR(i, s) scanf("%d", &p[i]);

		printf("Case #%d:", caseNum+1);
		solve();
	}


	return 0;
}
