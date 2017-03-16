#include <cstdio>
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
void solve(int caseNum)
{
	double C=0,F=0,X=0,r=2,t=0;
	scanf("%lf %lf %lf",&C, &F, &X);
	while (fabs(X)>1e-7)
	{
		//cout << X << " " << C << " " << F <<endl;
		if (X>C/F*r+C)
		{
			t+=C/r;
			r+=F;
		}
		else
		{
			t+=X/r;
			X=0;
		}
	}
	printf("Case #%d: %.7lf\n",caseNum,t);
}
int main()
{
	int caseNum = 0;
	scanf("%d",&caseNum);
	for (int i = 0; i < caseNum; i ++)
	{
		solve(i+1);
	}
	return 0;
}