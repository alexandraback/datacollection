#include <cmath>
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <unordered_set>
#include <utility>
#include <bitset>
using namespace std;

fstream in, out;

int t;
int k, n;

vector<int> keys;
vector<int> key_needed;
vector<vector<pair<int, int> > > keys_held;
unsigned int open;

vector<int> sequence;

unordered_set<int> seen;

bool search(int num_open, int first) {
	if (num_open > 18) {
		cout << num_open << endl;
	}
	if (num_open == n) {
		return true;
	} else if (seen.count(open) > 0) {
		return false;
	}
	for (int i = first; i < n; i++) {
		if ((open & (1 << i)) == 0 && keys[key_needed[i]] > 0) {
			keys[key_needed[i]]--;
			open |= 1 << i;
			for (int j = 0; j < keys_held[i].size(); j++) {
				keys[keys_held[i][j].first] += keys_held[i][j].second;
			}
			sequence[num_open] = i;
			int next;
			if (i > first) {
				next = first;
			} else {
				for (int j = first + 1; j < n; j++) {
					if ((open & (1 << j)) == 0) {
						next = j;
						break;
					}
				}
			}
			if (search(num_open + 1, next)) {
				return true;
			}
			keys[key_needed[i]]++;
			open ^= 1 << i;
			for (int j = 0; j < keys_held[i].size(); j++) {
				keys[keys_held[i][j].first] -= keys_held[i][j].second;
			}
		}
	}
	seen.insert(open);
	return false;	
}

int main() {
	in.open("D-small-attempt3.in", fstream::in);
	out.open("probd-small.out", fstream::out);

	in >> t;

    for (int i = 0; i < t; i++) {
		in >> k >> n;

		cout << i << " " << k << " " << n << endl;

		keys.clear();
		for (int j = 0; j < 201; j++) {
			keys.push_back(0);
		}

		int key;
		for (int j = 0; j < k; j++) {
			in >> key;
			keys[key]++;
		}

		int num_keys;
		key_needed.clear();
		keys_held.clear();
		open = 0;
		for (int j = 0; j < n; j++) {
			in >> key;
			key_needed.push_back(key);
			in >> num_keys;
			vector<int> keys_released;
			for (int k = 0; k < 201; k++) {
				keys_released.push_back(0);
			}
			for (int k = 0; k < num_keys; k++) {
				in >> key;
				keys_released[key]++;
			}
			vector<pair<int, int> > asdf;
			for (int k = 0; k < 201; k++) {
				if (keys_released[k] > 0) {
					asdf.push_back(make_pair(k, keys_released[k]));
				}
			}
			keys_held.push_back(asdf);
		}

		sequence.clear();
		for (int j = 0; j < n; j++) {
			sequence.push_back(-1);
		}
		seen.clear();
		bool possible = search(0, 0);		

		out << "Case #" << i + 1 << ":";
		if (!possible) {
			out << " IMPOSSIBLE" << endl;
		} else {
			for (int i = 0; i < sequence.size(); i++) {
				out << " " << sequence[i] + 1;
			}
			out << endl;
		}
	}
    
	in.close();
	out.close();

	return 0;
}
