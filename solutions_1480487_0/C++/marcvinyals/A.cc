#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

#define REP(i,n) for(int i=0;i<(n);++i)
#define REPR(i,n) for(int i=(n-1);i>=0;--i)
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define FORE(i,a,b) for(int i=(a);i<=(b);++i)
#define FORR(i,z,n) for (int (i)=(n-1);(i)>=(z);--(i))
#define FOREACH(it,c) \
  for(__typeof((c).begin()) it=(c).begin();it!=(c).end();++it)
#define MP make_pair
#define PB push_back
#define ALL(x) (x).begin(),(x).end()
#define UNIQUE(x) remove(unique((x).begin(),(x).end()),(x).end())
#define CLEAR(x,v) memset((x),(v),sizeof((x)))
#define FORS(i,x) for(int i=0;i<(int)(x).size();i++)

typedef long long ll;
typedef vector<ll> VI;
const double EPS=1e-10;

int main() {
	int T;
	cin >> T;
	FORE(t,1,T) {
		int n;
		cin >> n;
		VI v(n);
		double x=0;
		REP(i,n) {
			cin >> v[i];
			x+=v[i];
		}
		printf("Case #%d:",t);
		REP(i,n) {
			double a=0;
			double b=1;
			while(b-a>EPS) {
				double m=(a+b)/2;
				double all=1-m;
				double me=v[i]/x+m;
				REP(j,n) {
					if (j==i) continue;
					all-=max(0.,me-v[j]/x);
				}
				if (all<0) b=m;
				else a=m;
			}
			printf(" %.6f",100*(a+b)/2);
		}
		printf("\n");
	}
}

