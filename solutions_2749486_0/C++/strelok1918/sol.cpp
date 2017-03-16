#include <cstdio>
#include <vector>
#include <set>
#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <map>
#include <set>
using namespace std;
 
#define mp make_pair
#define X first
#define Y second
#define pb push_back
#define sz size()
#define sqr(x) (x) * (x)
#define all(x) (x).begin(), (x).end()




int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
char dest[] = {'W', 'N', 'E', 'S'};

string go(pair<int,int> to) {
	set<pair<int,int> > u;
	map<pair<int,int>, string > path;
	map<pair<int,int>, int> pt;
	pair<int,int> from = mp(0, 0), now;
	queue<pair<int,int> > q;
	int xn, yn, len;
	char p;
	q.push(from);
	pt[from] = 0;
	while(!q.empty()) {
		now = q.front();
		
		q.pop();
		if(now == to) return path[now];
		for(int i = 0; i < 4; i++) {
			len = pt[now] + 1;
			xn = now.X + dx[i] * len;
			yn = now.Y + dy[i] * len;
			if(u.count(mp(xn, yn))) continue;
			p = dest[i];
			path[mp(xn, yn)] = path[now] + p;
			q.push(mp(xn, yn));
			pt[mp(xn, yn)] = len ;
			u.insert(mp(xn, yn));
			if(to == mp(xn, yn)) return path[to];
		}
	}
}

void solve() {
	int x, y;
	scanf("%d%d", &x, &y);
	puts(go(mp(x, y)).c_str());
}
void OJ() {
    int t;
    scanf("%d", &t);
    for(int i = 1; i <= t; i++) {
		printf("Case #%d: ", i);
        solve();
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    OJ();
    //solve();
    return 0;
}