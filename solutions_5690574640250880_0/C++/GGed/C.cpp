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

int n, m, qm, qs;
int v[105][105];

void print(){
	FOR(i,0,n){
		FOR(j,0,m){
			if (i + j == 0) printf("c");
			else if (v[i][j]) printf(".");
			else printf("*");
		}
		puts("");
	}
}

void solve(int tc){
	printf("Case #%d:\n", tc);
	scanf("%d%d%d", &n, &m, &qm);
	qs = n * m - qm;
	CLR(v, 0);
	if (qs == 1){ v[0][0] = 1; print();}
	else if (n >= 3 && m >= 3){
		if (qs & 1){
			if (qs < 9){ puts("Impossible"); return; }
			FOR(i,0,3) FOR(j,0,3) v[i][j] = 1;
			qs -= 9;
			FOR(i,3,n) if (qs > 0) v[i][0] = v[i][1] = 1, qs -= 2;
			FOR(i,3,m) if (qs > 0) v[0][i] = v[1][i] = 1, qs -= 2;
			FOR(i,0,n) FOR(j,0,m) if (qs > 0 && !v[i][j]) v[i][j] = 1, qs--;
			print();
		}
		else{
			if (qs == 2){ puts("Impossible"); return; }
			FOR(i,0,n) if (qs > 0) v[i][0] = v[i][1] = 1, qs -= 2;
			FOR(i,2,m) if (qs > 0) v[0][i] = v[1][i] = 1, qs -= 2;
			FOR(i,0,n) FOR(j,0,m) if (qs > 0 && !v[i][j]) v[i][j] = 1, qs--;
			print();
		}
	}
	else if (n == 1){ FOR(i,0,qs) v[0][i] = 1; print();}
	else if (m == 1){ FOR(i,0,qs) v[i][0] = 1; print();}
	else{
		if ((qs & 1) || qs == 2) puts("Impossible");
		else{
			if (n == 2) FOR(i,0,qs/2) v[0][i] = v[1][i] = 1;
			else if (m == 2) FOR(i,0,qs/2) v[i][0] = v[i][1] = 1;
			print();
		}
	}
}

int main(){
	int tc;
	scanf("%d", &tc);
	FOE(i,1,tc) solve(i);
	return 0;
}
