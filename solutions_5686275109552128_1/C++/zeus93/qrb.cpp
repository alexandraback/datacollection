#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

#define N 1005

int val[N];
int main(){
	int t, n;
	int opt, ma;
	scanf("%d", &t);
	for(int id = 1; id <= t; id++){
		scanf("%d", &n);
		opt = ma = 0;
		for(int i = 0; i < n; i++){
			scanf("%d", &val[i]);
			if(opt < val[i]){
				opt = val[i];
				ma = val[i];
			}
		}
		int ans;
		for(int j = 1; j < ma; j++){
			ans = j;
			for(int i = 0; i < n; i++){
				if(ans >= opt){
					break;
				}
				if(val[i] < j){
					continue;
				}
				if(val[i] % j){
					ans += (val[i] / j);
				}
				else{
					ans += (val[i] / j - 1);
				}
			}
			if(ans < opt){
				opt = ans;
			}
		}
		printf("Case #%d: %d\n", id, opt);
	}
	return 0;
}
