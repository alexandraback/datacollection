#include <cstdio>
#include <cstring>

int main(){
	int T;
	int v3, v5, v2,v,tmp;
	v2=0;
	v3=0;
	v5=0;
	scanf("%d", &T);
	printf("Case #1:\n");
	int R, N, M, K;
	for (int t = 0; t < T; t++){
		scanf("%d %d %d %d", &R, &N, &M, &K);
		for (int i = 0; i < R; i++){
			v2=0;
			v3=0;
			v5=0;
			for (int j = 0; j < K; j++){
				scanf("%d ", &tmp);
				//printf("%d ", tmp);
				if (tmp == 1) continue;
				
				v = 0;
				while(tmp%2==0){
					v++;
					tmp=tmp/2;
				}
				if (v > v2) v2 = v;
				//printf("%d ", v);
				v = 0;
				while(tmp%3==0){
					v++;
					tmp=tmp/3;
				}
				if (v > v3) v3 = v;
				//printf("%d ", v);
				v = 0;
				while(tmp%5==0){
					
					v++;
					//if(v>5)printf("porra");
					tmp=tmp/5;
				}
				if (v > v5) v5 = v;
				//printf("%d ", v);
			}
			for (int i = 0; i < v3; i++) printf("3");
			for (int i = 0; i < v5; i++) printf("5");
			int rest = N-v3-v5;
			while (rest < v2 && rest > 0){
				printf("4");
				v2-=2;
				rest--;
			}
			for (int i = 0; i < rest; i++) printf("2");
			printf("\n");
		}
	}
	return 0;
}