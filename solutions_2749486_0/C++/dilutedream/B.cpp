#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <set>

#define all(x) x.begin (), x.end ()
#define size(x) (int)x.size ()
#define pb push_back

#define mp make_pair

using namespace std;

const int MAXN = 201;

const int dx [] = {1, -1, 0, 0};
const int dy [] = {0, 0, 1, -1};
const char c [] = {'E', 'W', 'N', 'S'};

typedef pair<int, int> pint;
typedef pair<pint, int> ppint;
typedef vector<int> vint;

set<ppint> ex;
map<ppint, int> dr;
map<ppint, ppint> pr;
queue<ppint> q;

inline ppint M (int x, int y, int step) { return mp (mp (x, y), step); }

inline void BFS (int x1, int y1, int x2, int y2) {
	while (!q.empty ()) q.pop (); ex.clear (), dr.clear ();
	
	q.push (M (x1, y1, 0)), ex.insert (M (x1, y1, 0));
	
	while (!q.empty ()) {
		int x = q.front ().first.first, y = q.front ().first.second, step = q.front ().second; q.pop ();
		
		if (x == x2 && y == y2) {
			vint sol; sol.clear ();
			while (x != x1 || y != y1 || step != 0) {
				sol.pb (dr [M (x, y, step)]);
				
				ppint S = pr [M (x, y, step)];
				
				x = S.first.first, y = S.first.second, step = S.second;
			}
			
			for (int i = size (sol) - 1; i >= 0; --i)
				printf ("%c", c [sol [i]]);
			
			printf ("\n");
			
			return;
		}
		
		step++; if (step > 500) continue;
		for (int i = 0; i < 4; ++i) {
			int nx = x + step * dx [i], ny = y + step * dy [i];
			
			if (!ex.count (M (nx, ny, step))) {
				ex.insert (M (nx, ny, step));
				
				dr [M (nx, ny, step)] = i, pr [M (nx, ny, step)] = M (x, y, step - 1);
				
				q.push (M (nx, ny, step));
			}
		}
	}
}

int main () {
	freopen ("B.in", "r", stdin);
	freopen ("B.out", "w", stdout);
	
	int task; scanf ("%d\n", &task);
	for (int T = 1; T <= task; ++T) {
		int x, y; scanf ("%d %d\n", &x, &y);
		
		printf ("Case #%d: ", T);
		
		BFS (0, 0, x, y);
	}
	
	fclose (stdin);
	fclose (stdout);
	return 0;
}
