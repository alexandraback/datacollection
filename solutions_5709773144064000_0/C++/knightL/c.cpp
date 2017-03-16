#include <cstring>
#include <cassert>
#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <cstdio>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)

const double EPS=1e-8;

int main()
{
	int T;
	scanf("%d",&T);
	for(int test=1;test<=T;test++)
	{
		double X;
		double F;
		double C;
		double cur=2;
		cin>>C>>F>>X;
		double res=1e100;
		double offset=0;
		for(int i=0;res+EPS>offset+X/cur;i++,offset+=C/cur,cur+=F)
			res=min(res,offset+X/cur);
		printf("Case #%d: %.10lf\n",test,res);
	}
	return 0;
}
