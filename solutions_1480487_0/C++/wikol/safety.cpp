#include <cstdio>
#include <algorithm>

using namespace std;

int X;
int s[205];
double ans[205];
int N;

void read()
{
	scanf("%d", &N);
	for(int i = 0;i<N;i++)
	{
		scanf("%d", &s[i]);
		X += s[i];
	}
}
bool is_enough(int k, double p)
{
	double used = p;
	for(int i = 0;i<N;i++)
		if(i != k && (double)s[i] < (double)s[k] + (double)X*p)
			used += ((double)s[k] - (double)s[i] + (double)X * p)/(double)X;
	return used > 1.0;
}
void bin_search(int k)
{
	double p = 0.0, q = 1.0;
	for(int i = 0;i<100;i++)
	{
		double w = (p+q)/2.0;
		if(is_enough(k,w))
			q = w;
		else
			p = w;
	}
	ans[k] = p;
}
void get_result(int c)
{
	X = 0;
	read();
	for(int i = 0;i<N;i++)
		bin_search(i);
	printf("Case #%d: ", c);
	for(int i = 0;i<N;i++)
		printf("%lf ", ans[i] * 100.0);
	printf("\n");
}
int main()
{
	int T;
	scanf("%d", &T);
	for(int i = 1;i<=T;i++)
		get_result(i);
}
