
#include <cstdio>
#include <cmath>

int p(long long x){
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
	long long a, b;
	
	long long tab[1000], ptr = 0;

	for(int i=1; i<=10000000; ++i){
		if(p(i) && p(((long long)i)*i)){
			tab[ptr++] = ((long long)i)*i;
		}
	}
	
	for(int testcase=1; testcase<=t; ++testcase){
		scanf("%lld %lld", &a, &b);
		int c = 0;
		for(int i=0; i<ptr; ++i){
			if(tab[i] >= a && tab[i] <= b){
				++c;
			}
		}
		/*
		for(int i=a; i<=b; ++i){
			int j = sqrt(i);
			if(j*j == i && p(i) && p(j)){
				++ c;
			}
		}
		*/
		printf("Case #%d: %d\n", testcase, c);
	}

	return 0;
}
