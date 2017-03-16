#include <unordered_set>
#include <unordered_map>
#include <functional>
#include <algorithm>
//#include <iostream>
#include <numeric>
#include <cassert>
#include <cstring>
#include <cstdio>
#include <vector>
#include <queue>
//#include <cmath>
#include <set>
#include <map>
using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef vector<int> VI;
typedef vector<LL> VLL;
typedef vector<VI> VVI;
typedef pair<int,int> PII;
typedef vector<PII> VPII;

#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,b,e) for(int i=(b);i<=(e);++i)
#define FORD(i,b,e) for(int i=(b);i>=(e);--i)

#define PB push_back
#define ALL(V) (V).begin(),(V).end()
#define SIZE(V) ((int)(V).size())

#define MP make_pair
#define ST first
#define ND second

#define DBG

#ifdef DBG
	#define debug(...) fprintf(stderr, __VA_ARGS__)
#else
	#define debug(...)
#endif

int __stmp;
#define scanf __stmp=scanf


const int INF = 1000000001;
const int MAX = 100000;

int n;

#define PARALLEL 1

/* UWAGA NA PAMIEC!
   Moze byc potrzebne nawet Z razy wiecej pamieci w trakcie dzialania,
   chyba ze bedzie sie ja alokowac i zwalniac w solve() wtedy moze byc
   potrzebne do <liczba rdzeni> razy wiecej.
   Kompilowac z --openmp
 */

class solver {
	public:
		// wczytujemy caly input dla jednego zestawu danych
		void input() {
			scanf("%d %d %d", &n, &m, &k);
		}
		
		// skminiamy rozwiazanie
		void solve() {
			res = n*m;
			int arr[n][m];
			int vis[n][m];
			REP(mask,1<<(n*m))
			{
				int c_res = 0;
				REP(i,n*m)
				{
					c_res += (mask>>i)&1;
					arr[i/m][i%m] = (mask>>i)&1;
				}
				memset(vis, 0, sizeof vis);
				VPII Q;
				REP(i,n)
				{
					if(!arr[i][0]) Q.PB({i, 0});
					if(!arr[i][m-1]) Q.PB({i, m-1});
				}
				REP(j,m)
				{
					if(!arr[0][j]) Q.PB({0, j});
					if(!arr[n-1][j]) Q.PB({n-1, j});
				}
				for(PII i : Q) vis[i.ST][i.ND] = 1;
				while(!Q.empty())
				{
					PII v = Q.back();
					Q.pop_back();
					FOR(i,v.ST-1,v.ST+1)
						FOR(j,v.ND-1,v.ND+1)
							if(abs(v.ST-i) + abs(v.ND-j) == 1 && 0 <= i && i < n && 0 <= j && j < m && !vis[i][j] && !arr[i][j]) {
								vis[i][j] = 1;
								Q.PB({i, j});
							}
				}
				int cnt = 0;
				REP(i,n)
					REP(j,m)
						cnt += !vis[i][j];
				if(cnt >= k)
					res = min(res, c_res);
			}
		}
		
		// wypisujemy output
		void output() {
			printf("%d\n", res);
		}
	private:
		int n, m, k;
		int res;
};

int main(int argc, char *argv[]) {
	int case_id = argc == 2 ? atoi(argv[1])-1 : -1;
	int Z;
	scanf("%d", &Z);
	vector<solver> S(Z);
	REP(z,Z) S[z].input();
	if(case_id == -1) {
		#if PARALLEL == 1
			#pragma omp parallel for schedule(dynamic)
		#endif
		REP(z,Z) S[z].solve();
	} else {
		S[case_id].solve();
	}
	REP(z,Z)
	{
		if(case_id == -1 || z == case_id) {
			printf("Case #%d: ", z+1);
			S[z].output();
		}
	}
	return 0;
}
