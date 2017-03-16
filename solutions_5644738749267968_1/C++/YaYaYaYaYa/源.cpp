#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <list>
#include <vector>
#include <set>
using namespace std;

#define PRINT_CASE_NO printf("Case #%d: ", t + 1)

int count(const vector<double>& a, const vector<double>& b)
{
	int c = 0;
	for (int i = 0; i < a.size(); ++i)
	{
		if (a[i] > b[i])
			++c;
	}
	return c;
}

int main()
{
	int T;
	scanf("%d", &T);
	for (int t = 0; t < T; ++t)
	{
		int n;
		scanf("%d", &n);
		int y = 0, z = n;
		double test;
		vector<double> Naomi, Ken;
		for (int i = 0; i < n; ++i)
		{
			scanf("%lf", &test);
			Naomi.push_back(test);
		}
		for (int i = 0; i < n; ++i)
		{
			scanf("%lf", &test);
			Ken.push_back(test);
		}
		sort(Naomi.begin(), Naomi.end());
		sort(Ken.begin(), Ken.end());
		vector<double> Naomi_ = Naomi, Ken_ = Ken;
		int countn = 0;
		for (int i = 0; i < n; ++i)
		{
			y = max(y, count(Naomi, Ken) + countn);
			if (*Naomi.begin() > *Ken.rbegin())
				++countn;
			Naomi.erase(Naomi.begin());
			Ken.pop_back();
		}
		Naomi = Naomi_;
		Ken = Ken_;
		countn = 0;
		for (int i = 0; i < n; ++i)
		{
			z = min(z, count(Naomi, Ken) + countn);
			if (*Naomi.rbegin() > *Ken.begin())
				++countn;
			Naomi.pop_back();
			Ken.erase(Ken.begin());
		}
		PRINT_CASE_NO;
		printf("%d %d\n", y, z);
	}
	return 0;
}