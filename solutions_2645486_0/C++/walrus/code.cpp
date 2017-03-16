#include"stdio.h"
#include"algorithm"
using namespace std;
int main(){
	int T;
	scanf("%d",&T);
	for(int tt=1;tt<=T;tt++){
		printf("Case #%d: ", tt);
		int E, R, N;
		scanf("%d%d%d", &E, &R, &N);
		long long best[E+1];
		int v[N];
		for(int i=0;i<N;i++)scanf("%d", &v[i]);
		for(int i=0;i<=E;i++)best[i] = 0;
		for (int i=0;i<N;i++){
			long long best2[E+1];
			for(int j=0;j<=E;j++)best2[j] = best[j];
			for(int j = 0; j<=E; j++){
				for(int en = 0; en <= j; en++){
					int end_energy = min(j - en + R, E);
					best2[end_energy] = max(best2[end_energy], best[j] + v[i]*en);
				}
			}
			for(int j=0;j<=E;j++)best[j] = best2[j];
		}
		long long be = 0;
		for(int j=0;j<=E;j++)be = max(be, best[j]);
		printf("%Ld\n", be);
	}
}
