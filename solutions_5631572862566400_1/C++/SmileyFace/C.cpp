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
const double eps = 1e-13;

vector<pair<int,int> > gay;
int p[1009];
vector<int> bp[1009];//back parent!
int dist[1009];

int dp(int x,int p){
	int v=1;
	for(int i:bp[x]){
		if(i==p)continue;
		v=max(v,dp(i,x)+1);
	}
	return v;
}

int main(){
	RF("C-large.in");
	WF("Cout.txt");
	CASET{
		DRI(n);
		REP(i,n)bp[i].clear();
		REP(i,n){RI(p[i]);p[i]--;bp[p[i]].PB(i);}
		gay.clear();
		REP(i,n){
			REPP(j,i+1,n){
				if(p[i]==j&&p[j]==i){
					gay.PB(MP(i,j));
				}
			}
		}
		//printf("GAY SIZE: %d\n",SZ(gay));
		int ans=0;
		for(PII g:gay){
			ans+=dp(g.F,g.S)+dp(g.S,g.F);
		}
		int longcyc=0;
		REP(i,n){//cycle starter
			MS1(dist);
			dist[i]=0;
			int cn=p[i];
			int cd=1;
			while(dist[cn]==-1){
				dist[cn]=cd;
				cn=p[cn];
				cd++;
			}
			if(cn==i&&cd!=2){
				longcyc=max(longcyc,cd);
			}
		}
		printf("Case #%d: %d\n",case_n,max(ans,longcyc));
		case_n++;
	}
}
