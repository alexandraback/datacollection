#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#define max_T 100
using namespace std;

int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int T;
	scanf("%d", &T);

	long long int N;
	long long int temp;
	int a[10];
	int x;
	int num;

	for(int i=0; i<T; i++){
		scanf("%I64d", &N);

		if(N==0){
			printf("Case #%d: INSOMNIA\n", i+1);
			continue;
		}

		for(int j=0; j<10; j++) a[j]=0;

		x=0;
		num=10;

		while(num!=0){
			x++;
			temp = ((long long int)x) * N;
            while(temp!=0){
					if(a[temp%10]==0){ num--; a[temp%10]=1; }
					temp=temp/10;
            }
		}

		printf("Case #%d: %I64d\n", i+1, ((long long int)x) * N);
	}

	return 0;
}
