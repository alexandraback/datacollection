
#include <cstdio>

FILE *fin = fopen("input.txt", "rt"),
*fout = fopen("output.txt", "wt");

#include <vector>
#include <set>
#include <algorithm>
#include <functional>
using namespace std;

int n;

void input(vector<double> &a)
{
	int i = n;
	while (i--)
	{
		double data;
		fscanf(fin, "%lf", &data);
		a.push_back(data);
	}
}

int war(vector<double> a, vector<double> b)
{
	int score = 0;

	reverse(a.begin(), a.end());
	for (double &naomiValue : a)
	{
		auto ken = lower_bound(b.begin(), b.end(), naomiValue);

		if (ken != b.end() && *ken > naomiValue)
		{
			auto val = ken++;
			b.erase(val, ken);
		}
		else
		{
			b.erase(b.begin(), ++b.begin());
			score++;
		}
	}

	return score;
}

int deceitfulWar(vector<double> a, vector<double> b)
{
	int score = 0;

	int i = n;
	while (i--)
	{
		double naomiValue;

		auto aIterator = lower_bound(a.begin(), a.end(), b.front());
		if (aIterator == a.end())
		{
			naomiValue = -1;
			a.erase(a.begin(), ++a.begin());
		}
		else
		{
			naomiValue = numeric_limits<double>::max();
			auto val = aIterator++;
			a.erase(val, aIterator);
		}






		auto ken = lower_bound(b.begin(), b.end(), naomiValue);

		if (ken != b.end() && *ken > naomiValue)
		{
			auto val = ken++;
			b.erase(val, ken);
		}
		else
		{
			b.erase(b.begin(), ++b.begin());
			score++;
		}
	}

	return score;
}

void testCase()
{
	fscanf(fin, "%d", &n);

	vector<double> a, b;
	input(a);
	input(b);
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());

	fprintf(fout, "%d %d", deceitfulWar(a, b), war(a, b));
}

int main()
{
	int t;
	fscanf(fin, "%d", &t);
	for (int i = 1; i <= t; i++)
	{
		fprintf(fout, "Case #%d: ", i);
		testCase();
		fprintf(fout, "\n");
	}

	return 0;
}
