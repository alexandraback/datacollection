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

int pd[2][10000];

int main() {
	int T;
	cin>>T;
	FORR (k, T){
		cout << "Case #" << (k+1) << ": ";
		ll X, N, Y;
		cin >> N >> X >> Y;
		X = abs (X);
		ll v1 = 1ll, v2 = 1ll, k = 0ll;
		while (v1<=N){
			k++;
			v2 += 4;
			v1 += v2;
		}
		//cout << "Teste-> " << v1 << " " << k << endl;
		v1 -= v2;
		k--;
		ll rest = N-v1, T = v2/2;
		if (2*k>=X+Y){
			//IMPRIMIR 1.0
			cout << "1.0" << endl;
		} else if (2*(k+1)<X+Y){
			//IMPRIMIR 0.0
			cout << "0.0" << endl;
		} else {
			//ll tot = min (T, rest) - max (rest - T, 0ll) + 1;
			//ll num = max (max (rest - T, 0ll) - Y + 1, 0ll);
			//cout << tot << " " << num << endl;
			//long double result = ((long double) num) / ((long double) tot);
			FORR (i, rest+1){
				pd[i&1][0] = pd[i&1][i] = 1;
				FOR (j, 1, i){
					pd[i&1][j] = pd[(i-1)&1][j-1] + pd[(i-1)&1][j];
				}
			}
			
			ll num = 0, tot = 0;
			FOR (i, max(rest-T, 0ll), T+1)
				tot += pd[rest&1][i];
			FOR (i, max(rest-T, Y+1), T+1){
				num += pd[rest&1][i];
			}
			//cout << rest << endl;
			//cout << max(rest-T, 0ll) << " " << pd[rest&1][1] << endl;
			//cout << rest << " " << T << " "<< num << "  "<< tot << endl;
			
			long double result = tot==0 ? 0 : ((long double) num) / ((long double) tot);
			
			//cout << result << endl;
			printf ("%Lf\n", result);
		}
	}
}
