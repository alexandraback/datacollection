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

#define PARALLEL 0

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
			scanf("%d %d %d", &r, &c, &w);
		}
		
		// skminiamy rozwiazanie
		void solve() {
			res = INF;
			VI v;
			REP(mask,1<<c)
			{
				if(!mask) continue;
				int t = r * __builtin_popcount(mask);
				v.clear();
				REP(i,c)
					if(mask & (1<<i))
						v.PB(i);
				bool ok = v[0] < w && v.back()+w >= c;
				REP(i,SIZE(v))
					if(i && v[i] - v[i-1] > w)
						ok = false;
				if(!ok) continue;
				int d = INF;
				REP(i,SIZE(v))
				{
					int prv = i ? v[i-1] : -1;
					int nxt = i+1 < SIZE(v) ? v[i+1] : c;
					if(nxt - prv - 1 < w) continue;
//					printf("%d %d\n", mask, v[i]);
					
					int p = max(0, w - (nxt - v[i])) + max(0, w - (v[i] - prv));
					assert(p < w);
					d = min(d, p + 2*(w-p-1));
				}
				if(d != -1)
					res = min(res, t+d);
//				printf("d: %d\n", t+d);
			}
		}
		
		// wypisujemy output
		void output() {
			printf("%d\n", res);
		}
	private:
		int r, c, w;
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
