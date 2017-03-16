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
	
	
	unsigned long long fairNum[1000];
	
	scanf("%d",&t);
	
	unsigned long long i = 1;
		
	int count = 0;
		
	while(true) {
		unsigned long long sqr = i * i;
			
		if(sqr > (unsigned long long)1e14) {
			break;
		}
			
		if(isPalin(sqr)) {
			fairNum[count] = sqr;
			count++;
		}
			
		do {
			++i;
		} while(!isPalin(i));
	}
	
	
	for(int caseCount = 1; caseCount <= t; ++caseCount) {
		scanf("%llu%llu",&a,&b);
		
		unsigned long long *lowerIndex = lower_bound(fairNum, fairNum + count, a);
		unsigned long long *upperIndex = upper_bound(fairNum, fairNum + count, b);
		
		printf("Case #%d: %llu\n", caseCount, (upperIndex - lowerIndex));
	}
	
	return 0;
}
