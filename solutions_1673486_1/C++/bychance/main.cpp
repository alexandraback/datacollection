#include<iostream>
#include<vector>
using namespace std;

int T,A,B;
double best;
vector<double> p;

int main()
{
	//freopen("in.txt","r",stdin);
	freopen("A-large.in","r",stdin);
	freopen("out.txt","w",stdout);
	scanf("%d", &T);
	for(int ca=1;ca<=T;++ca)
	{
		scanf("%d%d", &A, &B);
		p.clear();
		p.reserve(A);
		for(int i=0;i<A;++i)
		{
			double tmp;
			scanf("%lf",&tmp);
			p.push_back(tmp);
		}

		best = 1e30;

		double pi = 1;

		for (int C=A;C>=0;--C)
		{
			double e = (2*C+(B-A)+1)*pi + (2*C+(B-A)+1+B+1)*(1-pi);
			//cout<<e<<endl;
			if(best>e)
			{
				best = e;
			}
			if(C!=0)
			{
				pi*=p[A-C];

			}
			//cout<<pi<<endl;
		}

		if(A!=B)
		{
			if(best>B+2)
			{
				best = B+2;
			}
		}
		else
		{
			double e= (B+2)*(1-pi) + 1*pi;
			if(best>e)
			{
				best  =e;
			}
		}

		printf("Case #%d: %.6lf\n", ca, best);
	}
	return 0;
}