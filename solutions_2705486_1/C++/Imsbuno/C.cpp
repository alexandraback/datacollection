#include <map>
#include <set>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <cctype>
#include <cstdio>
#include <memory>
#include <string>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <windows.h>

#define sqr(x) ((x) * (x))
#define minn(x,y) (x=(y)<(x)?(y):(x))
#define maxx(x,y) (x=(y)>(x)?(y):(x))
#define pluss(x,y) (x+=(y),x%=mod)
#define random(x) ((((rand()%32767)*(rand()%32767)*(rand()%32767)%(x))+(x))%(x))

using namespace std;

typedef	long long	int64;


int	f[4444][5], A[600000], N = 0;
char	a[600000][11], s[4444];


int	main()
{
	freopen("C-large.in", "r", stdin);
	freopen("C-large.out", "w", stdout);
	
	ifstream fin("dic.txt");
	while (fin >> s)
	{
		++ N;
		strcpy(a[N], s);
		A[N] = strlen(a[N]);
	}
	
	int	Test;
	scanf("%d", &Test);
	for (int test = 1; test <= Test; ++ test)
	{
		cerr << test << endl;
		
		scanf("%s", s + 1);
		int	S = strlen(s + 1);
		
		memset(f, 60, sizeof(f)); f[0][4] = 0;
		for (int i = 1; i <= S; ++ i)
		for (int k = 0; k <= 4; ++ k) if (f[i - 1][k] < S)
		for (int j = 1; j <= N; ++ j)
		{
			if (S - i + 1 < A[j]) continue;
			
			int	last = -(k + 1), suc = 1, cnt = 0;
			for (int t = 0; t < A[j] && suc; ++ t)
				if (a[j][t] != s[i + t])
				{
					if (t - last < 5) suc = 0;
					last = t;
					++ cnt;
				}
			
			if (suc)
			{
				minn(f[i + A[j] - 1][min(A[j] - last - 1, 4)], f[i - 1][k] + cnt);
			}
		}
		
		int	ans = 1 << 30;
		for (int k = 0; k <= 4; ++ k) minn(ans, f[S][k]);
		printf("Case #%d: %d\n", test, ans);
	}
	
	return 0;
}
