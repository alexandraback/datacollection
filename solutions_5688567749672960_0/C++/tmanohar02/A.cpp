#include<bits/stdc++.h>
using namespace std;

long long rev(long long a){
	long long ans = 0;
	while(a != 0){
		ans = ans*10 + a%10;
		a /= 10;
	}
	return ans;
}

long long fPow(long long cur, long long num){
	long long ans = num - cur;
	long long temp = num;
	long long acc = 0, pp = 1;
	while(temp != 0){ 
		if(acc != 0)ans = min(ans, rev(temp)+acc);
		acc = (temp%10)*pp + acc;
		temp /= 10;
		pp *= 10;
	}
	return ans;
}

int main(){
	int T;
	cin>>T;
	for(int t=1; t<=T; t++){
		long long N;
		cin>>N;
		if(N <= 10){
			printf("Case #%d: %lld\n", t, N);
			continue;
		}
		long long cur = 1, ans = 0;
		while(cur*10 <= N){
			ans += fPow(cur, cur*10-1) + 1;
			cur *= 10;
		}
		long long f = fPow(cur, N);
		printf("Case #%d: %lld\n", t, ans);
	}
	return 0;
}
