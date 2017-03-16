#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

const int MAXN = 100000;

double P[MAXN];
double C[MAXN];

int main()
{
	int t, i, j, k, A, B;
	double min_key, sum;
	freopen("A-large.in", "r", stdin);
	freopen("A-large.out", "w", stdout);
	scanf("%d", &t);

	for(i=0; i<t; i++)
	{
		scanf("%d %d", &A, &B);
		for(j=0; j<A; j++)
		{
			scanf("%lf", &P[j]);
		}

		C[0] = P[0];
		for(j=1; j<A; j++)
		  C[j] = C[j-1]*P[j];

		min_key = (B-A+1)*C[A-1]+(2*B+2-A)*(1.0-C[A-1]);
		if(min_key>B+2) min_key = B+2;
		if(min_key>A+B+1) min_key = A+B+1;

		for(j=1; j<A; j++){
		  sum = (B+1-A+2*j)*C[A-1-j]+(2*B+2-A+2*j)*(1.0-C[A-1-j]);
		  if(sum<min_key) min_key = sum;
		}

		printf("Case #%d: %lf\n", i+1, min_key);
	}

	return 0;
}

