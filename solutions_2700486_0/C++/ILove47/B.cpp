//#pragma comment(linker, "/stack:16777216")
#include <ctime>
#include <string>
#include <vector>
#include <map>
#include <list>
#include <iterator>
#include <set>
#include <queue>
#include <iostream>
#include <sstream>
#include <stack>
#include <deque>
#include <cmath>
#include <memory.h>
#include <cstdlib>
#include <cstdio>
#include <cctype>
#include <algorithm>
#include <utility>
using namespace std;

#define FOR(i, a, b) for(int (i) = (a); (i) < (b); ++(i))
#define MIN(A, B) ((A) < (B) ? (A) : (B))
#define MAX(A, B) ((A) > (B) ? (A) : (B))
#define ALL(V) V.begin(), V.end()
#define SIZE(V) (int)V.size()
#define PB push_back
#define MP make_pair
#define FILL(a,v) memset(a,v,sizeof(a))

const double PI = acos(-1.0);
const double EPS = 1e-7;

typedef long long ll;
typedef unsigned long long ull;

int n, x, y, my=20;
int a[100][100];
int r[100][100];

void solve()
{
	FILL(r,0);
	cin >> n >> x >> y;
	if (x > 40 || y > 40 || x < -40)
	{
		cout << "0.000\n";
		return;
	}
	int NN = 1 << n;
	for (int mask = 0; mask != NN; ++mask)
	{
		FILL(a,0);
		for (int i = 0; i < n; ++i)
		{
			int yy = my;
			int xx = 47;
			while (yy != 0 && a[yy-2][xx] == 0)
				yy -= 2;
			if (yy == 0)
				a[yy][xx] = 1;else
			if (a[yy-2][xx] != 0)
			{
				if (mask & (1 << i))//left
				{
					while (yy != 0 && a[yy-1][xx-1] == 0)
					{
						--yy;
						--xx;
					}
					if (yy == 0)
						a[yy][xx] = 1;else
					if (a[yy-1][xx-1] != 0 && a[yy-1][xx+1] != 0)
						a[yy][xx] = 1;else
					if (a[yy-1][xx+1] == 0)
					{
						while (yy != 0 && a[yy-1][xx+1] == 0)
						{
							--yy;
							++xx;
						}
						if (yy == 0)
							a[yy][xx] = 1;else
						if (a[yy-1][xx+1] != 0)
							a[yy][xx] = 1;
					}

				}else//right
				{
					while (yy != 0 && a[yy-1][xx+1] == 0)
					{
						--yy;
						++xx;
					}
					if (yy == 0)
						a[yy][xx] = 1;else
					if (a[yy-1][xx+1] != 0 && a[yy-1][xx-1] != 0)
						a[yy][xx] = 1;else
					if (a[yy-1][xx-1] == 0)
					{
						while (yy != 0 && a[yy-1][xx-1] == 0)
						{
							--yy;
							--xx;
						}
						if (yy == 0)
							a[yy][xx] = 1;else
						if (a[yy-1][xx-1] != 0)
							a[yy][xx] = 1;
					}
				}
			}
		}
		for (int i = 0; i != 100; ++i)
		for (int j = 0; j != 100; ++j)
			r[i][j] += a[i][j];
		/*for (int i = 0; i != 7; ++i){
		for (int j = 44; j != 50; ++j)
		{
			cout << a[i][j] << " ";
		}
		cout << endl;}
	cout << endl;*/
	}
	printf("%.6f\n",r[y][x+47]/(NN+0.0));
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	int tests;
	scanf("%d", &tests);
	++tests;
	for (int i = 1; i != tests; ++i)
	{
		int time = clock();
		printf("Case #%d: ", i);
		solve();
		cerr<<"Case #"<<i<<"\t time="<<clock()-time<<endl;
	}
}