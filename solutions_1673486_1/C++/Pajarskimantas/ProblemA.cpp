#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <ctime>

using namespace std;

int main(){
	int testnum;
	scanf("%d", &testnum);
	for(int test = 0; test < testnum; test++){
		printf("Case #%d: ", test + 1);
		
		int n, m;
		scanf("%d %d", &n, &m);
		
		double bestprob = m+2, prob = 1, curr, currprob;
		for(int i = 1; i <= n; i++){
			scanf("%lf", &curr);
			prob *= curr;
			
			currprob = (double) prob*((n - i) + (m-i) + 1) + (1-prob) * ((n - i) + (m-i) + 1 + m + 1);
			if(currprob < bestprob)
				bestprob = currprob;
				
			
			}
		printf("%.7lf\n", bestprob);
		}
	return 0;
}
