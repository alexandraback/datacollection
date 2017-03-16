#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#define max_K 102
using namespace std;

long long int p(int k, int c){
	if(c==0) return 1;
	return ((long long int)k)*p(k, c-1);
}

int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int T;

	scanf("%d", &T);

	int K, C, S;

	for(int i=0; i<T; i++){
		scanf("%d %d %d", &K, &C, &S);

		if(K>C*S){
			printf("Case #%d: IMPOSSIBLE\n", i+1);
			continue;
		}

        printf("Case #%d: ", i+1);

        int x=0;

        for(int j=0; j<(K+C-1)/C; j++){
			long long int m = (long long int)x;
			for(int k=1; k<C; k++){
				x++;
				if(x>=K) x=K-1;
				m = m*(long long int)K+(long long int)x;
			}
			printf("%I64d ", m+1);
			x++;
			if(x>=K) x=K-1;
        }
        printf("\n");

	}

	return 0;
}
