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

__int128_t p[11][32];
vector<int> primes;
int isp[1000009];
int counter[11];

int main(){
	WF("Cout.txt");
	MS1(isp);
	isp[0]=isp[1]=0;
	REPP(i,2,1000000){
		if(isp[i])primes.PB(i);
		for(int j=2*i;j<1000000;j+=i)isp[j]=0;
	}
	REPP(i,1,11){
		p[i][0]=1;
		REPP(j,1,32){
			p[i][j]=(p[i][j-1]*i);
			//printf("%lld ",(LL)p[i][j]);
		}
		//puts("");
	}
	CASET{
		printf("Case #%d:\n",case_n);
		DRII(n,j);
		LL bmax=1LL<<(n);
		int cj=0;
		for(LL bm=(1LL<<(n-1))+1LL;cj<j&&bm<bmax;bm+=2){
			MS1(counter);
			REPP(b,2,11){
				__int128_t cv=0;
				REP(i,n){
					if(bm&(1LL<<i)){
						cv+=p[b][i];
					}
				}
				//printf("%lld\n",(LL)cv);
				for(int i:primes){
					if(cv!=i&&cv%i==0){
						counter[b]=i;break;
					}
				}
				if(counter[b]==-1)break;
			}
			if(counter[10]!=-1){
				for(int i=n-1;i>=0;i--){
					printf("%d",(bm&(1LL<<i))>0);
				}
				REPP(b,2,11)printf(" %d",counter[b]);
				puts("");
				cj++;
			}
		}
		case_n++;
	}
}
