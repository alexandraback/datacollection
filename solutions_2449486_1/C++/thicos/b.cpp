#include <cstdio>
#include <cstring>
#define REP(i,n) for(int i = 0; i<(n); i++)

int lawn[200][200];
int maxl[200];
int maxc[200];
int n, m;

bool solve(){
	REP(i, n){
		REP(j, m){
			if (lawn[i][j] != maxl[i] && lawn[i][j] != maxc[j]) return false;
		}
	}
	return true;
}

int main(){
	int T;
	scanf("%d",&T);
	REP(t,T){
		memset(maxl, 0, sizeof(maxl));
		memset(maxc, 0, sizeof(maxc));
		scanf("%d %d",&n, &m);
		REP(i,n){
			REP(j,m){
				scanf("%d", &lawn[i][j]);
				if (lawn[i][j] > maxl[i]) maxl[i] = lawn[i][j];
				if (lawn[i][j] > maxc[j]) maxc[j] = lawn[i][j];				
			}
		}
		printf("Case #%d: %s\n",t+1,solve()?"YES":"NO");
	}
	return 0;
}