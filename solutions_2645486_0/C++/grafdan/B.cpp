#include <cstdio>
#define MINFTY -10000000

using namespace std;

int T;
int DP[20][20];
int V[20];

int E,R,N;

int min(int a, int b) {
	if(a<b) return a;
	return b;
}
int max(int a, int b) {
	if(a>b) return a;
	return b;
}
int testc() {
	int a = 1;
	scanf("%d %d %d",&E,&R,&N);
	for(int n=0;n<=N+1;n++) {
		for(int e=0;e<=E;e++) {
			DP[e][n] = MINFTY;
		}
	}
	DP[E][0] = 0;
	for(int n=1;n<=N;n++) {
		scanf("%d",&(V[n]));
	}
	for(int n=0;n<=N;n++) {
		for(int e=0;e<=E;e++) {
			if(DP[e][n]!=MINFTY) {
				for(int s = 0;s<=e;s++) {
					int new_e = min(E,e-s+R);
					DP[new_e][n+1] = max(DP[new_e][n+1],DP[e][n]+s*V[n]);
				}
			}
			DP[e][n] = MINFTY;
		}
	}
	int res = MINFTY;
	for(int e=0;e<=E;e++) {
		if(res<DP[e][N+1]) res = DP[e][N+1];
	}

	return res;
}

int main() {
	scanf("%d\n",&T);
	for(int t=0;t<T;t++) {
		int a = testc();
		printf("Case #%d: %d\n",t+1,a);
	}

}