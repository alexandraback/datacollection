#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstdlib>
#include <map>
#include <queue>

using namespace std;

typedef struct {
	int d;
	int n;
	int w;
	int e;
	int s;
	int d_d;
	int d_p;
	int d_s;
} Tribe;

bool operator < (const Tribe &a, const Tribe &b) {
	return a.d > b.d;
}

#define MAX_P 10000

int h[2*MAX_P + 1];

typedef struct {
	int w;
	int e;
	int s;
} Work;

vector <Work> works;
vector <Work> walls;
void add_work (const Work &a) {
	works.push_back (a);
}

void commit () {
	for (int i=0; i<works.size(); i++) {
		walls.push_back (works[i]);
	}
	works.clear();
}

bool check (double p, int s) {
	for (int i=0; i<walls.size(); i++) {
		if (walls[i].w<=p && walls[i].e>=p && walls[i].s>=s)
			return true;
	}
	return false;
}


bool success(const Tribe &t) {
	for (double i=t.w; i<=t.e; i+=0.5) {
		if (!check(i, t.s))
			return true;
	}
	return false;
}

void solve(int testcase) {
	cout << "Case #" << testcase << ": ";
	
	int n;
	cin >> n;

	priority_queue<Tribe> que;

	walls.clear();

	for (int i=0; i<n; i++) {
		Tribe t;
		cin >> t.d >> t.n >> t.w >> t.e >> t.s >> t.d_d >> t.d_p >> t.d_s;
		que.push (t);
	}

	int curr_d = -1;
	int count = 0;

	works.clear();

	while (!que.empty()) {
		Tribe now = que.top();
		que.pop();
		if (curr_d != now.d) {
			commit();
			curr_d = now.d;
		}

		if (success(now)) {
			count++;
			Work w;
			w.w = now.w;
			w.e = now.e;
			w.s = now.s;
			add_work (w);
		}

		now.n--;
		if (now.n<=0)
			continue;
		now.d += now.d_d;
		now.w += now.d_p;
		now.e += now.d_p;
		now.s += now.d_s;
		que.push (now);
	}
	
	cout << count;
	cout << endl;
}

int main () {
	int testcases;

	cin >> testcases; 

	for (int testcase=1; testcase<=testcases; testcase++) {
		solve(testcase);
	}
	return 0;
}
