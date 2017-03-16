//Arek Wrobel - skater
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;
typedef long long LL;
typedef vector<int> VI;
typedef pair<int, int> PII;
#define REP(I, N) for(int I=0; I<(N); ++I)
#define FOR(I, M, N) for(int I=(M); I<=(N); ++I)
#define FORD(I, M, N) for(int I=(M); I>=(N); --I)
#define FOREACH(IT, CON) for(__typeof(CON.begin()) IT=CON.begin(); IT!=CON.end(); ++IT)
#define ST first
#define ND second
#define MP make_pair
#define PB push_back
const int INF=1000000000;
const LL INFLL=1000000000000000000LL;

int A, n;
int t[128];

int wy;

int main()
{
	int T;
	scanf("%d", &T);
	FOR(lpt, 1, T){
		//wej
		scanf("%d%d", &A, &n);
		REP(i, n)
			scanf("%d", &t[i]);
		sort(t, t+n);
		//prog
		int ile=0;
		wy=n;
		if (A>1)
		REP(I, n){
			while(A<=t[I]){
				A+=A-1;
				++ile;
			}
			A+=t[I];
			wy=min(wy, ile+n-I-1);
		}
		//wyj
		printf("Case #%d: %d\n", lpt, wy);
	}
	return 0;
}

