#include<iostream>
#include<cstdio>
#include<algorithm>
#include<map>
#include<vector>
#include<cstdlib>
using namespace std;

//BEGINTEMPLATE_BY_ACRUSH_TOPCODER
#define SIZE(X) ((int)(X.size()))
#define LENGTH(X) ((int)(X.length()))
#define MP(X,Y) make_pair(X,Y)
typedef long long LL;
typedef unsigned long long uLL;
#define two(X) (1<<(X))
#define twoL(X) (((LL)(1))<<(X))
#define contain(S,X) (((S)&two(X))!=0)
#define containL(S,X) (((S)&twoL(X))!=0)

int main()
{
	int cs;
	cin >> cs;
	for (int c = 1; c <= cs; c++)
	{
		int a, n;
		cin >> a >> n;
		int m[105];
		for (int i = 0; i < n; i++)
			cin>>m[i];

		int best = n;

		if (a == 1)
			best = n;
		else
		{
			int cur = 0;
			sort(m, m + n);

			for (int i = 0; i < n; i++)
			{
				if (m[i] < a)
				{
					a += m[i];
				}
				else
				{
					best = min(best, cur + n - i);
					while (a <= m[i])
					{
						a += (a - 1);
						cur++;
					}
					a += m[i];
				}
			}
			best = min(best, cur);
		}
		cout << "Case #" << c << ": " << best << endl;
	}
	return 0;
}
