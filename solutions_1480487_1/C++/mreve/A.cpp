#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int N;
double X;
vector<int> V;
const double eps = 0.000000001;

bool dasie(int I, double s)
{
	double Val = (double)V[I] + X*s;
	double left = 1.0 - s;
//	printf("Val: %lf, ", Val);
	for(int i=0; i<V.size(); i++)
		if(i != I)
		{
//			printf("%lf\n", (double)V[i] + X*left);
			if((double)V[i] + X*left < Val)
				return true;
			else
			{
				if((double)V[i] < Val)
					left -= ((Val-(double)V[i])/X);
			}
		}
	return false;
}

int main()
{
	int Z, a;
	double p, q, s;
	scanf("%d", &Z);
	for(int z=1; z<=Z; z++)
	{
		scanf("%d", &N); X = 0.0;
		for(int i=1; i<=N; i++)
		{
			scanf("%d", &a);
			X += (double)a;
			V.push_back(a);
		}
//		printf("X:%lf, ", X);
		printf("Case #%d: ", z);
		for(int i=0; i<V.size(); i++)
		{
			p = 0.0; q = 1.0;
			while(p+eps<q)
			{
				s = (p+q)/2;
//				printf("%lf, %lf: %lf\n", p, q, s);
				if(dasie(i, s))
					q = s;
				else
					p = s+eps;
			}
			printf("%lf ", p*100.0);
		}
		printf("\n");
		V.clear();
	}
	return 0;
}
