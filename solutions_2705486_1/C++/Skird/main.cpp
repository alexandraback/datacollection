#include <ctime>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cassert>

#include <algorithm>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <bitset>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <map>

#define mp make_pair

#ifdef LOCAL
    #define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
    #define eprintf(...) 42
#endif

using namespace std;

typedef long long ll;
typedef long double lf;

void initrand()
{
	ll seed;
	asm("rdtsc":"=A"(seed));
	srand(seed);
}

const int maxl = 4400, dictsz = 521196, sumlen = 4500000;

char pool[sumlen], *dict[dictsz], data[maxl + 1];
int dp[maxl][5], n, len[dictsz];

int solve()
{
	memset(dp, 127, sizeof(dp));
	scanf("%s\n", data), n = strlen(data);
	dp[0][4] = 0;
	for (int i = 0; i < n; i++)
		for (int d = 0; d <= 4; d++)
			for (int j = 0; j < dictsz; j++)
			{
				int last = -d - 1, ok = 1, cnt = 0;
				if (i + len[j] > n) continue;
				for (int k = 0; ok && k < len[j]; k++)
				{
					if (dict[j][k] == data[i + k]) continue;
					if (k - last < 5) ok = 0;
					last = k;
					cnt++;
				}
				int pos = min(4, (int) len[j] - last - 1);
				if (ok) dp[i + len[j]][pos] = min(dp[i + len[j]][pos], dp[i][d] + cnt);
			}
	return *min_element(dp[n], dp[n] + 5);
}

void readdict()
{
	FILE *fin = fopen("dictionary.txt", "r");
	char *word = pool;
	int ptr = 0;
	while (fscanf(fin, "%s\n", word) == 1)
	{
		dict[ptr] = word;
		len[ptr] = strlen(dict[ptr]);
		word += len[ptr] + 1;
		ptr++;
	}
	fclose(fin);
	assert(ptr == dictsz);
}

int main()
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	readdict();
	int t;
	scanf("%d\n", &t);
	for (int i = 0; i < t; i++) printf("Case #%d: %d\n", i + 1, solve());
	return 0;
}
