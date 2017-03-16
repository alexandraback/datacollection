#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 25;

int cnt[MAXN];

int main(){	
	int testcases;
	scanf("%d", &testcases);
	
	for(int test = 0; test < testcases; test++){
		double C, F, X;
		scanf("%lf%lf%lf\n", &C, &F, &X);
		
		double curr_rate = 2.0;
		double curr_time = 0.0;
		double answ = X / curr_rate;
		
		while(answ > curr_time){
			if(answ > curr_time + X / curr_rate)
				answ = curr_time + (X / curr_rate);
			
			curr_time += C/curr_rate;
			curr_rate += F;
			//~ printf("%lf %lf %lf\n", curr_time, curr_rate, answ);
			}
		
		printf("Case #%d: %.09lf\n", test + 1, answ);
		
		}
	
	return 0;
}
