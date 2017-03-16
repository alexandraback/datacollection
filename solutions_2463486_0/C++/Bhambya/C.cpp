#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstdlib>
#include<cmath>
#include<list>
#include<deque>
#include<cstring>

using namespace std;

char c[200];

bool isPalin(unsigned long long n) {
	sprintf(c,"%llu",n);
	
	for(int i = 0, j = strlen(c) - 1; i < j ; i++,j--) {
		if(c[i] != c[j])
			return false;
	}
	
	return true;
}

int main() {
	int t;
	
	unsigned long long a, b;
	
	scanf("%d",&t);
	
	for(int caseCount = 1; caseCount <= t; ++caseCount) {
		scanf("%llu%llu",&a,&b);
		
		unsigned long long i = floor(sqrt(a));
	
		while(i * i < a) {
			++i;
		}
		
		unsigned long long count = 0;
		
		while(!isPalin(i)) {
			++i;
		}
			
		while(true) {
			unsigned long long sqr = i * i;
			
			if(sqr > b) {
				break;
			}
			
			if(isPalin(sqr)) {
				++count;
			}
			
			do {
				++i;
			} while(!isPalin(i));
		}
		
		printf("Case #%d: %llu\n", caseCount, count);
	}
	
	return 0;
}
