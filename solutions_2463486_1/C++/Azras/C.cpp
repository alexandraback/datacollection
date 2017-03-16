#include <cstdio>
#include <cmath>
#define OGR 15000000
#define LL long long
int below[OGR + 10];
int find(LL num){
	LL left = 0;
	LL right = 1000000000;
	while(left < right){
		LL midd = (left + right + 1) / 2;
		if(midd * midd > num) right = midd - 1;
		else left = midd;
	}
	return (int)left;
}
bool isPalindrome(LL num){
	LL rev, temp;
	temp = num;
	while(temp){
		rev *= 10;
		rev += (temp % 10);
		temp /= 10;
	}
	return (rev == num);
}
int main(){
	below[0] = 0;
	for(int i = 1; i <= OGR; i++){
		below[i] = below[i - 1];
		if(isPalindrome(i) && isPalindrome((LL)i * (LL)i)){
			below[i]++;
		}
	}
	int t;
	scanf("%d", &t);
	for(int test = 1; test <= t; test++){
		LL A, B;
		scanf("%lld %lld", &A, &B);
		A = find(A - 1);
		B = find(B);
		printf("Case #%d: %d\n", test, below[B] - below[A]);
	}
	return 0;
}
