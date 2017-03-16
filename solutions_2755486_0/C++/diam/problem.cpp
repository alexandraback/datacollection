
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <unordered_map>


using namespace std;


 int d[2000]; int n[2000]; int w[2000]; int e[2000]; int s[2000]; int _d[1000]; int _p[1000]; int _s[1000];
 int wall[10000000];
 int shft = 1000000;
int main()
{
	freopen("input.txt","rt", stdin);
	freopen("output.txt","wt", stdout);			
	int tests;
	scanf("%d\n", &tests);	
	for (int test = 1; test <= tests; test++)
	{
		memset(wall, 0, sizeof(wall));
		int N;
		scanf("%d", &N);		
		for (int i = 0; i < N; i++)
		{
			scanf("%d%d%d%d%d%d%d%d", &d[i], &n[i], &w[i], &e[i], &s[i], &_d[i], &_p[i], &_s[i]);
		}
		int anw = 0;
		
		for (int time = 0; time <= 676060; time++)
		{
			//if (time < 50)
				//printf("%d  %d\n", anw, time);
			for (int i = 0; i < N; i++)
			{
				if (((time-d[i]) % _d[i] == 0) && time >= d[i])
				{
					int t = (time-d[i]) / _d[i];
					if (t < n[i])
					{
						// process attack number 0
						int xw = w[i] + _p[i]*t;
						int xe = e[i] + _p[i]*t;
						int xs = s[i] + _s[i]*t;
						xw *=2;
						xe*=2;
						bool kill = 0;
						for (int k = xw; k <= xe; k++)
							if (wall[shft+k] < xs)
								kill = 1;
						//printf("tribe %d day %d\n", i, time);
						//printf("attack %d %d %d\n", xw, xe, xs);
						if (kill)
						{
							//printf("success %d time %d\n", i, t);
							anw++;
						}
					}
				}
			}

			for (int i = 0; i < N; i++)
			{
				if (((time-d[i]) % _d[i] == 0) && time >= d[i])
				{
					int t = (time-d[i]) / _d[i];
					if (t < n[i])
					{
						// process attack number 0
						int xw = w[i] + _p[i]*t;
						int xe = e[i] + _p[i]*t;
						int xs = s[i] + _s[i]*t;
						xw *=2;
						xe*=2;
						bool kill = 0;
						for (int k = xw; k <= xe; k++)
							if (wall[shft+k] < xs)
								wall[shft+k] = xs;
						//if (kill)
							//anw++;
					}
				}
			}
		}
		printf("Case #%d: %d\n",test, anw);		

	}
		
	return 0;			
}     
