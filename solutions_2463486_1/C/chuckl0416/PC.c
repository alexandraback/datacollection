#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>

int TestCases, TCCount;
long long int A, B, S, E, x;
long long int Ans[1000];
char Check[100];
int i, L;

int main(){
	freopen("C-large-1.in", "r", stdin);
	freopen("C-large-1.out", "w", stdout);
	x = 0;
	for (A=0; A<10000000; A++){
		B = A;
		L = 0;
		while(B){
			Check[L] = (B%10)+48;
			B/=10;
			L++;
		}
		for (i=0; i<L; i++) if (Check[i]!=Check[L-i-1]) break;
		if (i!=L) continue;
		B = A*A;
		L = 0;
		while(B){
			Check[L] = (B%10)+48;
			B/=10;
			L++;
		}
		for (i=0; i<L; i++) if (Check[i]!=Check[L-i-1]) break;
		if (i!=L) continue;
		Ans[x] = A*A;
		x++;
	}
	Ans[x] = 2e+14;
	
	scanf("%d", &TestCases);
	for (TCCount=1; TCCount<=TestCases; TCCount++){
		printf("Case #%d: ", TCCount);
		scanf("%lld%lld", &A, &B);
		for (S=0; Ans[S]<A; S++);
		for (E=S; Ans[E]<=B; E++);
		printf("%lld\n", E-S);
	}
	
	
	return 0;
}

