#include <bits/stdc++.h>

using namespace std;
//Test 50 100000000000000

using ull = unsigned long long;

int main(int argc, char *argv[])
{
	int T;
	cin >> T;

	for(int t = 1; t <= T; t++) {
		ull B, M;
		cin >> B >> M;

		ull max_comb = (1ull << (B - 2));

		//Find connections for 1
		vector<int> connectTo;
		ull currM = M;
		for(unsigned n = 2; n < B; n++) {
			if(B - n - 1 < 0) continue;
			ull val = 1ull << (B - n - 1);
			if(val <= currM) {
				currM -= val;
				connectTo.push_back(n);
				if(currM == 0) break;
			}
		}
		if(currM) {
			connectTo.push_back(B);
			currM--;
		}

		if(currM != 0) {
			cout << "Case #" << t << ": IMPOSSIBLE\n";
			continue;
		}
		cout << "Case #" << t << ": POSSIBLE\n";
		//Row 1
		int conn_i = 0;
		for(int j = 1; j <= B; j++) {
			if(j == connectTo[conn_i]) {
				cout << 1;
				conn_i++;
				if(conn_i >= connectTo.size()) conn_i = 0;
			}
			else {
				cout << 0;
			}
		}
		cout << "\n";
		//Rows 2 - B
		int maxN = connectTo[0];
		for(int i = 2; i <= B; i++) {
			for(int j = 1; j <=B; j++) {
				if(i < maxN) cout << 0;
				else {
					if(j > i) cout << 1;
					else cout << 0;
				}
			}
			cout << "\n";
		}
	}

	return 0;
}
