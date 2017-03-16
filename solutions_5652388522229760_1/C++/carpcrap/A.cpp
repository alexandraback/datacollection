#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;

int main(){
	int T;
	scanf("%d", &T);
	for(int tt =1; tt<=T; tt++){
		int n,j;
		scanf("%d", &n);
		if(n==0) {printf("Case #%d: INSOMNIA\n", tt); continue;}
		int ans =0;
		int cnt =0;
		bool b[10];
		for(int i=0; i<10; i++) b[i] = false;
		while(cnt<10){
			ans += n;
			int tmp = ans;
			while(tmp >0){
				if(!b[tmp%10]){
					cnt++;
					b[tmp%10] = true;
				}
				tmp/=10;
			}
		}
		printf("Case #%d: %d\n",tt, ans);
	}
	return 0;
}
