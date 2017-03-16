// Problem A

#include <iostream>
#include <stdio.h>
#include <fstream>
#include <iomanip>
#include <cassert>
#include <vector>
#include <algorithm>
#include <set>
#include <string.h>
#include <map>
#include <queue>
#include <stack>

#define pb push_back
#define mp make_pair

using namespace std;

typedef long long int ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef set<int> si;
typedef vector<ii> vii;

int R, C, W;

void solve() {
	cin >> R >> C >> W;
	int sol = (R-1)*(C/W) + ((C+W-1)/W) + W - 1;
	cout << sol << endl;
}

int main() {
	int T;
	cin >> T;
	for (int t=1; t<=T; t++) {
		cout << "Case #" << t << ": ";
		solve();
	}
	
	return 0;
}
