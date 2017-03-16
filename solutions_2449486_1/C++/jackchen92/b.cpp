#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>
#include <algorithm>
#include <limits>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <list>
#include <string>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = numeric_limits<int>::max();

const int nmax = 105;
int t[nmax][nmax];
int h[nmax][nmax];

int R, C;
bool done;

void cut()
{
	for(int r=0;r<R;r++)
	{
		int tmax=0, hmax=0;
		for(int c=0;c<C;c++)
		{
			tmax = max(tmax, t[r][c]);
			hmax = max(hmax, h[r][c]);
		}
		if(tmax < hmax)
		{
			done = false;
			for(int c=0;c<C;c++)
				h[r][c] = tmax;
		}
	}

	for(int c=0;c<C;c++)
	{
		int tmax=0, hmax=0;
		for(int r=0;r<R;r++)
		{
			tmax = max(tmax, t[r][c]);
			hmax = max(hmax, h[r][c]);
		}
		if(tmax < hmax)
		{
			done = false;
			for(int r=0;r<R;r++)
				h[r][c] = tmax;
		}
	}
}

bool success()
{
	for(int r=0;r<R;r++)
		for(int c=0;c<C;c++)
			if(h[r][c] != t[r][c])
				return false;
	return true;
}

int main(int argc,char* argv[])
{
	int num_test_cases;
	scanf("%d",&num_test_cases);
	for(int test_case=1; test_case<=num_test_cases; test_case++)
	{
		scanf("%d%d", &R, &C);
		for(int r=0;r<R;r++)
			for(int c=0;c<C;c++)
			{
				scanf("%d", &t[r][c]);
				h[r][c] = 100;
			}
		while(true)
		{
			done = true;
			cut();
			if(done)
				break;
		}

		printf("Case #%d: %s\n",test_case, success() ? "YES" : "NO");
	}
	return 0;
}
