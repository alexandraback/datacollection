/* 2014.5.11 Celicath */
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <map>
#include <stdint.h>

char lines[200][200];
char line[200];
int par[200][4];	//0:both 1:start 2:end 3:mid
char map[200];
bool checking[200];

bool go(int k)
{
	if (checking[k]) return true;
	else
	{
		if (map[k] == 0)
			return false;
		checking[k] = true;
		bool result = go(map[k]);
		checking[k] = false;
		return result;
	}
}

int main()
{
	FILE* fin = fopen("input.txt", "r");
	FILE* fout = fopen("output.txt", "w");

	int T;

	fscanf(fin, "%d", &T);

	for (int c_n = 1; c_n <= T; c_n++)
	{
		int N;

		int64_t result = 0;
		fscanf(fin, "%d", &N);
		bool can = true;
		for (int i = 0; i < N; i++)
		{
			fscanf(fin, "%s", line);
			char prev = '\0';
			int count = 0;
			for (int j = 0; line[j]; j++)
			{
				if (prev != line[j])
				{
					prev = line[j];
					lines[i][count++] = prev;
					for (int k = 0; k < count - 1; k++)
						if (lines[i][k] == prev)
							can = false;
				}
			}
			lines[i][count] = 0;
			lines[i][199] = count;
		}
		if (!can) goto hell;

		result = 1;

		for (int i = 'a'; i <= 'z'; i++)
		for (int j = 0; j < 4; j++)
			par[i][j] = 0;

		for (int i = 0; i < N; i++)
		{
			if (lines[i][199] == 1)
				par[lines[i][0]][0]++;
			else
			{
				for (int j = 0; j < lines[i][199]; j++)
				{
					if (j == 0)
						par[lines[i][j]][1]++;
					else if (j == lines[i][199] - 1)
						par[lines[i][j]][2]++;
					else par[lines[i][j]][3]++;
				}
			}
		}

		int tot = N;
		for (int i = 'a'; i <= 'z'; i++)
		{
			if (par[i][3] >= 2)
				result = 0;
			else if (par[i][3] == 1)
			{
				if (par[i][0] || par[i][1] || par[i][2])
					result = 0;
			}
			else
			{
				if (par[i][1] > 1 || par[i][2] > 1)
					result = 0;
				else
				{
					int minus = par[i][0] + par[i][1] + par[i][2] - 1;
					if (minus > 0) tot -= minus;
					for (int j = 1; j <= par[i][0]; j++)
						result = (result * j) % 1000000007;
				}
			}
		}
		if (result > 0)
		{
			for (int i = 'a'; i <= 'z'; i++)
			{
				map[i] = 0;
				checking[i] = false;
			}
			
			for (int i = 0; i < N; i++)
			{
				if (lines[i][199] == 1) continue;
				int a = lines[i][0];
				char b = lines[i][lines[i][199] - 1];
				map[a] = b;
			}
			for (int i = 'a'; i <= 'z'; i++)
			{
				if (go(i))
				{
					result = 0;
					break;
				}
			}
		}
		for (int j = 1; j <= tot; j++)
			result = (result * j) % 1000000007;

	hell:
		fprintf(fout, "Case #%d: %lld\n", c_n, result);
		printf("Case #%d: %lld\n", c_n, result);
	}
	return -0;
}
