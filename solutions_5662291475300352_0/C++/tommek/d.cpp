#include "bits/stdc++.h"
using namespace std;

typedef long long LL;
typedef long double LD;
typedef vector<int> VI;
typedef pair<int,int> PII;
#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define FORD(i,a,b) for(int i=(a);i>=(b);--i)
#define FOREACH(it,v) for(decltype((v).begin())it=(v).begin();it!=(v).end();++it)
#define ST first
#define ND second
#define MP make_pair
#define PB push_back
#define ALL(v) (v).begin(),(v).end()
#define SIZE(x) ((int)(x).size())
#define DBG(x) cerr<<">> "<<#x<<" = "<<x<<endl;
const int MX = 1e6 + 5;
const int INF = 1e9 + 5;

int ccc, n;
LD d[MX], h[MX], m[MX];
pair<LD,LD> a, b;

void outRes(int x) {
	printf("Case #%d: %d\n", ccc, x);
}

int main(int argc, char* argv[])
{
	int cases; scanf("%d", &cases); for(ccc = 1; ccc <= cases; ++ ccc)
	{
		scanf("%d", &n);
		REP(i,n) 
			scanf("%Lf%Lf%Lf",&d[i], &h[i], &m[i]);
		
		if(n == 1 && h[0] == 1) {
			outRes(0); continue;
		}

		if(n == 1) {
			a = MP(d[0], m[0]);
			b = MP(d[0], m[0]+1.0);
		}
		else {
			a = MP(d[0], m[0]);
			b = MP(d[1], m[1]);
		}

		if(a.ST > b.ST) swap(a,b);
//		
//		DBG(a.ST);
//	//	DBG(a.ND);
//	/	DBG(b.ST);
//		DBG(b.ND);

		LD adwarazy = (1 - a.ST / 360.0) * a.ND + a.ND;
		LD bdwarazy = (1 - b.ST / 360.0) * b.ND + b.ND;

//		DBG(adwarazy);
//		DBG(bdwarazy);
	
		LD araz = (1 - a.ST / 360.0) * a.ND;
		LD braz = (1 - b.ST / 360.0) * b.ND;

//		DBG(araz);
//		DBG(braz);

		if(bdwarazy <= araz || adwarazy <= braz) {
			outRes(1); continue;
		}

//		if(araz <= braz) {
//			outRes(1); continue;
//		}

		outRes(0);
	}

	return 0;
}
