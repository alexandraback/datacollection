#include <stdio.h>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

int main()
{
	int T;
	scanf("%d", &T);
	for (int k = 0; k < T; k++)
	{
		int N;
		scanf("%d", &N);
		vector<pair<pair<pair<int, int>, int>, int> > data;
		vector<int> done;
		for (int i = 0; i < N; i++)
		{
			int a, b;
			scanf("%d %d", &a, &b);
			data.push_back(make_pair(make_pair(make_pair(a, b), 1), i));
			data.push_back(make_pair(make_pair(make_pair(b, a), 2), i));
			
			done.push_back(0);
		}

		int nowstars = 0;		
		set<pair<int, int> > canget;

		sort(data.begin(), data.end());

		bool ok = true;
		int steps = 0;

		for (int i = 0; i < data.size() && ok; i++)
		{
			//printf("Data is %d, %d, %d\n", data[i].first.first.first, data[i].first.second, data[i].second);
			while (data[i].first.first.first > nowstars && ok)
			{
				if (!canget.size())
				{
						ok = false;
						break;
				}
				pair<int, int> val = *canget.begin();
				canget.erase(canget.begin());

				if (done[val.second]) continue;
				done[val.second] = 1;
				nowstars++;
				steps++;
				/*for (int j = 1; j >= 0; j--)
				{
					for (int k = canget[j].size() - 1; k >= 0; k--)
					{
						int starcount = j + 1; 
						if (starcount == 3) starcount--;

						if (done[canget[j][k]] >= starcount)
						{
							canget[j].resize(canget[j].size() - 1);
							continue;
						}

						if (j == 2 && done[canget[j][k]] > 0)
						{
							canget[j - 1].push_back(canget[j][k]);
							canget[j].resize(canget[j].size() - 1);
							continue;
						}

						nowstars += starcount - done[canget[j][k]];
						done[canget[j][k]] = starcount;
						//printf("Taking %d at %d\n", canget[j][k], j + 1);
						canget[j].resize(canget[j].size() - 1);
						
						steps++;
						goto end1;
					}					
				}*/
			}

			
			if (data[i].first.second == 2)
			{
				nowstars += 2 - done[data[i].second];
				done[data[i].second] = 2;

				//printf("Taking %d at %d B\n", data[i].second, 2);
				steps++;
			}
			else
			{
				canget.insert(make_pair(-data[i].first.first.second, data[i].second));
			}
		}

		for (int k = 0; k < N; k++)
		{
			if (done[k] < 2) steps++;
		}

		if (ok) printf("Case #%d: %d\n", k + 1, steps);
		else
			printf("Case #%d: Too Bad\n", k + 1);
	}
}