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

char tab[] = "yhesocvxduiglbkrztnwjpfmaq";

int main(int argc, char *argv[]) {
	int Z;
	scanf("%d\n", &Z);
	FOR(z,1,Z)
	{
		printf("Case #%d: ", z);
		char c;
		do
		{
			c = getchar();
			if('a' <= c && c <= 'z')
				putchar(tab[c-'a']);
			else
				putchar(c);
		}
		while(c != '\n');
	}
	return 0;
}

