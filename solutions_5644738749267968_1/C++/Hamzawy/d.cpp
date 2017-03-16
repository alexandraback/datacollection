/*
 * d.cpp
 *
 *  Created on: Apr 12, 2014
 *      Author: AhmedHamza
 */

#include<cstdio>
#include<algorithm>
#include<set>
using namespace std;

int tc, n;
double nao[1001], ken[1001];

int normal()
{
	int res = 0;
	set<double> s(ken, ken + n);
	for (int i = 0; i < n; ++i)
	{
		auto it = s.upper_bound(nao[i]);
		if (it == s.end())
		{
			res += nao[i] > *s.begin();
			s.erase(s.begin());
		}
		else
		{
			s.erase(it);
		}
	}
	return res;
}

int other()
{
	int res = 0;
	set<double> s(ken, ken + n);
	for (int i = 0; i < n; ++i)
	{
		if (nao[i] < *s.begin())
		{
			s.erase(*s.rbegin());
		}
		else
		{
			s.erase(s.begin());
			res++;
		}
	}
	return res;
}

int main()
{

//	freopen("d.in", "rt", stdin);
		freopen("D-large.in", "rt", stdin);
		freopen("D-large.txt", "wt", stdout);

	scanf("%d", &tc);
	for (int t = 1; t <= tc; ++t)
	{
		scanf("%d", &n);
		for (int i = 0; i < n; ++i)
			scanf("%lf", nao + i);
		for (int i = 0; i < n; ++i)
			scanf("%lf", ken + i);
		sort(nao, nao + n);
		sort(ken, ken + n);

		int n_score = normal();
		int o_score = other();

		printf("Case #%d: %d %d\n", t, o_score, n_score);

		//		for (int i = 0; i < n; ++i)
		//			printf("%lf ", nao[i]);
		//		printf("\n");
		//		for (int i = 0; i < n; ++i)
		//			printf("%lf ", ken[i]);
		//		printf("\n");
	}
	return 0;
}
