#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <cassert>
#include <sstream>
#include <functional>
#include <algorithm>
#include <map>
#include <string>
#include <vector>
#include <set>
#include <queue>

using namespace std;

int nt, n;
char s[5000];
int d[5000][5];

const int W = 521196;

char w[11][212000][10]; 
int cnt[11];

int main()
{
	for(int i = 0; i < W; i++)
	{
		gets(s);
		int k = strlen(s);
		for(int j = 0; j < k; j++) w[k][cnt[k]][j] = s[j];
		cnt[k]++;
	}

	int nt;
	scanf("%d", &nt);
	for(int tt = 1; tt <= nt; tt++)
	{
		fprintf(stderr, "test = %d\n", tt);
		printf("Case #%d: ", tt);
		
		scanf("%s", s + 1);

		n = strlen(s + 1);

		d[0][0] = d[0][1] = d[0][2] = d[0][3] = d[0][4] = 0;

		for(int i = 1; i <= n; i++) for(int j = 0; j < 5; j++) d[i][j] = n;

		for(int i = 1; i <= n; i++)
		{
			for(int len = 1; len <= 10 && len <= i; len++)
			{
				for(int j = cnt[len]; j--;)
				{
					int errors = 0;
					int first_error = -1, last_error = -1;

					for(int k = 0; k < len; k++)
					if (w[len][j][k] != s[i - len + 1 + k])
					{
						errors++;
						if (first_error == -1) first_error = k;
						if (last_error != -1 && k - last_error < 5) { errors = -1; break; }
						last_error = k;
					}

					if (errors != -1)
					{
						for(int jj = 0; jj < 5; jj++)
						{
							int left = 4;
							
							if (last_error != -1)
								left = min(left, len - 1 - last_error);
							else
								left = min(left, len + jj);

							if (first_error != -1 && jj + first_error < 4) continue;
							d[i][left] = min(d[i][left], d[i - len][jj] + errors);
						}
					}
				}

			}
		}

		int res = d[n][0];
		for(int i = 1; i < 5; i++) res = min(res, d[n][i]);

		printf("%d\n", res);
	}
	return 0;
}