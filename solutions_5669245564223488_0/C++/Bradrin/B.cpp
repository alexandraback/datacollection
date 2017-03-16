#include <cstdio>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> trains;
vector<bool> done;
vector<int> sizes;
int n;

vector<char> ordering;

void read() {
	cin >> n;
	string next;
	trains.clear();
	for (int i = 0; i < n; i++) {
		cin >> next;
		trains.push_back(next);
	}
}

bool allDone() {
	for (int i = 0; i < n; i++) {
		if (done[i] == false) {
			return false;
		}
	}
	return true;
}

long fact(int n) {
	long total = 1;
	while (n > 0) {
		total *= n;
		n %= 1000000007;
		n--;
	}
	return total;
}

void solve() {
	done.clear();
	for (int i = 0; i < n; i++) {
		done.push_back(false);
	}
	//done[0] = true;
	int sets = 0;
	sizes.clear();
	sizes.push_back(0);
	char last = trains[0][trains[0].length()-1];
	int cur = 0;
	bool failed = true;
	for (int i = 0; i < n; i++) {
		for (int j = 1; j < trains[i].length()-1; j++) {
			for (int k = 0; k < n; k++) {
				if (i == k) continue;
				for (int l = 0; l < trains[k].length(); l++) {
					if (trains[i][j] == trains[k][l]) {
						bool fail = false;
						for (int m = 0; m < j; m++) {
							if (trains[i][m] != trains[i][j]) {
								fail = true;
								break;
							}
						}
						for (int m = l; m < trains[k].length(); m++) {
							if (trains[k][m] != trains[k][l]) {
								fail = true;
								break;
							}
						}
						if (!fail) {
							continue;
						}
						fail = false;
						for (int m = j; m < trains[i].length(); m++) {
							if (trains[i][m] != trains[i][j]) {
								fail = true;
								break;
							}
						}
						for (int m = 0; m < l; m++) {
							if (trains[k][m] != trains[k][l]) {
								fail = true;
								break;
							}
						}
						if (fail) {
							cout << 0 << endl;
							return;
						}
					}
				}
			}
		}
	}
	while (!allDone()) {
		failed = true;
		for (int i = 0; i < n; i++) {
			if (!done[i]) {
				bool allSame = true;
				for (int j = 0; j < trains[i].length(); j++) {
					if (trains[i][j] != last) {
						allSame = false;
						break;
					}
				}
				if (allSame) {
					cur = i;
					sizes[sizes.size()-1]++;
					done[i] = true;
				}
			}
		}
		sizes.push_back(0);
		for (int i = 0; i < n; i++) {
			if (!done[i] && trains[i][0] == last) {
				cur = i;
				done[i] = true;
				vector<char> b;
				for (int j = 1; j < trains[i].length()-1; j++) {
					if (trains[i][j] != last) {
						b.push_back(trains[i][j]);
					}
				}
				for (int j = 0; j < n; j++) {
					if (i == j) continue;
					for (int k = 0; k < trains[j].length(); k++) {
						for (int l = 0; l < b.size(); l++) {
							if (trains[j][k] == b[l]) {
								cout << 0 << endl;
								return;
							}
						}
					}
				}
				last = trains[i][trains[i].size()-1];
				failed = false;
				break;
			}
		}
		if (failed) {
			sets++;
			for (int i = 0; i < n; i++) {
				if (!done[i]) {
					cur = i;
					last = trains[i][trains[i].length()-1];
					done[i] = true;
					break;
				}
			}
		}
	}
	long ans = fact(sets);
	for (int i = 0; i < sizes.size(); i++) {
		ans *= fact(sizes[i]);
	}
	ans %= 1000000007;
	cout << ans << endl;
}

int main() {
    freopen("inputB.in", "r", stdin);
	freopen("outputB.txt", "w", stdout);
	
    int cases;
    cin >> cases;
    for (int count = 1; count <= cases; count++) {
		read();
        cout << "Case #" << count << ": ";
		solve();
    }
    return 0;
}