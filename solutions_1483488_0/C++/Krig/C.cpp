#include<algorithm>
#include<cstring>
#include<cstdio>
#include<vector>
#include<queue>
#include<set>
#include<map>
using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef vector<int> VI;
typedef vector<LL> VLL;
typedef vector<VI> VVI;
typedef pair<int,int> PII;
typedef vector<PII> VPII;

#define FOR(x,y,z) for(int x=y;x<=z;++x)
#define FORD(x,y,z) for(int x=y;x>=z;--x)
#define FOReach(x,Z) for(__typeof((Z).begin()) x=(Z).begin();x!=(Z).end();++x)
#define REP(x,y) for(int x=0;x<y;++x)

#define PB push_back
#define ALL(X) (X).begin(),(X).end()
#define SZ(X) ((int)(X).size())
#define CLR(X,x) memset(X, x, sizeof(X))

#define MP make_pair
#define ST first
#define ND second

#define DBG

#ifdef DBG
#define debug printf
#else
#define debug(fmt, ...)
#endif


const int MAX = 100000;
const int INF = 1000000001;

int len(int x) {
	if(!x)
		return 1;
	int l = 0;
	while(x)
		++l,
		x /= 10;
	return l;
}

int pow10[10];

int main(int argc, char *argv[]) {
	pow10[0] = 1;
	FOR(i,1,9)
		pow10[i] = pow10[i-1] * 10;
	int Z;
	scanf("%d", &Z);
	FOR(z,1,Z)
	{
		printf("Case #%d: ", z);
		int a, b;
		scanf("%d %d", &a, &b);
		int res = 0;
		FOR(i,a,b)
		{
			int l = len(i);
			int j = i;
			do
			{
				j += pow10[l] * (j % 10);
				j /= 10;
				if(a <= j && j <= b && i < j && len(j) == l)
					++res;
			}
			while(i != j);
		}
		printf("%d\n", res);
	}
	return 0;
}

