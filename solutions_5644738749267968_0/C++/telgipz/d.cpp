#include <cstdio>
#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <stack>
#include <cmath>
#include <queue>
using namespace std;

int N;
double a[10000], b[10000];
set<double> s;

void first_ans()
{
	int j = 0;
	int out = 0;
	for (int i = 0; i < N; ++i)
	{
		if (a[i] > b[j])
		{
			out++;
			j++;
		}
	}
/*
	for (int i = 0; i < N; ++i)
	{
		if (a[i] > m) out++;
	}*/
	printf("%d ", out);
}

void second_ans()
{
	int out = 0;
	for (int i = 0; i < N; ++i)
	{
		set<double>::iterator it = s.upper_bound(a[i]);
		if (it == s.end())
		{
			out++;
			s.erase(s.begin());
		}
		else
		{
			s.erase(it);
		}
	}
	printf("%d\n", out);
}

void input()
{
	scanf("%d", &N);

	for (int i = 0; i < N; ++i)
	{
		scanf("%lf", &a[i]);
	}
	for (int i = 0; i < N; ++i)
	{
		scanf("%lf", &b[i]);
		s.insert(b[i]);
	}
	sort(a, a+N);
	sort(b, b+N);
	first_ans();
	second_ans();
}

int main()
{
	freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	
	int T;
	scanf("%d", &T);

	for (int test = 1; test <= T; ++test)
	{
		printf("Case #%d: ", test);
		input();
	}

	return 0;
}