#include<iostream>
#include<vector>
#include<fstream>
#include<map>
#include<string>
#include<set>
#include <algorithm>

using namespace std;

void solve(const vector<long long> & numbers, int k, const vector<set<long long>> & diffs, long long diff, vector<int> * res) {
	if (k == 0) {
		if (diff == numbers[0]) {
			res->at(0) = 1;
		}
		if (diff == - numbers[0]) {
			res->at(0) = 2;
		}
	} else {
		for (set<long long>::const_iterator it = diffs[k - 1].begin(); it != diffs[k - 1].end(); ++it) {
			if (diff == *it + numbers[k]) {
				res->at(k) = 1;
				solve (numbers, k - 1, diffs, diff - numbers[k], res);
				return;
			}
			if (diff == *it - numbers[k]) {
				res->at(k) = 2;
				solve (numbers, k - 1, diffs, diff + numbers[k], res);
				return;
			}
			if (diff == *it) {
				solve (numbers, k - 1, diffs, diff, res);
				return;
			}
		}
	}
}


int main() {
	ifstream inp;
	ofstream out;
	inp.open("input.txt");
	out.open("output.txt");
	int t;
	inp >> t;
	for (int test = 0; test < t; ++test) {
		cout << test << endl;
		int n;
		inp >> n;
		vector<long long> numbers(n);
		for (int i = 0; i < n; ++i) {
			inp >> numbers[i];
		}
		sort(numbers.begin(), numbers.end());
		bool ok = false;
		vector<set<long long>> diffs(n);
		for (int i = 0; i < n; ++i) {
			if (i > 0) {
				for (set<long long>::iterator it = diffs[i - 1].begin(); it != diffs[i - 1].end(); ++it) {
					diffs[i].insert(*it + numbers[i]);
					diffs[i].insert(*it - numbers[i]);
					diffs[i].insert(*it);
				}
			}
			diffs[i].insert(numbers[i]);
			diffs[i].insert(-numbers[i]);
			if (diffs[i].find(0) != diffs[i].end()) {
				ok = true;
				vector<int> res(n, 0);
				solve(numbers, i, diffs, 0, &res);
				out << "Case #" << test + 1 << ":" << endl;
				for (int t = 1; t <= 2; ++t) {
					for (int i = 0; i < n; ++i) {
						if (res[i] == t) {
							out << numbers[i] << " ";
						}
					}
					out << endl;
				}
				break;
			}			
		}
		if (!ok) {
			out << "Case #" << test + 1 << ":" << endl << "Impossible" << endl;
		}
	}
	return 0;
}