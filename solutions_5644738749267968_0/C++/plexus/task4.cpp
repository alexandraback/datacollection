#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
#include <cstring>

#define mp make_pair
#define pb push_back
#define F first
#define S second
#define INF (1<<30)

using namespace std;

const int N = 1111;

double a[N];
double b[N];

int main()
{
	#ifdef DEBUG
		freopen("input.txt", "r", stdin);
		//freopen("output.txt", "w", stdout);
	#else
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif

	int t;

	scanf("%d", &t);

	for(int test = 1; test <= t; test++)
	{
		printf("Case #%d: ", test);

		int n;
		scanf("%d", &n);

		for(int i = 0; i<n; i++)
			scanf("%lf", &a[i]);

		for(int i = 0; i<n; i++)
			scanf("%lf", &b[i]);

		sort(a, a + n);
		sort(b, b + n);

		int deceitfulScore = 0;
		int warScore = 0;

		int ind1 = n-1;
		int ind2 = n-1;

		while (ind1 >= 0 && ind2 >= 0)
		{
			if (a[ind1] > b[ind2])
			{
				deceitfulScore++;
				ind1--;
				ind2--;
			}
			else
			{
				ind2--;
			}
		}

		ind1 = 0;
		ind2 = 0;

		int lost = 0;

		while (ind1 < n && ind2 < n)
		{
			while (ind2 < n && a[ind1] > b[ind2])
				ind2++;

			if (ind2 < n && a[ind1] < b[ind2])
				lost++;

			ind1++;
			ind2++;
		}

		warScore = n - lost;

		printf("%d %d\n", deceitfulScore, warScore);

	}

	return 0;

}