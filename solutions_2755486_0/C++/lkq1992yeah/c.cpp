#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

#define MAX(a,b)   ((a) > (b) ? (a) : (b))

int mid = 500;
int wall[2 * 500 + 1];
int repair[2 * 500 + 1];

struct attack
{
	int time, west, east, strength;
	
	bool operator < (const attack &x) const
	{
		return time < x.time;
	}
};

attack atts[10000];
int cnt = 0;

void Get_Repair()
{
	for (int i = 0; i <= 2 * mid; i++)
		if (repair[i] != 0)
			wall[i] = MAX(wall[i], repair[i]);
	memset (repair, 0, sizeof repair);
}

void Solve()
{
	int ret = 0;
	int N;
	int i, j;
	int d, n, w, e, s, d_d, d_p, d_s;
	scanf("%d", &N);
	cnt = 0;
	for (i = 0; i < N; i++)
	{
		scanf("%d%d%d%d%d%d%d%d", &d, &n, &w, &e, &s, &d_d, &d_p, &d_s);
		for (j = 0; j < n; j++)
		{
			atts[cnt] = (attack){d + j * d_d, w + j * d_p, e + j * d_p - 1, s + j * d_s};
			cnt++;
		}
	}
	sort(atts, atts + cnt);
	memset (wall, 0, sizeof wall);
	memset (repair, 0, sizeof repair);
	int last_day = -1;
	//printf("\n");
	for (i = 0; i < cnt; i++)
	{
		if (last_day != atts[i].time)
		{
			Get_Repair();
			last_day = atts[i].time;
		}
		//printf("Attack: %d %d %d %d\n", atts[i].time, atts[i].west, atts[i].east, atts[i].strength);
		bool can_attack = false;
		for (j = atts[i].west + mid; j <= atts[i].east + mid; j++)
			if (atts[i].strength > wall[j])
			{
				//printf("succeed.\n");
				can_attack = true;
				break;
			}
		if (can_attack)
		{
			ret++;
			for (j = atts[i].west + mid; j <= atts[i].east + mid; j++)
				repair[j] = MAX(repair[j], atts[i].strength);
		}
	}
	printf("%d\n", ret);
}

int main()
{
	int cas, t;
	scanf("%d", &t);
	for (cas = 1; cas <= t; cas++)
	{
		printf("Case #%d: ", cas);
		Solve();
	}
	return 0;
}
