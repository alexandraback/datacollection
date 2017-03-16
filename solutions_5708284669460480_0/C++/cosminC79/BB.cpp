#include <cstdio>
#include <algorithm>
#include <string>
#include <cstring>
#define NMAX 105
#define LMAX 26
using namespace std;
int tests, kk, l, s, pi[NMAX], nxt[NMAX][LMAX], cnt[LMAX];
char keyboard[NMAX], pattern[NMAX];
double prob[NMAX][NMAX][NMAX];
// length i, match of j so far, last match prefix of k

int main()
{
	freopen("input", "r", stdin);
	freopen("output", "w", stdout);
	
	scanf("%d\n", &tests);
	for (int test_no = 1; test_no <= tests; test_no++)
	{
		printf("Case #%d: ", test_no);
		
		scanf("%d%d%d\n", &kk, &l, &s);
		fgets(keyboard + 1, NMAX, stdin);
		fgets(pattern + 1, NMAX, stdin);
		
		for (int i = 1; i <= kk; i++)
			cnt[keyboard[i] - 'A']++;
		
		int k = 0;
		for (int i = 2; i <= l; i++)
		{
			while (k && pattern[k + 1] != pattern[i])
				k = pi[k];
			if (pattern[k + 1] == pattern[i]) k++;
			
			pi[i] = k;
		}
		
		for (int i = 0; i <= l; i++)
			for (int j = 0; j < LMAX; j++)
			{
				k = i;
				if (k == l) 
					k = pi[k];
					
				while (k && pattern[k + 1] != j + 'A')
					k = pi[k];
				if (pattern[k + 1] == j + 'A')
					k++;
					
				nxt[i][j] = k;
			}
			
		prob[0][0][0] = 1.0;
		for (int len = 0; len < s; len++)
			for (int so_far = 0; so_far <= len; so_far++)
				for (int match_now = 0; match_now <= l && match_now <= len; match_now++)
					for (int next_key = 0; next_key < LMAX; next_key++)
					{
						k = nxt[match_now][next_key];
						if (k == l)
						{
							prob[len + 1][so_far + 1][k] += prob[len][so_far][match_now] * (double)cnt[next_key] / kk;
						}
						else
							prob[len + 1][so_far][k] += prob[len][so_far][match_now] * (double)cnt[next_key] / kk;
					}
		
		int worst = 0;
		for (int so_far = 0; so_far <= s; so_far++)
			for (int match_now = 0; match_now <= l; match_now++)
				if (prob[s][so_far][match_now] > 0)
					worst = max(worst, so_far);
		
		double res = 0.0;	
		for (int so_far = 0; so_far <= s; so_far++)
			for (int match_now = 0; match_now <= l; match_now++)
				res += prob[s][so_far][match_now] * so_far;
			
		printf("%.8lf\n", (double)worst - res);
		
		memset(pi, 0, sizeof(pi));
		memset(nxt, 0, sizeof(nxt));
		memset(cnt, 0, sizeof(cnt));
		memset(prob, 0, sizeof(prob));
	}
	return 0;
}

