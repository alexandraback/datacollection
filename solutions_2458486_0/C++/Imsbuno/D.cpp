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

#define sqr(x) ((x) * (x))
#define minn(x,y) (x=(y)<(x)?(y):(x))
#define maxx(x,y) (x=(y)>(x)?(y):(x))
#define pluss(x,y) (x+=(y),x%=mod)
#define random(x) ((((rand()%32767)*(rand()%32767)*(rand()%32767)%(x))+(x))%(x))

using namespace std;

typedef	long long	int64;


string	f[1 << 21];
int	s[55][55], t[55], p[55], o[55], K, N, C;


int	main()
{
	freopen("D-small-attempt1.in", "r", stdin);
	freopen("D-small-attempt1.out", "w", stdout);
	
	int	Test;
	scanf("%d", &Test);
	for (int test = 1; test <= Test; ++ test)
	{
		cerr << test << endl;
		
		C = 0;
		scanf("%d%d", &K, &N);
		memset(o, 0, sizeof(o));
		for (int i = 1, x; i <= K; ++ i)
		{
			scanf("%d", &x);
			maxx(C, x);
			++ o[x];
		}
		for (int i = 0; i < N; ++ i)
		{
			scanf("%d%d", &t[i], &s[i][0]);
			for (int j = 1; j <= s[i][0]; ++ j)
			{
				scanf("%d", &s[i][j]);
				maxx(C, s[i][j]);
			}
		}
		
		for (int x = 0; x < 1 << N; ++ x) f[x] = "!";
		f[0] = " ";
		for (int x = 0; x < 1 << N; ++ x)
		{
			if (f[x] == "!") continue;
			
			for (int i = 0; i <= C; ++ i) p[i] = o[i];
			for (int i = 0; i < N; ++ i) if (x & (1 << i))
			{
				for (int j = 1; j <= s[i][0]; ++ j) p[s[i][j]] ++;
				p[t[i]] --;
			}
			
			for (int i = 0; i < N; ++ i)
				if ((x & (1 << i)) == 0 && p[t[i]])
					minn(f[x ^ (1 << i)], f[x] + (char)('a' + i));
		}
		
		printf("Case #%d: ", test);
		if (f[(1 << N) - 1] == "!")
		{
			puts("IMPOSSIBLE");
			continue;
		}
		
		string	ans = f[(1 << N) - 1];
		for (int i = 1; i < ans.size(); ++ i)
			printf("%d%c", ans[i] - 'a' + 1, (i == ans.size() - 1 ? '\n' : ' '));
	}
	
	return 0;
}
