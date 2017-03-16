#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <iterator>
#include <iostream>
#include <functional>
#include <sstream>
#include <numeric>

#define CLR( x , y ) ( memset( (x) , (y) , sizeof( (x) ) ) )
#define EPS 1e-9

using namespace std;

FILE *in=fopen("B.in","r");
FILE *out=stdout;//fopen("B.out","w");

int n;

int main()
{
	int i,j,k,test,tests;
	fscanf(in,"%d",&tests);
	long double C,F,X;
	for(test=1;test<=tests;test++){
		fscanf(in,"%lf %lf %lf", &C, &F, &X);
		long double best_ans = 1LL<<50;
		for(i=0;i<=ceil(X);i++) {
			long double ans = 0;
			long double cur_rate = 2;
			for(j=0;j<i;j++) {
				ans += C/cur_rate;
				cur_rate += F;
			}
			ans += X/cur_rate;
			if(ans > best_ans)break;
			best_ans = ans;
		}
		fprintf(out,"Case #%d: %llf\n",test, best_ans);


	}
	return 0;
}
