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

int n, x, y;
double wy;

void fork(const int ile, const int k, const double p){
	if (ile==0){
		if (k>=y)
			wy+=p;
		return;
	}
	fork(ile-1, k+1, p/2.0);
	fork(ile-1, k, p/2.0);
}

int main()
{
	int T;
	scanf("%d", &T);
	FOR(lpt, 1, T){
		//wej
		scanf("%d%d%d", &n, &x, &y);
		//prog
		int h=-1;
		for(int i=1; i<=n; i+=4){
			n-=i;
			++h;
		}
//		printf("%d %d\n", h, n);
		if (abs(x)+y<=2*h)
			wy=1.0;
		else {
			h=2*h+2;
			++y;	// - liczba klockow potrzebna po "mojej" stronie
			if (y>h)
				wy=0;
			else if (n>=h+y)
				wy=1.0;
			else {	// teraz moge olac przesypywanie sie diamentow na druga strone - wynik zalezy tylko od n i y
				wy=0.0;
				fork(n, 0, 1.0);
			}
		}
		//wyj
		printf("Case #%d: %lf\n", lpt, wy);
	}
	return 0;
}

