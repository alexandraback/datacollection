#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
using namespace std;


int main(void) {
	int t, testCases;
	cin >> testCases;
	unsigned long A, B, K, count;
	unsigned long a, b;
	
	for (t=1; t<=testCases; t++) {
		cin >> A >> B >> K;
		count = 0;
		for (a=0; a<A; a++) for (b=0; b<B; b++) if ((a&b) < K) count++;
		
		printf("Case #%d: %ld\n", t, count);
	}
	
	
	return 0;
}