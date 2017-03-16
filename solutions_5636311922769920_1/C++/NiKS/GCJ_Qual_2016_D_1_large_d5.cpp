#include<cstdio>

using namespace std;

#define REP(a, b, c) for(int a=(b); a<(c); a++)

int T, K, C;
long long S;

int main(){
	scanf("%d", &T);
	REP(t, 1, T+1){
		printf("Case #%d:", t);
		scanf("%d%d%lld", &K, &C, &S);
		int minS = K;
		if(K<=C) minS = 1;
		else minS = (K+C-1)/C;
		if(S<((long long) minS)) printf(" IMPOSSIBLE");
		else{
			long long offset = 0, cell = 0;
			REP(i, 0, minS){
				offset = i*C;
				cell = offset;
				REP(j, 1, C){
					cell = cell*K;
					offset++;
					if(offset<K) cell += offset;
				}
				printf(" %lld", cell+1);
			}
		}
		printf("\n");
	}
	return 0;
}
