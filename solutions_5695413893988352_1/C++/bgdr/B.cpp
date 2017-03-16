#include <cstdlib>
#include <assert.h>
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void brute(string s1, string s2, int k, int n1, int n2, int & best_diff, int &best_n1, int &best_n2) {
	if (k == s1.size()) {
		int diff = n1 > n2 ? n1 - n2 : n2 - n1;
		if (diff == best_diff) {
			if (best_n1 == n1) {
				if (best_n2 > n2) {
					best_n2 = n2;
				}
			}
			if (best_n1 > n1) {
				best_n1 = n1;
				best_n2 = n2;
			}
		}
		if (diff < best_diff) {
			best_diff = diff;
			best_n1 = n1;
			best_n2 = n2;
		}
		return;
	}
	for (int d1 = 0; d1 <= 9; d1++)
		for (int d2 = 0; d2 <= 9; d2++) {
			if (s1[k] == '?' || ((s1[k] - '0') == d1))
				if (s2[k] == '?' || ((s2[k] - '0') == d2)) {
					brute(s1, s2, k + 1, n1 * 10 + d1, n2 * 10 + d2, best_diff, best_n1, best_n2);
				}

		}
}

bool solve(string s1, string s2, int k, int bigger, vector<int> & ret1, vector<int> & ret2) {
	int cbigger = -1;
	ret1.clear();
	ret2.clear();
	assert(ret1.size() == 0);
	for (int i = 0; i < s1.size(); ++i) {
		if (s1[i] != '?' && s2[i] != '?') {
			if (cbigger == -1) {
				if (s1[i] > s2[i]) cbigger = 1;
				if (s1[i] < s2[i]) cbigger = 2;
				if (k == i && cbigger != bigger) {
					return false;
				}
			}
			ret1.push_back(s1[i] - '0');
			ret2.push_back(s2[i] - '0');
			continue;
		}
		if (s1[i] == '?' && s2[i] == '?') {
			if (i == k && cbigger == -1) {
				if (bigger == 1) {
					ret1.push_back(1);
					ret2.push_back(0);
				}
				if (bigger == 2) {
					ret1.push_back(0);
					ret2.push_back(1);
				}
				cbigger = bigger;
				continue;
			}
			if (cbigger == -1) {
				ret1.push_back(0);
				ret2.push_back(0);
			}
			if (cbigger == 1) {
				ret1.push_back(0);
				ret2.push_back(9);
			}
			if (cbigger == 2) {
				ret1.push_back(9);
				ret2.push_back(0);
			}
			continue;
		}
		assert( (s1[i] == '?' && s2[i] != '?') || (s1[i] != '?' && s2[i] == '?') );
		if (i == k && cbigger == -1) {
			if (bigger == 1 && s1[i] == '?') {
				if (s2[i] == '9') return false;
				ret1.push_back(s2[i] - '0' + 1);
				ret2.push_back(s2[i] - '0');
			}
			if (bigger == 1 && s1[i] != '?') {
				if (s1[i] == '0') return false;
				ret2.push_back(s1[i] - '0' - 1);
				ret1.push_back(s1[i] - '0');
			}
			if (bigger == 2 && s2[i] == '?') {
				if (s1[i] == '9') return false;
				ret2.push_back(s1[i] - '0' + 1);
				ret1.push_back(s1[i] - '0');
			}
			if (bigger == 2 && s2[i] != '?') {
				if (s2[i] == '0') return false;
				ret1.push_back(s2[i] - '0' - 1);
				ret2.push_back(s2[i] - '0');
			}
			cbigger = bigger;
			continue;
		}
		if (s1[i] == '?') {
			if (cbigger == 1) {
				ret1.push_back(0);
			}
			if (cbigger == -1) {
				ret1.push_back(s2[i] - '0');
			}
			if (cbigger == 2) {
				ret1.push_back(9);
			}
		} else {
			ret1.push_back(s1[i] - '0');
		}
		if (s2[i] == '?') {
			if (cbigger == 1) {
				ret2.push_back(9);
			}
			if (cbigger == -1) {
				ret2.push_back(s1[i] - '0');
			}
			if (cbigger == 2) {
				ret2.push_back(0);
			}
		} else {
			ret2.push_back(s2[i] - '0');
		}
	for(int ii = 0 ; ii < ret2.size(); ++ii)
		assert(ret2[ii] < 10);
	}
	assert(ret1.size() == s1.size());
	assert(ret2.size() == s2.size());
	for(int i = 0 ; i < ret1.size(); ++i)
		assert(ret1[i] < 10);
	return true;
}

