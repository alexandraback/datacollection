#include "bits/stdc++.h"
using namespace std;
int t;
int n;
bool done[10];
int cnt;
int tc = 0;
int lst;
void check(int num){
	while(num){
		cnt += !done[num % 10];
		done[num % 10] = 1;
		num /= 10;
	}
}
int main(){
	cin >> t;
	while(t--){
		memset(done , 0 , sizeof(done));
		cnt = 0;
		cin >> n;
		printf("Case #%d: " , ++tc);
		if(n == 0){
			printf("INSOMNIA\n");
		}
		else{
			for(int i = n ; cnt < 10 ; i += n){
				check(i);
				lst = i;
			}
			printf("%d\n" , lst);
		}
	}
}