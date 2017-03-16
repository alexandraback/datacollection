#include <cstdio>
#include <cmath>
#include <cstring>
#include <memory.h>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <map>
#include <queue>
using namespace std;
int a,b;

void init(){
	scanf("%d%d",&a,&b);
	return;
}

double process(){
	double ans=((double)b)+2.0;
	double prob=1.0;
	for (int i=1;i<=a;i++){
		double cur;
		scanf("%lf",&cur);
		prob*=cur;
		double e=(((double)a)-((double)i)+((double)b)-((double)i)+1.0)+(1.0-prob)*(((double)b)+1.0);
		ans=min(ans,e);
	}
	return ans;
}

int main(){
	int tcase;
	scanf("%d",&tcase);
	for (int i=1;i<=tcase;i++){
		init();
		printf("Case #%d: %.6lf\n",i,process());
	}
	return 0;
}
