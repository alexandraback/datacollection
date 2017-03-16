#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
using namespace std;

int main() {
	freopen("small.in","r",stdin);
	freopen("small.out","w",stdout);
	int T,cases,j,J,N;
	scanf("%d ",&T);
	
	scanf("%d %d",&N,&J);
	printf("Case #1:\n");

	int digit[50];
	memset(digit,0,sizeof digit);

	for (int i=0;i<J;i++){
		//find out the digits in base 2 of J;
		digit[0] = 1;
		digit[N-1] = 1;
		int num = i;

		for (j=1;j<=(N-1)/2;j++) {
			int d = num % 2;
			digit[j*2] = d;
			digit[j*2-1] = d;
			num /= 2;
		}
		for (j=0;j<N;j++) printf("%d",digit[j]);

		for (j=2;j<=10;j++) printf(" %d",j+1);
		printf("\n");
	}
}