#include "bits/stdc++.h"
#define puba push_back
#define mapa make_pair
#define ff first
#define ss second
#define bend(_x) (_x).begin(), (_x).end()
#define szof(_x) ((int) (_x).size())
#define TASK_NAME ""

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int MAXL = 32, MAXN = 13, MAXR = 20;

int t;
int rest[MAXL][MAXN][MAXR];
int tot_rest[MAXN][MAXR];

int main() {
	//freopen(TASK_NAME ".in", "r", stdin);
	//freopen(TASK_NAME ".out", "w", stdout);

	scanf("%d", &t);

	int n, m;
	scanf("%d%d", &n, &m);
    
    for (int i = 2; i <= 10; ++i) {
     	for (int j = 2; j < MAXR; ++j) {
     	 	rest[0][i][j] = 1;
     	 	for (int k = 1; k < MAXL; ++k) {
     	 	 	rest[k][i][j] = (rest[k - 1][i][j] * i) % j;
     	 	}
     	}
    }

    ll now = 0;

    cout << "Case #1:\n";
    while (m) {
    	assert(now < (1ll << (n - 1)));
     	memset(tot_rest, 0, sizeof tot_rest);
     	ll tmp = ((now << 1) | 1 | (1 << (n - 1)));
     	for (int i = 0; i < n; ++i) {
     	 	if (tmp & 1) {
     	 	 	for (int j = 2; j <= 10; ++j) {
     	 	 	 	for (int k = 2; k < MAXR; ++k) {
     	 	 	 	 	tot_rest[j][k] = (tot_rest[j][k] + rest[i][j][k]) % k;
     	 	 	 	}
     	 	 	}
     	 	}
     	 	tmp >>= 1;
     	}
     	bool flag = true;
     	vector<int> ans;
     	for (int i = 2; i <= 10; ++i) {
     		bool hflag = false;
     	 	for (int j = 2; j < MAXR; ++j) {
     	 	 	if (tot_rest[i][j] == 0) {
     	 	 	 	ans.puba(j);
     	 	 	 	hflag = true;
     	 	 	 	break;
     	 	 	}
     	 	}
     	 	if (!hflag) {
     	 	 	flag = false;
     	 	 	break;
     	 	}
     	}
     	if (flag) {
     	 	string b;
     	 	tmp = ((now << 1) | 1 | (1 << (n - 1)));
     	 	for (int i = 0; i < n; ++i) {
     	 	 	b += '0' + (tmp & 1);
     	 	 	tmp >>= 1;
     	 	}
     	 	reverse(bend(b));
     	 	cout << b << " ";
     	 	for (int num: ans) {
     	 	 	cout << num << " ";
     	 	}
     	 	cout << "\n";
     	 	--m;
     	}
     	++now;
    }

	return 0;
}