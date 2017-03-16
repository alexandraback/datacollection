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

int n;

int main() {
	//freopen(TASK_NAME ".in", "r", stdin);
	//freopen(TASK_NAME ".out", "w", stdout);

	scanf("%d", &n);

	for (int i = 0; i < n; ++i) {
	 	int num;
	 	scanf("%d", &num);
	 	int have[10];
	 	memset(have, 0, sizeof have);
	 	bool flag = false;
	 	int c = 0;
	 	for (int j = 0; j < 1000; ++j) {
	 	 	int now = num * (j + 1);
	 	 	while (now) {
	 	 	 	c += !have[now % 10];
	 	 	 	have[now % 10] = true;
	 	 	 	now /= 10;
	 	 	}
	 	 	if (c == 10) {
	 	 	 	cout << "Case #" << i + 1 << ": " << num * (j + 1) << "\n";
	 	 	 	flag = true;
	 	 	 	break;
	 	 	}
	 	}
	 	
	 	if (!flag) {
	 	 	cout << "Case #" << i + 1 << ": INSOMNIA\n";
	 	}
	}

	return 0;
}