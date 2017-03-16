#include <stdio.h>
#include <vector>
#include <string>
#include <algorithm>


using namespace std;


char w[20][2][30];
int n;

int one(int x){
	int ret = 0;
	while (x)
		x &= (x-1),
		ret++;
	return ret;
}


void gao()
{
	int i, j, k;
	int ans = 0;
	scanf ("%d", &n);
	for (i = 0; i < n; i++)
		scanf ("%s %s", w[i][0], w[i][1]);
	for (i = 1; i < (1<<n); i++)
	{
		vector<string> s1, s2;
		for (j = 0; j < n; j++)if ((1<<j) & i)
		{
			s1.push_back(w[j][0]);
			s2.push_back(w[j][1]);	
		}
		for (j = 0; j < n; j++) if (((1<<j) & i) == 0)
		{
			for (k = 0; k < s1.size(); k++) if (s1[k] == w[j][0]) break;
			if (k >= s1.size()) break;
			for (k = 0; k < s2.size(); k++) if (s2[k] == w[j][1]) break;
			if (k >= s2.size()) break;
		}
		if (j >= n) ans = max(ans, n - one(i));
	}
	printf ("%d\n", ans);
}


int main()
{
	int T;
	freopen ("C-small-attempt0.in", "r", stdin);
	freopen ("out.txt", "w", stdout);
	scanf ("%d", &T);
	for (int cas = 1; cas <= T; cas++)
	{
		printf ("Case #%d: ", cas);
		gao();
	}
	return 0;
}
