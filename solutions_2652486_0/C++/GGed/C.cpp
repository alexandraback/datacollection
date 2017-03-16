#include <cstdio>
#include <cstring>
#include <algorithm>
#define FOR(i,s,e) for (int i=(s); i<(e); i++)
#define FOE(i,s,e) for (int i=(s); i<=(e); i++)
#define FOD(i,s,e) for (int i=(s)-1; i>=(e); i--)
#define CLR(a,x) memset(a, x, sizeof(a))
#define EXP(i,l) for (int i=(l); i; i=qn[i])
#define LLD long long
using namespace std;

int tc, n, m, K;
int a[30], f[130];
int freq[6][6][6][130];
int x, mn, dist;
char sol[10];

int main(){
	scanf("%*d");
	scanf("%d%d%d%d", &tc, &n, &m, &K);
	
	
	FOE(i,2,5) FOE(j,2,5) FOE(k,2,5){
		a[0] = i;
		a[1] = j;
		a[2] = k;
		FOR(l,0,8){
			int p = 1;
			FOR(r,0,3) if (l & (1<<r)) p *= a[r];
			freq[i][j][k][p]++;
		}
	}
	
	printf("Case #1:\n");
	while (tc--){
		CLR(f, 0);
		FOR(i,0,K) scanf("%d", &x), ++f[x];
		mn = (1<<30);
		FOE(i,2,5) FOE(j,2,5) FOE(k,2,5){
			dist = 0;
			FOR(l,0,130) dist += (freq[i][j][k][l] - f[l]) * (freq[i][j][k][l] - f[l]);
			if (dist < mn){
				mn = dist;
				sprintf(sol, "%d%d%d", i, j, k);
			}
		}
		printf("%s\n", sol);
	}

	return 0;
}
