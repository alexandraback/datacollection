#include "sstream"
#include "iostream"
#include "cstdio"
#include "cstring"
#include "cmath"
#include "algorithm"
#include "vector"
#include "map"
#include "set"
#include "queue"
#include "deque"
#include "list"
#include "string"
#include "cassert"

using namespace std;

typedef pair<int, int> pii;

map<pii, pii> mp;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};

void dfs(int x, int y, int lx, int ly, int d)
{
	if (d > 200) {
		return;
	}
	map<pii,pii>::iterator it = mp.find(pii(x, y));
	if (it != mp.end()) {
		return;
	}
	mp[pii(x, y)] = pii(lx, ly);
	for (int k = 0; k < 4; k++) {
		int xx = x + dx[k] * d;
		int yy = y + dy[k] * d;
		if (abs(x) > 100 || abs(y) > 100) {
			continue;
		}
		dfs(xx, yy, x, y, d + 1);
	}
}

void bfs()
{
	pii s(0, 0);
	mp[s] = s;
	queue<pair<pii, int> > Q;
	Q.push(pair<pii, int>(s, 1));
	while (!Q.empty()) {
		pii s = Q.front().first;
		int d = Q.front().second;
		Q.pop();
		if (d > 500) {
			continue;
		}
		int x = s.first, y = s.second;
		for (int k = 0; k < 4; k++) {
			int xx = x + dx[k] * d;
			int yy = y + dy[k] * d;
			pii t = pii(xx, yy);
			if (abs(x) > 500 || abs(y) > 500 || t != pii(0, 0) && mp.count(t)) {
				continue;
			}	
			mp[t] = s;
			Q.push(pair<pii, int>(t, d+1));
		}
	}
}

void init()
{
	//dfs(0, 0, 0, 0, 1);
	bfs();
}

void print(int x, int y)
{
	if (x == 0 && y == 0) {
		return;
	}
	//cout<<x<<" "<<y<<endl;
	pii last = mp[pii(x, y)];
	print(last.first, last.second);
	if (last.first > x) {
		putchar('W');
	} 
	if (last.first < x) {
		putchar('E');
	} 
	if (last.second > y) {
		putchar('S');
	} 
	if (last.second < y) {
		putchar('N');
	} 
}

int main()
{
	init();
	int T, t = 1;
	for (scanf("%d", &T); T--; ) {
		printf("Case #%d: ", t++);
		int x, y;
		scanf("%d%d", &x, &y);
		print(x, y);	
		puts("");
	}
	return 0;
}

