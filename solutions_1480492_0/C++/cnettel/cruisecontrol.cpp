#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;


int main()
{
	int T;
	scanf("%d", &T);

	for (int k = 0; k < T; k++)
	{	
		vector<pair<double, pair<int, int> > > possiblecollides;
		int speeds[2500];
		bool lanes[2500];
		int poses[2500];
		int hasswitchedwith[2500];

		int N;
		scanf("%d", &N);
		for (int i = 0; i < N; i++)
		{
			hasswitchedwith[i] = -1;
			char tlf[255];
			scanf("%s %d %d", tlf, &speeds[i], &poses[i]);
			lanes[i] = (tlf[0] == 'R');
		}

		for (int i = 0; i < N; i++)
		{
			for (int j = i + 1; j < N; j++)
			{
				double sd = speeds[i] - speeds[j];
				double pd = poses[i] - poses[j];

				if (pd < 0) pd += 5;
				if (pd > 0) pd -= 5;

				if (sd == 0) continue;
				double val = pd / sd;
				if (val < 0)
				{
					possiblecollides.push_back(make_pair(-val, make_pair(i, j)));
				//	printf("Colliding %d %d at %lf\n", i, j, -val);
				}
			}
		}

		sort(possiblecollides.begin(), possiblecollides.end());

		double endtime = -1;
		for (int k = 0; k < possiblecollides.size(); k++)
		{
			double time = possiblecollides[k].first;
			int cars[2] = {possiblecollides[k].second.first, possiblecollides[k].second.second};
			if (lanes[cars[0]] != lanes[cars[1]]) continue;
			//printf("Collision %d, %d at %lf, %lf, time %lf\n", cars[0], cars[1], time * speeds[cars[0]] + poses[cars[0]], time * speeds[cars[1]] + poses[cars[1]], time);
			double pd = (time * speeds[cars[0]] + poses[cars[0]]) - (time * speeds[cars[1]] + poses[cars[1]]);
			//printf("PD\t\t\t\t%lf\n", pd);

			for (int j = 0; j < 2; j++)
			{
				bool canmove = true;
				int menum = cars[j];
				double mestart = time * speeds[menum] + poses[menum];
				double meend = mestart + 5;

				for (int n = 0; n < N && canmove; n++)
				{
					if (lanes[n] == lanes[cars[j]]) continue;
					double start = time * speeds[n] + poses[n];
					double end = start + 5;

					if (!(end < mestart || meend < start))
					{
						if ((end == mestart ) && speeds[n] <= speeds[menum])
						{
						}
						else
						if ((meend == start) && speeds[n] >= speeds[menum])
						{
						}
						else
							canmove = false;
					}
				}

				if (canmove)
				{
					//printf("Switching %d into %d, time %lf\n", menum, !lanes[menum], time);
					lanes[menum] = !lanes[menum];
					goto end;
				}
			}

			endtime = time;
			break;
			end:;
		}

		if (endtime == -1)
		{
			printf("Case #%d: Possible\n", k + 1);
		}
		else
			printf("Case #%d: %.10lf\n", k + 1, endtime);
	}
}