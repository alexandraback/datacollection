#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
int C,c,N,M,A[12][12],T[12][12];
bool ok;
bool check() {
	for (int i=0;i<N;i++) for (int j=0;j<M;j++) if (T[i][j]!=A[i][j]) return 0;
	return 1;
}
void GO2(int x) {
	if (x==M) {
		ok=ok || check();
		return;
	}
	GO2(x+1);
	int V[12];
	for (int i=0;i<N;i++) V[i]=A[i][x];
	for (int i=0;i<N;i++) A[i][x]=1;
	GO2(x+1);
	for (int i=0;i<N;i++) A[i][x]=V[i];
}
void GO(int x) {
	if (x==N) {
		GO2(0);
		return;
	}
	GO(x+1);
	int V[12];
	for (int i=0;i<M;i++) V[i]=A[x][i];
	for (int i=0;i<M;i++) A[x][i]=1;
	GO(x+1);
	for (int i=0;i<M;i++) A[x][i]=V[i];
}
int main () {
	scanf("%d",&C);
	for (int c=1;c<=C;c++) {
		ok=0;
		scanf("%d%d",&N,&M);
		for (int i=0;i<N;i++) for (int j=0;j<M;j++) scanf("%d",&T[i][j]);
		for (int i=0;i<N;i++) for (int j=0;j<M;j++) A[i][j]=2;
		GO(0);
		printf("Case #%d: %s\n",c,ok?"YES":"NO");
	}
	scanf("\n");
	return 0;
}
