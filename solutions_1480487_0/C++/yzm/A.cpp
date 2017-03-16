#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>

using namespace std;

double J[1000];

const double eps=1e-8;

double Calc(int N,double J[],double Min)
{
	double Ret=0;
	for (int i=1;i<=N;++i)
		if (Min>J[i])
			Ret+=(Min-J[i])/J[0];
	return Ret;
}

void Solve(int CaseX)
{
	int N;
	scanf("%d",&N);
	J[0]=0;
	for (int i=1;i<=N;++i)
	{
		scanf("%lf",&J[i]);
		J[0]+=J[i];
	}
	printf("Case #%d:",CaseX);
	for (int i=1;i<=N;++i)
	{
		double Min=0,Max=1,Mid;
		while (Min+eps<Max)
		{
			Mid=(Min+Max)/2;
			if (Calc(N,J,J[i]+Mid*J[0])>1)
				Max=Mid;
			else
				Min=Mid;
		}
		printf(" %.10lf",Min*100);
	}
	printf("\n");
}

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int T=0;
	scanf("%d",&T);
	for (int i=1;i<=T;++i)
		Solve(i);
	return 0;
}
