#include "stdafx.h"
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

struct Attack
{
	int w;
	int e;
	int s;
	int d;
};

bool operator < (const Attack& a1, const Attack& a2)
{
	return a1.d < a2.d;
}

int wall[10000];

int toWall(int cor)
{
	return (cor + 2000) * 2;
}

int main()
{
	FILE* in = fopen("C-small-attempt0 (1).in", "r");
	FILE* out = fopen("c.out.txt", "w");

	int t;
	int n;
	fscanf(in, "%d", &t);

	for (int it = 1; it <= t; it++)
	{
		fscanf(in, "%d", &n);

		vector<Attack> attacks;

		memset(wall, 0, sizeof(wall));

		for (int itn = 0; itn < n; itn++)
		{
			int di, ni, wi, ei, si, delta_di, delta_pi, delta_si;
			fscanf(in, "%d %d %d %d %d %d %d %d", &di, &ni, &wi, &ei, &si, &delta_di, &delta_pi, &delta_si);

			int w = wi, e = ei, d = di, s = si;
			for (int i = 0; i < ni; i++)
			{
				Attack a;
				a.w = w;
				a.e = e;
				a.d = d;
				a.s = s;
				attacks.push_back(a);
				w += delta_pi;
				e += delta_pi;
				d += delta_di;
				s += delta_si;
			}
		}
		sort(attacks.begin(), attacks.end());

		vector<pair<int, int>> intervals;
		int count = 0;
		for (int i = 0; i < attacks.size(); i++)
		{
			Attack a = attacks[i];
			bool broken = false;
			for (int j = toWall(a.w); j <= toWall(a.e); j++)
			{
				if (wall[j] < a.s)
				{
					count++;
					wall[j] = a.s;
					broken = true;
					break;
				}
			}
			if (i + 1 < attacks.size() && attacks[i + 1].d != a.d)
			{
				int firstAttackOnDay = 0;
				for (int j = i; j >= 0; j--)
					if (attacks[j].d != a.d)
					{
						firstAttackOnDay = j + 1;
						break;
					}
				for (int ia = firstAttackOnDay; ia <= i; ia++)
				{
					Attack a = attacks[ia];
					for (int j = toWall(a.w); j <= toWall(a.e); j++)
					{
						if (wall[j] < a.s)
						{
							wall[j] = a.s;
						}
					}
				}
			}
		}

		fprintf(out, "Case #%d: %d\n", it, count);
	}

	return 0;
}