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


int	a[105][105], M, N;


int	main()
{
	freopen("B-large.in", "r", stdin);
	freopen("B-large.out", "w", stdout);
	
	int	Test;
	scanf("%d", &Test);
	for (int test = 1; test <= Test; ++ test)
	{
		scanf("%d%d", &M, &N);
		for (int i = 1; i <= M; ++ i)
		for (int j = 1; j <= N; ++ j)
			scanf("%d", &a[i][j]);
		
		int	failed = 0;
		for (int i = 1; i <= M; ++ i)
		for (int j = 1; j <= N; ++ j)
		{
			int	sucRow = 1, sucCol = 1;
			for (int jj = 1; jj <= N; ++ jj) sucRow &= (a[i][jj] <= a[i][j]);
			for (int ii = 1; ii <= M; ++ ii) sucCol &= (a[ii][j] <= a[i][j]);
			if (!sucRow && !sucCol) failed = 1;
		}
		
		printf("Case #%d: %s\n", test, failed ? "NO" : "YES");
	}
	
	return 0;
}
