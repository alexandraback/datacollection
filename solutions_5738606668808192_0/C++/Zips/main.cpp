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
		long long int origin = (1<<(N-1)) + 1;
		int t[max_N];
		long long int temp;
		long long int a[12];

		while(ans!=J){
			temp = origin;
			for(int j=0; j<N; j++){
                t[j]=temp%2;
				temp = temp/2;
			}

			int isnans = 0;

            for(int k=2; k<=10; k++){
                temp = 0;
                int isnp = 0;
				for(int j=0; j<N; j++)
					temp += t[j] * p(k, j);

				for(long long int j=2; j<sqrtl(temp); j++){
                    if(temp%j==0){
						a[k] = j;
						isnp = 1;
						break;
                    }
				}

				if(isnp == 0) isnans = 1;
            }

            if(isnans == 0){
				printf("%I64d ", temp);
				for(int k=2; k<=10; k++)
					printf("%I64d ", a[k]);
				printf("\n");
				ans++;
            }
            origin += 2;
		}
	}

	return 0;
}
