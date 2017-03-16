#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <bitset>


using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int N;

vi best;
vi visited;
vvi friends;
bool done[1001][1001];

bool check(vi& circle) {
	int k = (int) circle.size();

	for (int i = 0; i < k; i++) {
		if (!(best[circle[i]] == circle[(i+1) % k] || best[circle[i]] == circle[(i+k-1) % k])) {
			return false;
		}
	}

	return true;
}

int rec(vi& circle) {
	int k = (int) circle.size();
	int last = circle[k-1];
	int start =  circle[0];

	int r1 = -1;

	//if (done[circle[k-2]][last]) return -1;

	//done[circle[k-2]][last] = true;

	if (check(circle)) {
		r1 = k;
		for (int i = 0; i < k; i++) {
			cout << circle[i] << " ";
		}
		cout << endl;
	}

	if (best[last] == circle[k-2]) {
		for (int i = 1; i <= N; i++) {
			if (!visited[i]) {
				visited[i] = true;
				circle.push_back(i);
				r1 = max(r1, rec(circle));
				circle.pop_back();
				visited[i] = false;
			}
		}
	} else {
		if (!visited[best[last]]) {
			int i = best[last];
			visited[i] = true;
			circle.push_back(i);
			r1 = max(r1, rec(circle));
			circle.pop_back();
			visited[i] = false;

		} 
	}

	return r1;
	/*
	if (last == start) {
		return s;
	}

	int r1 = -1;
	if (best[last] == start) r1 = s;

	for (f : friends[last]) {
		if (!visited[f]) {
			// left is BFF
			visited[f] =  true;
			r1 = max (r1, rec(start, f, s+1));
			visitd[f] = false;
		}
	}

	if (!visited[best[last]]) {
		visited[best[last]] = true;
		max(r1, rec(start, best[last], s+1));
		visited[best[last]] = false;
	}

	return r1;
	*/
}


int main() {
	ifstream in ("in.txt");
	ofstream out ("out.txt");

	int T; in >> T;

	for (int i = 1; i <= T; i++) {
		in >> N;
		cout << "Case " << i << endl;
		best.assign(N+1, 0);
		friends.assign(N+1, vi());

		for (int j = 1; j <= N; j++) {
			int u;
			in >> u;
			best[j] = u;
			friends[u].push_back(j);
		}

		//fill(&done[0][0], 1001*1001, false);
		//memset(done, sizeof done, 0);

		int res = 1;
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (i != j) {
					visited.assign(N+1, false);
					visited[i] = true;
					visited[j] = true;
					vi circle = vi();
					circle.push_back(i);
					circle.push_back(j);

					res = max(res, rec(circle));
				}
			}
		}

		out << "Case #" << i << ": " << res << endl;
	}

	return 0;
} 