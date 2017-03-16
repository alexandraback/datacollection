#include <iostream>
#include <fstream>
#include <cmath>
#include <cstdlib>
#include <map>
#include <set>
#include <vector>
#include <cstring>
#include <string>
#include <algorithm>
#include <queue>
#include <cassert>

using namespace std;

vector <string> dict;

void read_dict() {
	ifstream din("dict.txt");
	while (din) {
		string s;
		din >> s;
		dict.push_back(s);
	}
}

const int nmax = 5000;
int n;
int t[nmax][6]; 
const int inf = 1e9;

void solve(int tn) {
	string s;
	cin >> s;
	n = s.size();
	for (int i = 0; i <= n; i ++) {
		for (int j = 0; j < 5; j ++) {
			t[i][j] = inf;
		}
	}
	t[0][4] = 0;
	for (int i = 0; i < n; i ++) {
		for (int j = 0; j < 5; j ++) {
			if (t[i][j] < inf) {
				for (int k = 0; k < dict.size(); k ++) {
					int cur = t[i][j];
					const string& w = dict[k];
					int pos = i - 1 - j;
					for (int l = 0; l < w.size(); l ++) {
						if (w[l] != s[i + l]) {
							if (i + l - pos < 5) {
								cur = inf;
							} else {
								cur ++;
							}
							pos = i + l;
						}
					}
					int newj = min(4, i + (int) w.size() - 1 - pos);
					t[i + w.size()][newj] = min(t[i + w.size()][newj], cur);
				}	
			}
		}
	}
	int answer = inf;
	for (int i = 0; i < 5; i ++) {
		answer = min(answer, t[n][i]);
	}
	cout << "Case #" << tn << ": " << answer << endl;
}

int main()
{
	read_dict();
	int t;
	cin >> t;
	for (int i = 0; i < t; i ++) {
		solve(i + 1);
	}
	return 0;
}
