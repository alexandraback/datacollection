#include <iostream>
#include <vector>
using namespace std;
int n,m;
vector<vector<int> > f;

bool check(int pi, int pj) {
	bool same_or_less = true;
	for (int i = 0; i < n; i++)
		if (f[i][pj] > f[pi][pj]) {
			same_or_less = false;
			break;
		}
	if (same_or_less) return true;
	for (int j = 0; j < m; j++)
		if (f[pi][j] > f[pi][pj])
			return false;
	return true;
}

void test(int tn) {
	cout << "Case #" << tn << ": ";
	cin >> n >> m;
//	cout << "n = " << n << " m = " << m;
	f.resize(n);
	for (int i = 0; i < n; i++) {
		f[i].resize(m);
		for (int j = 0; j < m; j++)
			cin >> f[i][j];
	}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if(!check(i,j)) {
				cout << "NO\n";
				return;
			}
	cout << "YES\n";
}

int main() {
	int tc;
	cin >> tc;
	for (int i = 0; i < tc; i++)
		test(i+1);
}
