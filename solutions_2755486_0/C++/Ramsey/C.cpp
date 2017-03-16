#include <cstdlib>
#include <cstdio>
#include <vector>
#include <string>
#include <memory.h>
#include <algorithm>

using namespace std;

const char inFileName[] = "C-small.in";
const char outFileName[] = "C-small.out";

const int MaxN = 100;
const int MaxLen = 1000;

struct Tribe
{
	int d, n;
	long long w, e;
	long long s;
	long long delta_d, delta_p, delta_s;
	Tribe() {}
};

struct Segment
{
	int d;
	long long left, right;
	long long s;
	Segment() {}
};

bool cmp(const Segment& a, const Segment& b)
{
	return (a.d < b.d);
}

vector<Segment> segments;
int T, N;
Tribe a[MaxN];
long long heights[MaxLen];
long long between[MaxLen];

int main() {
	
	FILE* inFile = fopen(inFileName, "r");
	FILE* outFile = fopen(outFileName, "w");

	fscanf(inFile, "%d", &T);
	for (int t = 0; t < T; t++) 
	{
		segments.clear();
		Tribe tribe;
		fscanf(inFile, "%d", &N);
		for (int i = 1; i <= N; i++)
		{
			Tribe tribe;
			fscanf(inFile, "%d%d%lld%lld%lld%lld%lld%lld", &tribe.d, &tribe.n, &tribe.w, &tribe.e, &tribe.s, &tribe.delta_d, &tribe.delta_p, &tribe.delta_s);
			for (int j = 0; j < tribe.n; j++)
			{
				Segment seg;
				seg.d = tribe.d + j * tribe.delta_d;
				seg.left = tribe.w + j * tribe.delta_p;
				seg.right = tribe.e + j * tribe.delta_p;
				seg.s = tribe.s + j * tribe.delta_s;
				segments.push_back(seg);
			}
		}
		
		sort(segments.begin(), segments.end(), cmp);

		int sol = 0;
		memset(heights, 0, sizeof(heights));
		memset(between, 0, sizeof(between));
		int zero = MaxLen / 2;

		for (int ind = 0; ind < (int)segments.size(); ind++)
		{
			if (ind > 0 && segments[ind].d != segments[ind - 1].d)
			{
				int d = segments[ind - 1].d;
				for (int ind1 = ind - 1; ind1 >= 0; ind1--)
				{
					if (segments[ind1].d != d) break;
					for (int i = segments[ind1].left; i <= segments[ind1].right; i++)
					{
						if (segments[ind1].s > heights[zero + i])
							heights[zero + i] = segments[ind1].s;
						if (i > segments[ind1].left && segments[ind1].s > between[zero + i])
							between[zero + i] = segments[ind1].s;
					}
				}
			}

			for (int i = segments[ind].left; i <= segments[ind].right; i++)
			{
				if (segments[ind].s > heights[zero + i] || (i > segments[ind].left && segments[ind].s > between[zero + i])) 
				{
					sol++;
					break;
				}
			}
		}

		fprintf(outFile, "Case #%d: %d\n", t + 1, sol);
	}	
	
	fclose(inFile);
	fclose(outFile);
	return 0;
}
