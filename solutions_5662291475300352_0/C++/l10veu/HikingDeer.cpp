#include <cstdio>
#include <vector>
#include <map>
#include <set>

using namespace std;

int main()
{
	int t;
	scanf("%d", &t);
	for (int tc=1; tc<=t; ++tc)
	{
		vector<pair<int,int>> hikers;
		set<int> speeds;
		
		int N;
		scanf("%d", &N);
		for (int i=0; i<N; ++i)
		{
			int D, H, M;
			scanf("%d %d %d", &D, &H, &M);
			for (int j=0; j<H; ++j)
			{
				hikers.push_back(make_pair(D, M+j));
				speeds.insert(M+j);
			}
		}
		
		int ans = 0;
		if (speeds.size() > 1)
		{
			pair<int, int> slow, fast;
			if (hikers[0].second > hikers[1].second)
			{
				slow = hikers[1];
				fast = hikers[0];
			}
			else
			{
				slow = hikers[0];
				fast = hikers[1];
			}

			double time = (360 - (fast.first - slow.first)) / (fast.second - slow.second);
			double there = slow.first + time * slow.second;

			if (there < 360)
				ans = 1;
		}
		printf("Case #%d: %d\n", tc, ans);
	}
	
	return 0;
}