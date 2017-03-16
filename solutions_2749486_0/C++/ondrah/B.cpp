#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <utility>
#include <vector>

#define FOR(I,A,B)	for(int I = (A); I < (B); ++I)
#define REP(I,N)	FOR(I,0,N)
#define ALL(A)		(A).begin(), (A).end()

using namespace std;

typedef struct
{
	long long X, Y;
	int t;
	string path;
} st;

int d[4][2] = {{0,1},{1,0},{-1,0},{0,-1}};
char DD[4] = {'N', 'E', 'W', 'S'};
map< pair<int, int>, bool > visited;

int main()
{
	int currTest,T;
	scanf("%d", &T);
	REP(currTest, T) {
		visited.clear();
		int X, Y;
		scanf("%d %d", &X, &Y);
		queue<st> q;
		q.push((st){0,0,1,""});
		bool found = false;
		int ans = 0;
		string res;
		while(!q.empty() && !found) {
			st curr = q.front();
			q.pop();
			
			REP(i, 4) {
				int nX = curr.X + d[i][0]*curr.t, nY = curr.Y + d[i][1]*curr.t;
				if(visited.find(make_pair(nX, nY)) != visited.end()) continue;
				visited[make_pair(nX, nY)] = true;
				if(nX == X && nY == Y) {
					found = true;
					ans = curr.t;
					res = curr.path+DD[i];
					break;
				}
				q.push((st){nX, nY, curr.t+1, curr.path + DD[i]});
			}
		}

		printf("Case #%d: %s\n", currTest+1, res.c_str());
	}
	return 0;
}
