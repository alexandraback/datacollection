#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <queue>
#include <algorithm>
#include <stack>

using namespace std;

struct Tribe {
	int first;
	int num;
	int w, e;
	int s;
	int dd;
	int dp;
	int ds;
};

int main() {
	int T;
	cin >> T;

	Tribe tribes[10];
	int	next[10];
	int	offset = 200;

	for (int t = 1; t <= T; t++) {
		int N;
		cin >> N;

		int	wall[400] = {0};

		for (int n = 0; n < N; n++)
			cin >> tribes[n].first >> tribes[n].num >> tribes[n].w >> tribes[n].e >> tribes[n].s >> tribes[n].dd >> tribes[n].dp >> tribes[n].ds;

		for (int n = 0; n < N; n++)
			next[n] = tribes[n].first;

		int success = 0;

		while (true) {
			int nextd = 1e9;

			bool attacks = false;
			for (int n = 0; n < N; n++) {
				if (tribes[n].num > 0) {
					attacks = true;
					if (next[n] < nextd) nextd = next[n];
				}
			}

			if (!attacks) break;

			//cout << "Start of day " << nextd << endl;

			for (int n = 0; n < N; n++) {
				const Tribe& tr = tribes[n];

				if (nextd != next[n]) continue;
				if (tr.num == 0) continue;

				//cout << "Tribe " << n << " attacks" << endl;

				for (int i = tr.w; i < tr.e; i++)
					if (wall[i+offset] < tr.s) {
						success++;
						//cout << " and succeeds" << endl;
						break;
					}
			}

			attacks = false;
			for (int n = 0; n < N; n++) {
				Tribe& tr = tribes[n];

				if (nextd != next[n]) continue;
				if (tr.num == 0) continue;

				for (int i = tr.w; i < tr.e; i++)
					if (wall[i+offset] < tr.s)
						wall[i+offset] = tr.s;

				tr.num--;
				tr.s += tr.ds;
				tr.w += tr.dp;
				tr.e += tr.dp;
				next[n] += tr.dd;
			}
		}

		cout << "Case #" << t << ": " << success << endl;
	}
}
