#include "bits/stdc++.h"
using namespace std;
const int N = 105;
int t;
int k , c , s;
int tc = 0;
long long pw[N];
int cnt;
void go(int depth , long long print , int cnt){
	if(depth > c || cnt > k){
		printf("%lld " , print);
		return;
	}
	go(depth + 1 , print + pw[c - depth] * (cnt - 1LL) , cnt + 1);
}
int main(){
	cin >> t;
	while(t--){
		cin >> k >> c >> s;
		printf("Case #%d: " , ++tc);
		if(((k + c - 1) / c) > s){
			printf("IMPOSSIBLE\n");
		}
		else{
			pw[0] = 1;
			for(int i = 1 ; i <= c ; ++i){
				pw[i] = pw[i - 1] * k;
			}
			cnt = 1;
			while(cnt <= k){
				go(1 , 1LL , cnt);
				cnt += c;
			}
			printf("\n");
		}
	}
}