#include <stdio.h>
#include <algorithm>
using namespace std;

int testCases, n, r;
int dp[1000005];

int reverseDigits(int num){
	int numdig = 0, out = 0, powten = 1, incTen = 1;
	for(;powten < num;powten*=10){numdig++;}
	powten/=10;
	for(int i = 0; i < numdig; i++){
		out += (num%(powten*10))/powten * incTen;
		incTen *= 10;
		powten /= 10;
	}
	return out;
}

int main(){
	scanf("%d", &testCases);
	//printf("%d\n", reverseDigits(testCases));
	
	for(int t = 1; t <= testCases; t++){
		scanf("%d", &n);
		dp[1] = 1;
		for(int i = 2; i <= n; i++){
			//printf("i = %d, n = %d\n", i, n);
			dp[i] = dp[i-1] + 1;
			r = reverseDigits(i);
			if(r < i && (i%10)){
				//printf("i = %d, r = %d, dp[i] = %d, dp[r] + 1 = %d\n", i, r, dp[i], dp[r]+1);
				dp[i] = min(dp[i], dp[r]+1);
			}
		}
		printf("Case #%d: %d\n", t, dp[n]);
	}
}
