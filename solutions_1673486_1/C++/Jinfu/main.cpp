#include <iostream>
#include <vector>
using namespace std;
int main()
{
	freopen("d:\\in.txt","r",stdin);
	freopen("d:\\out2.txt","w",stdout);
	int T;
	scanf("%d",&T);
	for(int t=1;t<=T;t++)
	{
		printf("Case #%d: ",t);
		double A,B;
		scanf("%lf %lf",&A,&B);
		double answer;
		double answer1;
		double answer2=B+2;
		double answer3= B+2;
		double p;
		double pp=1;
		for(int i=1;i<=A;i++)
		{
			scanf("%lf",&p);
			pp=pp*p;
			double tmp=(A-i)+(B-i+1)+(1.0-pp)*(B+1);
			if(tmp<=answer2) answer2=tmp;
		}
		answer1 = B-A+1+(1-pp)*(B+1);
		answer=answer1;
		if(answer2<answer) answer = answer2;
		if(answer3<answer) answer = answer3;
		printf("%.6lf\n",answer);
		//printf("%.6lf %.6lf %.6lf\n",answer1,answer2,answer3);
	}
	return 0;
}