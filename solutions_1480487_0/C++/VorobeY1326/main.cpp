#include<iostream>
#include<algorithm>
#include<stdio.h>
#include<math.h>
#include<set>
#include<vector>
#include<string.h>
#include<string>
#include<map>
#include<algorithm>
using namespace std;

vector<int>curr;
int sum;

int ok(int numb, double use)
{
	double have = 1. - use;
	for (int i=0; i<curr.size(); i++)
	{
		if (i == numb)
			continue;
		double need = (double(curr[numb]) + double(sum) * use - double(curr[i])) / ( double(sum) );
		if (need < 0)
			need = 0;
		have -= need;
	}
	if (have >= 0)
		return 26;
	return -26;
}

int main()
{
#ifdef _DEBUG
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
#endif

	const double EPS = 1e-12;

	int T;

	cin >> T;

	for (int cs = 1; cs <= T; cs ++)
	{
		int n;
		cin >> n;

		curr.clear();
		curr.resize(n);
		sum = 0;

		for (int i=0; i<n; i++)
		{
			cin >> curr[i];
			sum = sum + curr[i];
		}

		printf("Case #%d: ",cs);

		for (int i=0; i<n; i++)
		{
			
			double l = 0.;
			double r = 1.;

			while (r - l > EPS)
			{
				double mid = (r+l) / 2.;
				int prove = ok(i,mid);
				if (prove > 0)
					l = mid;
				else
					r = mid;
			}

			printf("%.8lf ",l*100.);
		}

		printf("\n");
	}

	return 0;
}