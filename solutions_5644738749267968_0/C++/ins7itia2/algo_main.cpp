#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;


int DeceitfulWar(vector<double> &naomi, vector<double> &ken)
{
	int count = 0;

	int kenBegin = 0;
	int kenEnd = ken.size() - 1;
	for(int i = 0; i < naomi.size(); ++i)
	{
		if(naomi[i] > ken[kenBegin])
		{
			++count;
			++kenBegin;
		}
		else
		{
			--kenEnd;
		}
	}

	return count;

}

int War(vector<double> &naomi, vector<double> &ken)
{
	int count = 0;

	int kenBegin = 0;
	int kenEnd = ken.size() - 1;
	for(int i = naomi.size() - 1; i >= 0; --i)
	{
		if(naomi[i] > ken[kenEnd])
		{
			++count;
			++kenBegin;
		}
		else if(naomi[i] < ken[kenEnd])
			--kenEnd;
	}

	return count;
}

int main(int argc, char **argv)
{
	int T;
	scanf("%d", &T);
	int numCase = 1;
	while(T-- > 0)
	{
		int N;

		scanf("%d", &N);

		vector<double> naomi;
		vector<double> ken;

		// naomi
		for(int i = 0; i < N; ++i)
		{
			double blk;
			scanf("%lf", &blk);
			naomi.push_back(blk);
		}
		sort(naomi.begin(), naomi.end());

		// ken
		for(int i = 0; i < N; ++i)
		{
			double blk;
			scanf("%lf", &blk);
			ken.push_back(blk);
		}
		sort(ken.begin(), ken.end());

		int x = DeceitfulWar(naomi, ken);
		int y = War(naomi, ken);


		printf("Case #%d: %d %d\n", numCase, x, y);

		++numCase;
	}

	return 0;
}