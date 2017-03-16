#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#define max_N 37
using namespace std;

long long int p(int k, int j){
	if(j==0) return 1;
	return ((long long int)k)*p(k, j-1);
}


int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int T;
	int N;
	int J;

	scanf("%d", &T);

	for(int i=0; i<T; i++){
		scanf("%d %d", &N, &J);

		printf("Case #%d:\n", i+1);

		int ans = 0;
		long long int origin = (1<<(N/2-1)) + 1;
		int t[max_N];
		long long int temp;
		long long int a[12];

		while(ans!=J){
			temp = origin;
			for(int j=0; j<N; j++){
                t[j]=temp%2;
				temp = temp/2;
			}
			temp = 0;
			for(int j=0; j<N; j++)
				temp += t[j] * p(10, j);
			printf("%I64d%I64d ", temp, temp);
			for(int k=2; k<=10; k++)
				printf("%I64d ", p(k, N/2)+1);
			printf("\n");
			ans++;
            origin += 2;
		}
	}

	return 0;
}
