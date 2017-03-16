#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

#define fi first
#define se second

typedef pair<int,int> pii;

vector<int> F;

bool visited[1100];
bool involved_loop[1100];
int attached_len[1100];

int detect_loop(int cur, int start, int len) {
	if(visited[cur]) {
		if(cur == start) return len;
		return 0;
	}
	visited[cur] = true;
	return detect_loop(F[cur], start, len+1);
}

pii attached(int cur, int len) {
	if(involved_loop[cur])
		return pii(len, cur);
	return attached(F[cur], len+1);
}

int main() {
	int T;
	cin >> T;
	for(int t = 1; t <= T; t++) {
		int N;
		int ans = 0;
		vector<pii> v;

		cin >> N;
		F.resize(N);
		for(int i = 0; i < N; i++) {
			cin >> F[i];
			F[i]--;
		}

		for(int i = 0; i < 1100; i++) {
			involved_loop[i] = false;
			attached_len[i] = 0;
		}

		for(int i = 0; i < N; i++) {
			for(int j = 0; j < 1100; j++)
				visited[j] = false;
			int tmp;
			tmp = detect_loop(i, i, 0);
			ans = max(ans, tmp);
			if(tmp) {
				if(tmp == 2 && i < F[i]) {
					v.push_back(pii(i,F[i]));
				}
				for(int j = 0; j < 1100; j++)
					involved_loop[j] = involved_loop[j] || visited[j];
			}
		}

		for(int i = 0; i < N; i++) {
			pii tmp;
			tmp = attached(i, 0);
			attached_len[tmp.se] = max(attached_len[tmp.se], tmp.fi);
		}

		int sum = 0;
		for(int i = 0; i < v.size(); i++) {
			sum += 2 + attached_len[v[i].fi] + attached_len[v[i].se];
		}
		ans = max(ans, sum);

		cout << "Case #" << t << ": " << ans << endl;
	}
}
