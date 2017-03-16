#include <stdio.h>
#include<stdlib.h>
#pragma warning(disable:4996)
#include <vector>
#include <algorithm>
#include <math.h>
FILE *in, *out;
using namespace std;

long long int flip(long long int N){
	long long int x = 0;
	while (N != 0){
		x = x * 10 + N % 10;
		N = N / 10;
	}
	return x;
}
int digit(long long N){
	int x = 0;
	while (N != 0){
		x += 1;
		N /= 10;
	}
	return x;
}
long long int cut(long long int N){
	if (N < 10) return N;
	long long int x = N, y = 1; int z = digit(N);
	for(int j=0;j<(z+1)/2;j++){
		y *= 10;
		x /= 10;
	}
	return N - x *y;
}



int first(long long int N){
	while (N > 9){
		N = N / 10;
	}
	return N;
}

int main(){
	out = fopen("1.out", "w");
	int T; int ans=0;
	scanf("%d", &T);
	for (int i = 0; i < T; i++){
		long long int N;
		scanf("%lld", &N);
		long long int count = 0;
		while (N != 0){
			if (N % 10 == 0){
				N = N - 1;
				count = count + 1;
			}
			if (N < 20){ count += N; break; }
			count = count + (cut(N)-1);
			N = N -  (cut(N)-1);
			if (N == 0){
				break;
			}

			if (N % 10 != 0){
				if (cut(flip(N)) == 1){
					N = N - 2;
					count = count + 2;
				}
				else{
					N = flip(N);
					count = count + 1;
				}
			}
			else{
				N = N - 1;
				count = count + 1;
			}

		}




		printf("Case #%d: %lld\n", i + 1, count);
		fprintf(out, "Case #%d: %lld\n", i + 1, count);
	}
	return 0;
}