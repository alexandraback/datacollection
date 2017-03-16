#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <bitset>

using namespace std;

typedef pair<int,int> ii;
typedef vector<int> vi;
#define REP(i, a, b) for(int i = int(a); i <= int(b); i++)
#define LOOP(i, v) for(int i = 0; i < v.size(); i++)
#define EPS 1e-9
#define INF 1e12
#define debug(x) cerr << "DEBUG : " << (#x) << " => " << (x) << endl

int main()
{
	int T;
	int N;
	
	scanf("%d\n", &T);
	
	REP(t, 1, T)
	{
		fprintf(stderr, "Cas %d\n", t);
		printf("Case #%d: ", t);
		
		scanf("%d", &N);
		
		vi a, bypair;
		a.resize(N+1);
		bypair.resize(N+1);
		REP(i, 1, N) scanf("%d", &a[i]);
		REP(i, 1, N)
		{
			if(a[a[i]] == i) bypair[i] = true;
			else bypair[i] = false;
		}
		int best = 0;
		vi bestqueue(N+1);
		REP(i, 1, N) bestqueue[i] = 0;
		REP(i, 1, N)
		{
			if(!bypair[i])
			{
				vi place(N+1);
				REP(j, 1, N) place[j] = -1;
				place[i] = 1;
				int encours = i;
				int p = 1;
				while(true)
				{
					p++;
					encours = a[encours];
					if(place[encours] >= 0)
					{
						int poss = p-place[encours];
						best = max(best, poss);
						break;
					}
					else if(bypair[encours])
					{
						int poss = p-1;
						bestqueue[encours] = max(bestqueue[encours], poss);
						break;
					}
					else place[encours] = p;
				}
			}
		}
		int tot = 0;
		REP(i, 1, N)
		{
			//fprintf(stderr, "%d : %d (%d)\n", i, bypair[i], bestqueue[i]);
			if(i < a[i] && bypair[i])
			{
				tot += 2 + bestqueue[i] + bestqueue[a[i]];
			}
		}
		best = max(best, tot);
		//fprintf(stderr, "--> %d\n", best);
		printf("%d\n", best);
	}

  return 0;
}
