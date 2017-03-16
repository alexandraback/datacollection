
#include <set>
#include <list>
#include <stack>
#include <cmath>
#include <queue>
#include <ctime>
#include <cfloat>
#include <vector>
#include <string>
#include <cstdio>
#include <bitset>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <iomanip>
#include <sstream>
#include <utility>
#include <iostream>
#include <algorithm>

using namespace std;


#define FOR(i, a, b) for(int i = a; i <= b; ++i)
#define RFOR(i, b, a) for(int i = b; i >= a; --i)
#define REP(i, N) for(int i = 0; i < N; ++i)
#define RREP(i, N) for(int i = N-1; i >= 0; --i)
#define FORIT(i, a) for( TI(a) i = a.begin(); i != a.end(); i++ )
#define MAXN 10000
#define INF 0x3F3F3F3F
#define LINF 0x3F3F3F3FFFFFFFFFLL
#define FILL(X, V) memset( X, V, sizeof(X) )
#define TI(X) __typeof((X).begin())
#define ALL(V) V.begin(), V.end()
#define SIZE(V) int((V).size())
#define pb push_back
#define mp make_pair

struct tri{
	int ant, novo;
	tri ( int ant = 0, int novo = 0) : ant(ant), novo(novo) { }
};


typedef vector < int > vi;
typedef vector < vi > vii;
typedef vector < tri > vtri;
typedef vector < vtri > vvtri;
typedef long long int64;
typedef unsigned long long uint64;

int x[] = {-1,-1,-1, 0, 1, 1, 1, 0 };
int y[] = {-1, 0, 1, 1, 1, 0,-1,-1 };

vector < int > vet;
vector < int > re;
int e, r, n, resp = 0;

void solve(int k, int ene, int sum){
	ene = min(e,r+ene);
	if( ene <= 0 ) return ;
	resp = max(resp,sum);
	if( k >= n ) return ; 
	int ans = 0;
	REP(i,ene+1){
		solve(k+1, ene - i,sum + vet[k]*i);
	}
	return ;
}

int main(){
	ios::sync_with_stdio(false);
	int t, caso = 1;
	cin >> t;
	
	while( t-- ){
		cin >> e >> r >> n;
		vet.clear();
		vet.resize(n);
		re.clear();
		re.resize(n);
		REP(i,n){re[i] = 0; cin >> vet[i]; }
		solve(0, e - r,0);
		cout << "Case #" << caso++ << ": " << resp << "\n";
		resp = 0;
	}
	return 0;
}
