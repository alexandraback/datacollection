#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <vector>
using namespace std;
#define MAXN 1010
typedef pair<int,int> ii;
typedef vector< ii > vii;

int N;
int pai[MAXN];
int dist[MAXN], mark[MAXN], distxp[MAXN];
bool amigo[MAXN][MAXN];
vii par;


int main()
{
	int T;
	int tc = 1;
	int val = 0, maximo = 0;
	scanf("%d", &T);
	while ( T-- ) {
		scanf("%d", &N);
		maximo = 0;
		par.clear();
		for ( int i = 1; i <= N; i++ ) {
			scanf("%d", &pai[i]);
			mark[i] = false;
			distxp[i] = 0;
		}
		for ( int i = 1; i <= N; i++ )
			for ( int j = i+1; j <= N; j++ )
				amigo[i][j] = false;
		for ( int i = 1; i <= N; i++ )  {
			int x = i;
			for ( int i = 1; i <= N; i++ ) {
				dist[i] = -1;
			}
			dist[x] = 0;
			x = pai[x]; int atual = 0;
			while ( dist[x] == -1 ) {
				dist[x] = ++atual;
				x = pai[x];
			}
			maximo = max(atual-dist[x]+1,maximo);
			if ( atual - dist[x] == 1 ) {
				int a = max(x,pai[x]), b = min(x,pai[x]);
				amigo[b][a] = true;
				distxp[x] = max(distxp[x],dist[x]); 
			}
		}
		for ( int i = 1; i <= N; i++ ) {
			for ( int j = i+1; j <= N; j++ ) {
				if ( amigo[i][j] == true ) {
					maximo = max(distxp[i] + distxp[j] + 2, maximo);
				}
			}
		}
		printf("Case #%d: %d\n", tc++, maximo);
	}
	return 0;
}