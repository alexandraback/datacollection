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
typedef pair<ll, ll> ii;
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

string bfs (ll x, ll y){
	map< ii, int > mapi;
	queue< pair <ii, string> > fila;
	ii start (0,0);
	pair <ii, string> pis (start, "");
	fila.push(pis);
	while (!fila.empty()){
		pis = fila.front();
		fila.pop();
		//if (abs(pis.first.first)>1000||abs(pis.first.second)>1000) continue;
		if (pis.first.first==x&&pis.first.second==y) return pis.second;
		//cout << pis.first.first << " " << pis.first.second << endl;
		//North
		start = pis.first;
		start.second += sz(pis.second)+1;
		if (!mapi[start]&&y) {
			mapi[start] = 1;
			pair<ii, string> nova (start, pis.second+'N');
			fila.push(nova);
		}
		
		//South
		start = pis.first;
		start.second -= sz(pis.second)+1;
		if (!mapi[start]&&y) {
			mapi[start] = 1;
			pair<ii, string> nova (start, pis.second+'S');
			fila.push(nova);
		}
		
		//East
		start = pis.first;
		start.first += sz(pis.second)+1;
		if (!mapi[start]&&x) {
			mapi[start] = 1;
			pair<ii, string> nova (start, pis.second+'E');
			fila.push(nova);
		}
		
		//West
		start = pis.first;
		start.first -= sz(pis.second)+1;
		if (!mapi[start]&&x) {
			mapi[start] = 1;
			pair<ii, string> nova (start, pis.second+'W');
			fila.push(nova);
		}
	}
	return "";
} 

int main() {
	int T;
	cin>>T;
	FORR (k, T){
		cout << "Case #" << (k+1) << ": ";
		ll x, y;
		cin >> x >> y;
		cout << bfs (x, y) << endl;
	}
}
