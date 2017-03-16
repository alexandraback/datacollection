#include <bits/stdc++.h>

char s[1010];

int main(){
	int t;
	scanf(" %d", &t);
	
	for(int k = 1; k <= t; k++){
		int smax;
		int res = 0;
		int nump = 0;
		scanf(" %d", &smax);
	
		scanf(" %s", s);
		
		for(int i = 0; i <= smax; i++){
			if(nump < i){
				res += i-nump;
				nump = i;
			}
			nump += s[i] - '0';
		}
		
		printf("Case #%d: %d\n", k, res);
	}
	return 0;
}