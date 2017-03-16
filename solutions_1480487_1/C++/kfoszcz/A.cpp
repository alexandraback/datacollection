#include <cstdio>
#include <algorithm>
using namespace std;

const int N = 202;

int J[N];
int n, sum;

bool check(int x, double votes)
{
	double A = votes;
	for (int i = 0; i < n; i++)
	{
		if (i == x) continue;
		double min_votes = max(0.0, ((J[x]-J[i])/(double)sum) + votes);
		A += min_votes;
		if (A > 1) return true;
	}
	return false;
}

double find(int x) // x - contestant's number
{
	double p, q, s;
	p = 0;
	q = 1;
	while (q - p > 0.0000001)
	{
		s = (p+q) / 2;
		if (check(x, s))
			q = s;
		else
			p = s;
	}
	return (p+q)/2;
}

int main()
{
	int z;
	scanf("%d", &z);
	for (int nr = 1; nr <= z; nr++)
	{
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
			scanf("%d", J + i);
			printf("Case #%d: ", nr);
		sum = 0;
		for (int i = 0; i < n; i++)
			sum += J[i];
		for (int i = 0; i < n; i++)
		{
			double result = 100*find(i);
			printf("%lf ", result);
		}
		printf("\n");
	}
	return 0;
}
