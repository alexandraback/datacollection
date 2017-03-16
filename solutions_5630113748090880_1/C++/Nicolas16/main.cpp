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
	vector<vector<int> > a;
	
	scanf("%d\n", &T);
	
	REP(t, 1, T)
	{
		fprintf(stderr, "Cas %d\n", t);
		printf("Case #%d: ", t);
		
		scanf("%d", &N);
		
		a.resize(2*N-1);
		
		vector<bool> still;
		still.resize(2*N-1);
		
		REP(i, 0, 2*N-2)
		{
			still[i] = true;
			a[i].resize(N);
			REP(j, 0, N-1)
			{
				scanf("%d", &a[i][j]);
			}
		}
		
		REP(i, 0, N-1)
		{
			vi b;
			REP(j, 0, 2*N-2)
			{
				if(still[j])
				{
					b.push_back(a[j][i]);
				}
			}
			debug(b.size());
			sort(b.begin(), b.end());
			if(b.size() == 1 || b[0] != b[1])
			{
				printf("%d ", b[0]);
				int x;
				REP(j, 0, 2*N-2)
				{
					if(still[j] && a[j][i] == b[0])
					{
						x = j;
					}
				}
				debug(x);
				vi c;
				REP(j, i+1, N-1) c.push_back(a[x][j]);
				int g = 0;
				REP(j, 1, b.size()-1)
				{
					if(g == c.size() || c[g] != b[j])
					{
						printf("%d ", b[j]);
					}
					else g++;
				}
				still[x] = false;
				break;
			}
			else
			{
				int x = -1, y = -1;
				REP(j, 0, 2*N-2)
				{
					if(still[j] && a[j][i] == b[0])
					{
						if(x == -1) x = j;
						else y = j;
					}
				}
				vi c;
				REP(j, i+1, N-1) c.push_back(a[x][j]);
				REP(j, i+1, N-1) c.push_back(a[y][j]);
				sort(c.begin(), c.end());
				REP(j, 0, c.size()-1)
				{
					if(j == c.size()-1 || c[j] != b[j+2])
					{
						printf("%d ", c[j]);
						break;
					}
				}
				still[x] = false;
				still[y] = false;
			}
		}
		printf("\n");
	}

  return 0;
}
