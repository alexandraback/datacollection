#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <climits>
#include <algorithm>
using namespace std;

#define ll long long;

int main() {

	ifstream cin("in.in");
	ofstream cout("out.txt");
	int T;
	cin >> T;
	for (int idx = 1; idx <= T; idx++) {
		int R, C, W;
		cin >> R >> C >> W;
		int ans;
		if (W == C) ans = R - 1 + W;
		else if (W > C / 2) ans = R + W;
		else {
			ans = (R)*(C / W); //guarantee hit in min number of moves
			ans += (W - 1); //sink the ship
			int right = C - (C / W)*W;
			if (right > 0) ans++;
		}
		cout << "Case #" << idx << ": " << ans << endl;
	}
	return 0;
}