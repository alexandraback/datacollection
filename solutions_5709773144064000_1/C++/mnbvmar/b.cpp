#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

double c, f, x;

void input(){
	scanf("%lf%lf%lf", &c, &f, &x);
}

void test(){
	input();
	
	double res = 1e100;
	double rate = 2;
	double tim = 0;
	
	while(true){
		if(tim + x / rate < res)
			res = tim + x / rate;
		else
			break;
		
		tim += c/rate;
		rate += f;
	}
	
	printf("%.7lf\n", res);
}

int main(){
	int t;
	scanf("%d", &t);
	for(int i = 1; i <= t; i++){
		printf("Case #%d: ", i);
		test();
	}
}
