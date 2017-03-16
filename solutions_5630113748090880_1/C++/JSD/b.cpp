#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
#include <queue>
#include <map>
#include <stack>

using namespace std;

typedef unsigned int uint;
typedef long long L; // LL
typedef pair<int, int> PII;
typedef vector<PII> VPII;
typedef vector<int> VI;
typedef vector<VI> VVI;


int n;
int height[2550];

void parse() {
	cin >> n;
	int x;
	memset(height, 0, sizeof(height));
	for (int i = 0; i < 2*n-1; i++)
		for (int j =0 ; j < n; j++){
			cin >> x;
			height[x]++;
		}
}

void solve() {
	for (int i = 0 ; i < 2500; i++)
		if (height[i] % 2 == 1)
			cout << " " << i;
	cout << endl;
}

int main() {
	int T;
	cin >> T;

	for (int i = 1; i <= T; i++){
		parse();
		cout << "Case #" << i << ":";
		solve();
	}
	return 0;
}



