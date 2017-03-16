#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
using namespace std;

const int max_n = 100100;
double mul[max_n];
int A,B;
int T;


int main()
{
	scanf("%d",&T);
	for(int ii=1;ii<=T;++ii)
	{
		scanf("%d%d",&A,&B);
		mul[0]=1;
		double pi;
		for(int i=1;i<=A;++i)
		{
			scanf("%lf",&pi);
			mul[i]=mul[i-1]*pi;
		}
		double min_ans=0;
		double tmp_ans;
		//keep typeing
		min_ans = mul[A]*(B-A+1)+(1-mul[A])*(2*B-A+2);
		//press enter
		tmp_ans = B+2;
		if(tmp_ans < min_ans)min_ans= tmp_ans;
		// press backspace i times
		for(int i=1;i<=A;++i)
		{//now at postion A-i
			if(i!=A)
				tmp_ans = mul[A-i]*(B-A+2*i+1)+(1-mul[A-i])*(2*B-A+2*i+2);
			else
				tmp_ans = A+B+1;
			if(tmp_ans<min_ans)min_ans = tmp_ans;
		}
		printf("Case #%d: %.6lf\n",ii,min_ans);
	}
	return 0;
}
