#include <algorithm>
#include <bitset>
#include <cmath>
#include <complex>
#include <cstring>
#include <cstdio>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <unordered_set>
#include <valarray>
#include <vector>

using namespace std;

typedef long long ull;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pii> vpii;
typedef vector<bool> vb;


int main() {
#ifdef TESTING
	ifstream cin("input.txt");
	ofstream cout("output.txt");
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	int T, R, C, W;
	cin >> T;
	for (int caso = 1; caso <= T; caso++) {
		cin >> R >> C >> W;
		int count = (R - 1) * (C / W);
		while (C >= 2*W) {
			C -= W;
			count++;
		}
		if (C == W) count += W;
		else count += W + 1;
		cout << "Case #" << caso << ": " << count << endl;
	}

	return 0;
}
