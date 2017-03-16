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
const int MAXL = 105;

int n;
char s[MAXL];
int d[2][MAXL];

int main() {
	//freopen(TASK_NAME ".in", "r", stdin);
	//freopen(TASK_NAME ".out", "w", stdout);

	scanf("%d", &n);

	for (int i = 0; i < n; ++i) {
	 	scanf("%s", s);
	 	int l = strlen(s);
	 	d[0][0] = (s[0] != '+');
	 	d[1][0] = (s[0] != '-');
	 	for (int j = 1; j < l; ++j) {
	 	 	if (s[j] == '-') {
	 	 	 	d[0][j] = d[1][j - 1] + 1;
	 	 	 	d[1][j] = d[1][j - 1];
	 	 	} else {
	 	 	 	d[0][j] = d[0][j - 1];
	 	 	 	d[1][j] = d[0][j - 1] + 1;
	 	 	}
	 	 	//cerr << d[0][j] << " " << d[1][j] << endl;
	 	}
	 	cout << "Case #" << i + 1 << ": " << d[0][l - 1] << "\n";
	}

	return 0;
}