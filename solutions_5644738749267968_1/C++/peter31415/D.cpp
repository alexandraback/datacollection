#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

void solve(int caseN);

void solve(int caseN)
{
	int w = 0;
	int dw = 0;
	int n = 0;
	scanf("%d", &n);

	float* naomi = new float[n];
	float* ken = new float[n];

	for(int i = 0; i < n; i++)
		scanf(" %f", &naomi[i]);

	for(int i = 0; i < n; i++)
		scanf(" %f", &ken[i]);

	sort(naomi, naomi + n);
	sort(ken, ken + n);

	// war
	bool* used = new bool[n];	
	for(int i = 0; i < n; i++)
	{
		used[i] = false;
	}

	bool tmp = used[0];
	w = n;
	for(int i = 0; i < n; i++)
	{
		int kenChoice = -1;
		int j = 0;
		for(j = n - 1; j >= 0; j--)
		{
			bool tmp = used[j];
			if (!(tmp))
			{
				if (ken[j] > naomi[i])
				{
					kenChoice = j;
				}
			}
		}

		if (kenChoice > -1)
		{
			w--;
			used[kenChoice] = true;
		} else 
		{			
			for(int j = 0; j < n; j++)
			{
				if (!used[j])
				{
					used[j] = true;
					break;
				}
			}
		}			
	}

	// war

	// deceitful war
	for(int i = 0; i < n; i++)
	{
		used[i] = false;
	}

	dw = n;
	for(int i = 0; i < n; i++)		
	{
		int lowestUnused = 0;
		for(int j = 0; j < n; j++)
		{
			if (!used[j])
			{
				lowestUnused = j;
				break;
			}
		}

		if (naomi[i] < ken[lowestUnused])
		{
			dw--;
			for(int j = n- 1; j >=0 ;j--)
			{
				if (!used[j])
				{
					used[j]=true;
					break;
				}
			}
		} else {
			used[lowestUnused] = true;
		}
	}
	// deceitful war

	printf("Case #%d: %d %d\n", caseN, dw, w);
}

int main() {
	freopen("D-large.in", "r", stdin);
	freopen("out", "w", stdout);

	int t;
	scanf("%d", &t);

	for(int i = 1;i <= t; i++)
	{
		solve(i);
	}
}