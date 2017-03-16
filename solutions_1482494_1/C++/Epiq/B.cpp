#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <numeric>
#include <utility>
#define mp make_pair
#define pb push_back
#define f(x, n) for (int (x) = 0; (x) < (n); (x)++)
#define Max 1000
#define Inf 1000000
using namespace std;

int T, N;
int s[Max][2];

int main()
{
	freopen("B-large.in", "r", stdin);
	freopen("B-large.out", "w", stdout);
	
	//int tcase = 3;
	
	scanf("%d", &T);
	f (test, T)
	{
		int r = 0, stars = 0;
		
		scanf("%d", &N);
		f (i, N) scanf("%d %d", &s[i][0], &s[i][1]);
		
		//if (test == tcase) f (i, N) printf("%d %d\n", s[i][0], s[i][1]);
		
		int best = 1, ind, st = 0;
		while (best > 0)
		{
			best = 0;
			int ind = -1;
			bool pr = 0;
			int st = 0;
			
			f (i, N)
			{
				if (best < 2 && stars >= s[i][1] && s[i][0] != Inf)
				{
					best = 2;
					ind = i;
				}
				else if (best <= 1 && stars >= s[i][1])
				{
					best = 1;
					ind = i;
					pr = 1;
				}
				else if (!pr && best <= 1 && stars >= s[i][0] && s[i][1] > st)
				{
					best = 1;
					ind = i;
					st = s[i][1];
				}
			}
			//cout << "? " << ind << " " << best << endl;
			if (ind != -1)
			{
				if (best == 2) s[ind][0] = s[ind][1] = Inf;
				else if (s[ind][0] == Inf) s[ind][1] = Inf;
				else s[ind][0] = Inf;
				stars += best;
				r++;
			}
		}
		
//		if (test == tcase){cout << "--> " << stars << " " << r << endl;
//		if (stars == 2 * N) printf("Case #%d: %d\n", test + 1, r);
//		else printf("Case #%d: Too Bad\n", test + 1);}
		if (stars == 2 * N) printf("Case #%d: %d\n", test + 1, r);
		else printf("Case #%d: Too Bad\n", test + 1);
	}
	
	return 0;
}
