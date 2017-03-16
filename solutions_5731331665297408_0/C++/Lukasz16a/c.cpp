#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <cmath>
#include <cassert>
#include <cstring>
#include <ext/numeric>
#include <gmpxx.h>			// -lgmpxx -lgmp
#include <sstream>
using namespace std ;
using namespace __gnu_cxx ;
typedef mpz_class BIGNUM ;
typedef long long LL ;
typedef pair<int,int> PII ;
typedef vector<int> VI ;
const int INF = 1000*1000*1000 ;
const LL INFLL = (LL)INF * (LL)INF ;
#define REP(i,n) for(i=0;i<(n);++i)
#define ALL(c) c.begin(),c.end()
#define VAR(v,i) __typeof(i) v=(i)
#define FOREACH(i,c) for(VAR(i,(c).begin());i!=(c).end();++i)
#define CLEAR(t) memset(t,0,sizeof(t))
#define PB push_back
#define MP make_pair
#define FI first
#define SE second

template<class T1, class T2> ostream & operator<<(ostream &s, pair<T1,T2> x) { s << "(" << x.FI << "," << x.SE << ")" ; return s ; }
template<class T> ostream & operator<<(ostream &s, const vector<T> &t) { FOREACH(it, t) s << *it << " " ; return s ; }
template<class T1, class T2> ostream & operator<<(ostream &s, const map<T1, T2> &t) { FOREACH(it, t) s << *it << " " ; return s ; }

const int MAXN = 60 ;

int id[MAXN] ;
bool graf[MAXN][MAXN] ;
bool used[MAXN] ;
bool vis[MAXN] ;
int n ;

bool can(stack<int> S, int next) {
	while(!S.empty() && !graf[S.top()][next]) S.pop() ;
	if(S.empty()) return false ;
	
	int i ;
	for(i=1 ; i<=n ; i++) vis[i] = used[i] ;
	vis[next] = true ;
	S.push(next) ;
	while(!S.empty()) {
		int u = S.top() ; S.pop() ;
		for(i=1 ; i<=n ; i++)
			if(!vis[i] && graf[u][i]) {
				vis[i] = true ;
				S.push(i) ;
			}
	}
	int calc=0 ;
	for(i=1 ; i<=n ; i++) if(vis[i]) calc++ ;
	return calc==n ;
}

void wrzuc(priority_queue<PII> &Q, int u) {
	for(int j=1 ; j<=n ; j++)
		if(graf[u][j] && !used[j])
			Q.push(MP(-id[j], j)) ;
}

void _main() {
	int m, i, a, b ;
	cin >> n >> m ;
	CLEAR(used) ;
	CLEAR(graf) ;
	priority_queue<PII> Q ;
	stack<int> S ;
	id[0] = INF ;
	int start=0 ;
	for(i=1 ; i<=n ; i++) {
		cin >> id[i] ;
		if(id[i] < id[start]) start=i ;
	}
	while(m--) {
		cin >> a >> b ;
		graf[a][b] = graf[b][a] = true ;
	}
	
	ostringstream ret ;
	ret << id[start] ;
	wrzuc(Q, start) ;
			
//	cout << start << " " ;
	used[start] = true ;
	S.push(start) ;
	vector<PII> old ;
	while(!Q.empty()) {
		PII tmp = Q.top() ; Q.pop() ;
		int u = tmp.SE ;
		if(used[u]) continue ;
		if(can(S,u)) {
//			cout << u << " " ;
			ret << id[u] ;
			used[u] = true ;
			while(!graf[S.top()][u]) S.pop() ;
			S.push(u) ;
			wrzuc(Q, u) ;
			
			FOREACH(it, old)
				if(!used[it->SE]) Q.push(*it) ;
			old.clear() ;
		}
		else old.PB(tmp) ;
	}
//	cout << endl ;
	cout << ret.str() << endl ;
}

int main()
{
	ios_base::sync_with_stdio(0) ;
	int C ;
	cin >> C ;
	for(int tests=1 ; tests<=C ; tests++) {
//		cerr << "Case #" << tests << endl ;
		cout << "Case #" << tests << ": " ;
		_main() ;
	}
}

