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

const int MAXN = 21;
int n;
vi s;

vii res;

bool compare(ii a, ii b) {
	return a.second < b.second;
}

int main() {
	int tests = 0;
	scanf("%d", &tests);

	FORR(caseNum, tests) {
		scanf("%d", &n);
		s.resize(n);
		FORR(i, n) scanf("%d", &s[i]);
		res.resize(1<<n);

		FORR(i, (1<<n)) {
			int bit = 0, r = 0, aux = i;
			while(bit < n && aux > 0) {
				if(aux % 2) r += s[bit];
				aux /= 2;
				bit ++;
			}

			res[i] = make_pair(i, r);
		}

		printf("Case #%d:\n", caseNum+1);


		sort( all(res), compare );

		bool can = false;
		FORR(i, (1<<n)-1) {
			if(can) break;
			int j = i+1;
			if(res[i].second == res[j].second) {
				can = true;
				bool al = false;
				int aux = res[i].first, bit = 0;
				while(aux > 0) {
					if(aux % 2) {
						if(al) printf(" ");
						al = true;
						printf("%d", s[bit]);
					}
					aux /= 2;
					bit++;
				}
				printf("\n");

				al = false;
				aux = res[j].first;
				bit = 0;
				while(aux > 0) {
					if(aux % 2) {
						if(al) printf(" ");
						al = true;
						printf("%d", s[bit]);
					}
					aux /= 2;
					bit++;
				}
				printf("\n");
			}
		}

		if(!can) printf("Impossible\n");
	}

	return 0;
}
