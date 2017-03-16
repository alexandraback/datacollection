#include<stdio.h>
int pt[500], sum, N;
bool valid(int x, double ll)
{
	double ol = ll;
	int i;
	ll = 100 - ll;

	double ppt = pt[x] + sum * (ol / 100);
	for(i = 1; i <= N; i++)
	{
		if(i == x) continue;
		if(pt[i] - ppt >= 0) continue;
		ll -= 100 * (ppt - pt[i])/sum ;
	}
	if(ll <= 0) return true;
	else return false;
}
int main()
{
	int T, t, i;
	double s, e, m;
	freopen("input-large.txt", "r", stdin);
	freopen("output-large.txt", "w", stdout);
	scanf("%d", &T);
	for(t = 1; t <= T; t++)
	{
		scanf("%d", &N);
		sum = 0;
		for(i = 1; i <= N; i++)
		{
			scanf("%d", &pt[i]);
			sum += pt[i];
		}
		printf("Case #%d:", t);
		for(i = 1; i <= N; i++)
		{
			s = 0;
			e = 100;
			while(e-s > 1E-7){
				m = (s+e)/2;
				if(valid(i, m)) e = m;
				else s = m;
			}
			printf(" %.6lf", s);
		}
		printf("\n");
	}
	return 0;
}