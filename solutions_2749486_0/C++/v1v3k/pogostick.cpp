#include <stdio.h>
#include <iostream>
#include <math.h>
#include <assert.h>
#include <vector>
#include <algorithm>
#include <utility>
#include <set>
#include <queue>
#include <string.h>
using namespace std;
typedef pair<int, int> ii;
typedef long long ll;
typedef vector<int> vi;
#define X first
#define Y second
#define all(c)	(c).begin(), (c).end()
#define sz(x)	((int) (x).size())
#define fill(c, v)	memset((c), (v), sizeof((c)))

struct step {
	int x, y, d;
	string p;
	step(int a, int b, int c, string q="") : x(a), y(b), d(c), p(q) {}
};



int main() {

	int T, X, Y;
	cin >> T;

	for(int t=1; t <= T; t++) {
		cin >> X >> Y;
		queue<step> Q;
		Q.push(step(0, 0, 1));
		string ans;
		set<ii> seen;


		while(!Q.empty()) {
			step curr = Q.front();
			Q.pop();
			if (seen.find(ii(curr.x, curr.y)) != seen.end()) {
				continue;
			}
			seen.insert(ii(curr.x, curr.y));

			if (curr.x == X && curr.y == Y) {
				ans = curr.p;
				break;
			}
			Q.push(step(curr.x, curr.y + curr.d, curr.d+1, curr.p + "N"));
			Q.push(step(curr.x + curr.d, curr.y, curr.d+1, curr.p + "E"));
			Q.push(step(curr.x, curr.y - curr.d, curr.d+1, curr.p + "S"));
			Q.push(step(curr.x - curr.d, curr.y, curr.d+1, curr.p + "W"));
		}
		cout << "Case #" << t << ": " << ans << endl;

	}
	return 0;
}