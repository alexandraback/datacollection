#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair

#define eps 0.0000001
#define pi  3.14159265359
#define inf 2000000000

typedef long long lld;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;

struct node {
	int x, y, z;
	node(int x, int y, int z) : x(x), y(y), z(z) {}

	void print() {
		cout << x << " " << y << " " << z << endl;
	}
};

int cnt[3][15][15];
vector<node> sol;

int main() {
	int tt, n, nn, nnn, limit;
	cin >> tt;
	for (int t = 1; t <= tt; t++) {
		cin >> n >> nn >> nnn >> limit;
		for (int i = 0; i < 3; i++)
			for (int j = 1; j <= nnn; j++)
				for (int k = 1; k <= nnn; k++) cnt[i][j][k] = 0;
		sol.clear();
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= nn; j++)
				for (int k = 1; k <= nnn; k++) {
					if (cnt[0][i][j] < limit && cnt[1][j][k] < limit && cnt[2][i][k] < limit) {
						sol.push_back(node(i, j, k));
						cnt[0][i][j]++;
						cnt[1][j][k]++;
						cnt[2][i][k]++;
					}
				}
		cout << "Case #" << t << ": " << sol.size() << endl;
		for (int i = 0; i < sol.size(); i++) sol[i].print();
	}    
    return 0;
}
