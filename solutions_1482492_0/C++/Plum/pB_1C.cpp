#include<stdio.h>
#include<math.h>

struct Car{
		double t, x;
}car[2001];

double ac[1001];

int main(){
	int T, cnt;
	scanf("%d", &T);
	cnt = 0;
	while(T--){
		double D;
		int N, A;
		scanf("%lf %d %d", &D, &N, &A);
		for(int i = 0; i < N; i++){
			double a, b;
			scanf("%lf %lf", &a, &b);
			car[i] = (Car){a, b};
		}

		for(int i = 0; i < A; i++){
			scanf("%lf", &ac[i]);	
		}

		printf("Case #%d:\n", ++cnt);
		double initv = 0.0;
		double costTime;
		double initx = 0.0;
		for(int i = 0; i < A; i++){
			initv = costTime = 0.0;
			if(N == 1){
				costTime+=sqrt(2*D/ac[i]);
			}else{
				for(int j = 1; j < N; j++){
					double va = (car[j].x - car[j-1].x)/(car[j].t-car[j-1].t);
					double vb = initv + (ac[i]*(car[j].t-car[j-1].t));
					if(vb < va) costTime += sqrt(2*D/ac[i]);  
					else{
						if(initx == car[j-1].x) costTime += D/va;
						else costTime += (car[j].t - car[j-1].t);
					}
				}
			}
			printf("%lf\n", costTime);
		}

	}
	return 0;
}
