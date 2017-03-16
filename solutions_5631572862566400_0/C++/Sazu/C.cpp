#include <bits/stdc++.h>

#define debug(x) cout << #x << " = " << x << endl
#define fori(i, ini, lim) for(int i = int(ini); i < int(lim); i++)
#define ford(i, ini, lim) for(int i = int(ini); i >= int(lim); i--)

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;

int bff[15];
int n;
bool check(vector<int> &v) {
	fori(i, 0, v.size()) {
		int lft = (i == 0) ? (int) v.size() - 1 : i - 1;
		int rgt = (i == ((int) v.size() - 1)) ? 0 : i + 1;
		if(v[lft] != bff[v[i]] && v[rgt] != bff[v[i]]) {
			return false;
		}
	}
	return true;
}

int ANS = 0;
vector<int> current;

void roll(int mask) {
	if(check(current)) {
		ANS = max(ANS, (int) current.size());
	}
	if((int) current.size() == n) {
		return;
	}
	fori(i, 1, n + 1) {
		if(!(mask & (1 << i))) {
			current.push_back(i);
			roll(mask | (1 << i));
			mask &= ~(1 << i);
			current.pop_back();
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);

	int kase = 1;
	int t;
	cin >> t;
	while(t--) {
		cin >> n;

		fori(i, 1, n + 1) {
			cin >> bff[i];
		}

		ANS = 0;
		roll(0);
		cout << "Case #" << kase++ << ": ";
		cout << ANS << '\n';
	}
	return 0;
}
