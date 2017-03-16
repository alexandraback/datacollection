#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace std;

int n;
vector< vector<int> > seq;
vector<int> missing;
vector< vector<int> > board;
set<int> c;
int min_value, max_value;

vector<int> get_prefix(vector<int>& v, int length) {
	vector<int> prefix;
	for(int i = 0; i < length; i++) {
		prefix.push_back(v[i]);
	}
	return prefix;
}

bool fill(int row) {
	if(row == n) {
		set< vector<int> > flag;
		for(set<int>::iterator it = c.begin(); it != c.end(); it++) {
			flag.insert(seq[*it]);
		}
		for(int i = 0; i < n; i++) {
			vector<int> q;
			for(int j = 0; j < n; j++) {
				q.push_back(board[j][i]);
			}
			if(!flag.count(q)) {
				missing = q;
				break;
			}
		}
		return true;
	}

	vector<int> candidates;
	if(row == 0) {
		for(set<int>::iterator it = c.begin(); it != c.end(); it++) {
			if(seq[*it][0] == min_value) {
				candidates.push_back(*it);
			}
		}
	} else {
		map<vector<int>, int> prefix;
		for(set<int>::iterator it = c.begin(); it != c.end(); it++) {
			prefix[get_prefix(seq[*it], row + 1)]++;
		}

		for(set<int>::iterator it = c.begin(); it != c.end(); it++) {
			vector<int> p = get_prefix(seq[*it], row + 1);
			prefix[p]--;
			map<vector<int>, int> needs;
			board[row] = seq[*it];
			for(int i = 0; i < n; i++) {
				vector<int> q;
				for(int j = 0; j <= row; j++) {
					q.push_back(board[j][i]);
				}
				needs[q]++;
			}	
			int missing = 0;
			for(map<vector<int>, int>::iterator jt = needs.begin(); jt != needs.end(); jt++) {
				if(prefix[jt->first] < jt->second) {
					missing += (jt->second - prefix[jt->first]);
				}
				if(missing > 1) break;
			}

			if(missing <= 1) {
				candidates.push_back(*it);
			}

			prefix[p]++;
		}
	}

	for(vector<int>::iterator it = candidates.begin(); it != candidates.end(); it++) {
		board[row] = seq[*it];
		c.erase(*it);
		bool res = fill(row + 1);
		if(res) return true;
		c.insert(*it);
	}
	return false;
}

void solve() {
	board.clear();
	board.resize(n);
	for(int i = 0; i < n; i++) {
		board[i].resize(n);
	}

	min_value = seq[0][0];
	max_value = seq[0][n - 1];
	for(int i = 0; i < seq.size(); i++) {
		if(seq[i][0] < min_value) {
			min_value = seq[i][0];
		}
		if(seq[i][n - 1] > max_value) {
			max_value = seq[i][n - 1];
		}
	}

	c.clear();
	for(int i = 0; i < seq.size(); i++) {
		c.insert(i);
	}
	fill(0);
}

int main(int argc, char** argv) {

	int t;

	cin >> t;

	for(int i = 1; i <= t; i++) {
		cin >> n;
		seq.clear();
		seq.resize(n * 2 - 1);
		for(int j = 0; j < seq.size(); j++) {
			seq[j].resize(n);
			for(int k = 0; k < n; k++) {
				cin >> seq[j][k];
			}
		}

		solve();
		cout << "Case #" << i << ": ";
		for(int j = 0; j < n; j++) {
			cout << missing[j] << " ";
		}
		cout << endl;
	}

	return 0;
}
