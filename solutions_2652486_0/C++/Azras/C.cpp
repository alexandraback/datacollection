#include <cstdio>
#define LL long long
LL arr[1000];
int main(){
	int t, r, n, m, k;
	scanf("%d", &t);
	scanf("%d %d %d %d", &r, &n, &m, &k);
	printf("Case #1:\n");
	for(int t = 0; t < r; t++){
		for(int i = 0; i < k; i++){
			scanf("%lld", &arr[i]);
		}
		int bestNum = 222;
		int bestVal = 0;

		for(int a = 2; a <= m; a++){
			for(int b = 2; b <= m; b++){
				for(int c = 2; c <= m; c++){
					int pq[3] = {a, b, c};
					LL prod = 1;
					for(int i = 0; i < k; i++){
						int got = 0;
						for(int mask = 0; mask < (1LL<<3); mask++){
							LL temp = 1;
							for(int j = 0; j < 3; j++){
								if(mask&(1<<j)) temp *= pq[j];
							}
							if(temp == arr[i]) got++;
						}
						prod *= got;
					}

					//
					if(prod > bestVal){
						bestVal = prod;
						bestNum = 100 * a + 10 * b + c;
					}
				}
			}
		}
		printf("%d\n", bestNum);
	}
	return 0;
}

