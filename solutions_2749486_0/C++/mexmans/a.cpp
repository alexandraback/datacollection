#include<iostream>
#include<stdio.h>
#include<assert.h>
#include<string.h>
#include<time.h>
#include<stdlib.h>
#include<math.h>
#include<string>
#include<sstream>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<vector>
#include<algorithm>
#pragma comment(linker, "/STACK:16777216")
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
#define LL long long
#define bit __builtin_popcountll
#define sqr(x) (x) * (x)
using namespace std;
typedef pair<int, int> pii;
const double eps = 1e-9;
const double pi = acos(-1.0);
bool used[202][202][202];
pii p[202][202][202];
int main()
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	queue< pair<pii, int> > q;
	used[100][100][1] = true;
	q.push(mp(mp(100,100),1));
	while(!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int m = q.front().second;
		q.pop();
		if (x - m >= 0 && !used[x - m][y][m + 1]) {
			used[x - m][y][m + 1] = true;
			p[x - m][y][m + 1] = mp(x,y);
			q.push(mp(mp(x - m,y),m + 1));
		}
		if (x + m < 202 && !used[x + m][y][m + 1]) {
			used[x + m][y][m + 1] = true;
			p[x + m][y][m + 1] = mp(x,y);
			q.push(mp(mp(x + m,y),m + 1));
		}
		if (y - m >= 0 && !used[x][y - m][m + 1]) {
			used[x][y - m][m + 1] = true;
			p[x][y - m][m + 1] = mp(x,y);
			q.push(mp(mp(x,y - m),m + 1));
		}
		if (y + m < 202 && !used[x][y + m][m + 1]) {
			used[x][y + m][m + 1] = true;
			p[x][y + m][m + 1] = mp(x,y);
			q.push(mp(mp(x,y + m),m + 1));
		}
	}
	int T; cin >> T;
	for (int t = 1; t <= T; t++) {
		printf("Case #%d: ",t);
		int x,y; scanf("%d%d",&x,&y);
		x += 100;
		y += 100;
		int m;
		for (int i = 1;; i++) {
			if (used[x][y][i]) {
				m = i;
				break;
			}
		}
		string s = "";
		while(x != 100 || y != 100) {
			int xx = p[x][y][m].first;
			int yy = p[x][y][m].second;
			m--;
			if (x < xx) {
				s += "W";
			} else if (x > xx) {
				s += "E";
			}
			if (y < yy) {
				s += "S";
			} else if (y > yy) {
				s += "N";
			}
			x = xx;
			y = yy;
		}
		reverse(all(s));
		cout << s << endl;
	}
	return 0;
}
