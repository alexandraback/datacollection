
#include <cstdio>
#include <cmath>

int p(int x){
	int s[10]; int len = 0;
	while(x){
		s[len++] = x%10;
		x /= 10;
	}
	for(int i=0; i<len; ++i){
		if(s[i] != s[len-1-i]){
			return 0;
		}
	}
	return 1;
}
int main(){
	
	int t; scanf("%d",&t);
	int a, b;

	for(int testcase=1; testcase<=t; ++testcase){
		scanf("%d %d", &a, &b);
		int c = 0;
		for(int i=a; i<=b; ++i){
			int j = sqrt(i);
			if(j*j == i && p(i) && p(j)){
				++ c;
			}
		}
		printf("Case #%d: %d\n", testcase, c);
	}
	return 0;
}
