#include <stdio.h>
#include <iostream>
#include <cstring>
using namespace std;

void gothrough (int a, int* got) {
	int digit;
	// printf("going Through %d ,", a);
	// for (int i=0;i<=10;i++) {
	// 	printf("got[%d] = %d \n",i,got[i]);
	// }
	while (a > 0){
		// printf("a = %d\n",a);
		digit = a%10;
		if (!got[digit]) got[10]++;

		got[digit] = 1;
		a /= 10;
	}
}


int main(){
	freopen("in.txt","r",stdin);
	freopen("outlarge.txt","w",stdout);
	int T,cases,N;
	scanf("%d ", &T);
	
	for (cases=1;cases<=T;cases++) {
		scanf("%d ", &N);
		if (N==0) {
			printf("Case #%d: INSOMNIA\n", cases);
			continue;
		}

		int got[11];
		memset(got,0,sizeof got);
		int num = 0;

		while (got[10] < 10) {
			num += N;
			gothrough(num, got);
			
		}

		printf("Case #%d: %d\n", cases, num);

	}
	return 0;
}