void get_diff(vector<int> & a, vector<int> & b, vector<int> & c) {
	c.clear();
	int t = 0;
	int bigger = -1;
	assert(a.size() == b.size());
	for (int i = 0; i < a.size(); ++i) {
		if (bigger == -1) {
			if (a[i] > b[i]) {
				bigger = 1;
				break;
			}
			if (a[i] < b[i]) {
				bigger = 2;
				break;
			}
		}
	}
	for (int i = a.size() - 1; i >= 0; --i) {
		int d = a[i] - t - b[i];
		if (bigger == 2) {
			d = b[i] - t - a[i];
		}
		if (d < 0) {
			d += 10;
			t = 1;
		} else t = 0;
		c.insert(c.begin(), d);
	}
	
	assert(c.size() == a.size());
}

int cmp(vector<int> & a, vector<int> & b) {
	assert(a.size() == b.size());
	for (int i = 0; i < a.size(); ++i) {
		if (a[i] > b[i]) {
			return 1;
		}
		if (a[i] < b[i]) {
			return -1;
		}
	}
	return 0;
}

void replace(vector<int> & a, vector<int> & b) {
	a.clear();
	for (int i = 0; i < b.size(); ++i)
		a.push_back(b[i]);
}
void printv(vector<int> & v) {
	cout << "[";
	for(int i = 0; i <v.size();++i)
		cout << v[i] << " ";
	cout << "] " ;
	
}
void update(vector<int> & best_ret1, vector<int> & best_ret2, vector<int> & best_diff, vector<int> & ret1, vector<int> & ret2) {
	vector<int> diff;
	get_diff(ret1, ret2, diff);
	int res = best_diff.size() == 0 ? 1 : cmp(best_diff, diff);
	if (res == 1) {
		replace(best_ret2, ret2);
		replace(best_ret1, ret1);
		replace(best_diff, diff);
		cout << "repl1 " ;
		printv(best_diff);
		printv(best_ret1);
		printv(best_ret2);
		cout << endl;
		return;
	}
	if (res == 0) {
		int res1 = cmp(best_ret1, ret1);
		if (res1 == 1) {
			replace(best_ret2, ret2);
			replace(best_ret1, ret1);
		cout << "repl2 " ;
		printv(best_ret1);
		printv(best_ret2);
		cout << endl;
			return;
		}
		if (res1 == 0) {
			int res2 = cmp(best_ret2, ret2);
			if (res2 == 1) {
				replace(best_ret2, ret2);
				return;
			}
		}
	}
}

int main(int argc, char** argv) {
	ifstream fin("/home/bgd/Downloads/B-large.in");
	fin.exceptions(ifstream::failbit | ifstream::badbit);
	ofstream fout("B-large.out");
	ostream & out = fout;

	int T;
	string S1, S2;

	fin >> T;
	for (int t = 1; t <= T; ++t) {
		vector<int> best_ret1, best_ret2, best_diff, ret1, ret2;

		fin >> S1 >> S2;
		for (int k = 0; k <= S1.size(); ++k) {
			if (solve(S1, S2, k, 1, ret1, ret2)) {
				update(best_ret1, best_ret2, best_diff, ret1, ret2);
				assert(best_ret1.size() == S1.size());
				assert(best_ret2.size() == S1.size());
			}
			if (solve(S1, S2, k, 2, ret1, ret2)) {
				update(best_ret1, best_ret2, best_diff, ret1, ret2);
			}
		}
				assert(best_ret1.size() == S1.size());
				assert(best_ret2.size() == S1.size());
		out << "Case #" << t << ": ";
		for (int i = 0; i < best_ret1.size(); ++i)
			out << best_ret1[i];
		out << " ";
		for (int i = 0; i < best_ret2.size(); ++i)
			out << best_ret2[i];
//		out << " ";
//		for (int i = 0; i < best_diff.size(); ++i)
//			out << best_diff[i];

		/* CHECK */
/*		int best_n1, best_n2, best_diff_ = 100000000;
		brute(S1, S2, 0, 0, 0, best_diff_, best_n1, best_n2);
		int n1 = 0, n2 = 0;
		for (int i = 0; i < ret1.size(); ++i) {
			n1 = (n1 * 10 + best_ret1[i]);
			n2 = (n2 * 10 + best_ret2[i]);
		}
		if (n1 != best_n1 || n2 != best_n2) out << " DIFFFF: " << best_n1 << " " << best_n2;*/
		out << endl;
//		break;
	}
	return 0;
}

