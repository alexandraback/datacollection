#include <map>
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
typedef long long int64;
typedef unsigned long long uint64;
typedef vector < int > vi;
typedef vector < vi > vii;

vector < int64 > vet;

struct tri{
	int64 valor;
	vector <int64> vv;
	int b;
	tri ( int64 valor = 0, int b = 0 ) : valor(valor), b(b){
		REP(i,vet.size()){
			vv.pb(vet[i]);
		}
	}
};



typedef vector < tri > vtri;
typedef vector < vtri > vvtri;


int x[] = {-1,-1,-1, 0, 1, 1, 1, 0 };
int y[] = {-1, 0, 1, 1, 1, 0,-1,-1 };
int visit[10000][10000], vis = 1;

int bfs(int64 valor){
	queue < tri > fila;
	fila.push(tri(valor, 0));
	tri at = tri(0,0);
	int ans = INF;
	while( !fila.empty()){
		at = fila.front();
		fila.pop();
		if( at.vv.empty() ){ ans = min(ans,at.b); continue; }
		if( visit[at.valor][at.vv.size()] == vis ) continue;
		visit[at.valor][at.vv.size()] = vis;
		int64 sum = at.valor;
		vet.clear();
		REP(i,at.vv.size()){
			if( sum > at.vv[i] ) sum += at.vv[i];
			else vet.pb(at.vv[i]);
		}
		fila.push(tri(sum, at.b));
		fila.push(tri(sum + (sum-1), at.b+1));
		if( !vet.empty() ){ 
			vet.erase(vet.begin()+vet.size()-1);
			fila.push(tri(sum, at.b+1));
			fila.push(tri(sum + (sum-1), at.b+2));
		}
	}
	return ans;
}

int main(){
	ios::sync_with_stdio(false);
	int t, caso = 1;
	cin >> t;
	int64 a, n;
	while( t-- ){
		vet.clear();
		cin >> a >> n;
		vet.resize(n);
		REP(i,n) cin >> vet[i];
		sort(ALL(vet));
		cout << "Case #" << caso++ << ": " << bfs(a) << "\n";
		//cout << "Case #" << caso++ << ": " << "0" << "\n";
		vis++;
	}
	return 0;
}
