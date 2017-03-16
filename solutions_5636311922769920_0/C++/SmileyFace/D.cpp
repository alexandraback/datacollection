#include <bits/stdc++.h>
#define SZ(X) ((int)(X).size())
#define ALL(X) (X).begin(), (X).end()
#define REP(I, N) for (int I = 0; I < (N); ++I)
#define REPP(I, A, B) for (int I = (A); I < (B); ++I)
#define RI(X) scanf("%d", &(X))
#define RII(X, Y) scanf("%d%d", &(X), &(Y))
#define RIII(X, Y, Z) scanf("%d%d%d", &(X), &(Y), &(Z))
#define DRI(X) int (X); scanf("%d", &X)
#define DRII(X, Y) int X, Y; scanf("%d%d", &X, &Y)
#define DRIII(X, Y, Z) int X, Y, Z; scanf("%d%d%d", &X, &Y, &Z)
#define RS(X) scanf("%s", (X))
#define CASET int ___T, case_n = 1; scanf("%d ", &___T); while (___T-- > 0)
#define MP make_pair
#define PB push_back
#define MS0(X) memset((X), 0, sizeof((X)))
#define MS1(X) memset((X), -1, sizeof((X)))
#define LEN(X) strlen(X)
#define VPII vector<pair<int,int> >
#define F first
#define S second
#define RF(x) freopen(x,"r",stdin)
#define WF(x) freopen(x,"w",stdout)
typedef long long LL;
using namespace std;
typedef pair<LL,LL> PLL;
typedef pair<int,int> PII;
const LL MOD = 1e9+7;
const int SIZE = 1e6+5;
const LL INF = 1LL<<58;
const double eps = 1e-10;

LL p[64];

int main(){
	RF("D-small-attempt0.in");
	WF("Dout.txt");
	CASET{
		DRIII(k,c,s);
		int v=k/c;
		if(k%c!=0)v++;
		p[0]=1;
		REPP(i,1,c){
			p[i]=p[i-1]*k;
		}
		if(s<v){
			printf("Case #%d: IMPOSSIBLE\n",case_n);
			case_n++;
		}
		else{
			printf("Case #%d:",case_n);
			REP(i,v){
				LL cv=0;
				REP(j,c){
					if(i*c+j<k)
					cv+=(i*c+j)*p[j];
				}
				printf(" %lld",cv+1);
			}
			puts("");
		}
		case_n++;
	}
}
