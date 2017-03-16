#pragma comment(linker, "/STACK:512000000")
#include <iostream>
#include <vector>
#include <iomanip>
#include <set>
#include <queue>
#include <deque>
#include <map>
#include <list>
#include <algorithm>
#include <stdlib.h>
#include <stdio.h>
#include <cstring>
#include <ctime>
#include <string>
#include <sstream>
#include <math.h>
#include <stack>

using namespace std;

#define eprintf(...) fprintf(stderr, __VA_ARGS__)

vector<int> covered;
vector<int> test;

int memo[10];
int found;
int this_v;
void rec(int lowest, int at, int need) {

	if (found == 1) return;

	if (at == need) {
		
		vector<int> tcovered = covered;
		for (int j = 0; j < need; ++j) {
			for (int i = this_v; i >= 0; --i) {
				if (tcovered[i] && i + test[memo[j]] <= this_v) {
					tcovered[i + test[memo[j]]] = 1;
				}
			}
		}

		for (int i = 0; i <= this_v; ++i) {
			if (tcovered[i] == 0) {
				goto end;
			}
		}

		found = 1;

		end:;

		return;
	}

	for (int i = lowest + 1; i < test.size(); ++i) {
		memo[at] = i;
		rec(i, at + 1, need);
	}
}

int brute_solve(int v, vector<int> have) {
	covered.assign(v + 1, 0);
	covered[0] = 1;

	bool in_have[45] = {0,};
	
	for (int j = 0; j < have.size(); ++j) {
		in_have[have[j]] = 1;
		for (int i = v; i >= 0; --i) {
			if (covered[i] && i + have[j] <= v) {
				covered[i + have[j]] = 1;
			}
		}
	}

	test.clear();

	for (int i = 1; i <= v; ++i) {
		if (in_have[i] == 0) {
			test.push_back(i);
		}
	}

	if (test.empty()) return 0;
	
	found = 0;
	this_v = v;

	for (int i = 0; i <= test.size(); ++i) {
		rec(-1, 0, i);

		if (found) return i;
	}

}





int very_brute(int v, vector<int> have) {

	vector<int> covered(v+1, 0);
	covered[0] = 1;

	bool in_have[45] = {0,};
	
	for (int j = 0; j < have.size(); ++j) {
		in_have[have[j]] = 1;
		for (int i = v; i >= 0; --i) {
			if (covered[i] && i + have[j] <= v) {
				covered[i + have[j]] = 1;
			}
		}
	}

	vector<int> test;

	for (int i = 1; i <= v; ++i) {
		if (in_have[i] == 0) {
			test.push_back(i);
		}
	}

	if (test.empty()) return 0;

	int need = 5;

	for (int mask = 0; mask < (1 << test.size()); ++mask) {
		vector<int> tcovered = covered;
		int cur = 0;
		for (int i = 0; i < test.size(); ++i) {
			if (mask & (1 << i)) {
				++cur;
				if (cur >= need) {
					goto end;
				}
				for (int j = v; j >= 0; --j) {
					if (tcovered[j] && j + test[i] <= v) {
						tcovered[j + test[i]] = 1;
					}
				}
			}
		}

		int sum = v;
		for (int i = 1; i < tcovered.size(); ++i) {
			if (tcovered[i] == 0) {
				sum = -1;
				break;
			}
		}

		if (sum != -1) {
			if (cur < need) need = cur;
		}

		end:;
	}

	return need;
}



int main() {

	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
	    freopen("output.txt","w",stdout);
	#else
	#define taskname "cutting"
		//freopen(taskname".in","r",stdin);
		//freopen(taskname".out","w",stdout);
	#endif



	int tests_; cin >> tests_;
	for (int test_ = 1; test_ <= tests_; ++test_) {
		
		int c, d, v;
		cin >> c >> d >> v;
		vector<int> have(d);
		for (int i = 0; i < d; ++i) {
			cin >> have[i];
		}

		
		int res = -1;
		if (c == 1 && d <= 5 && v <= 30) {
			res = brute_solve(v, have);
			if (false && v <= 25) {
				int tres = very_brute(v, have);

				if (res != tres) {
					cerr << "ERROR" << endl;
					cerr << c << " " << d << " " << v << endl;
					for (int i = 0; i < have.size(); ++i) {
						cerr << have[i] << " ";
					}
					cerr << "REAL: " << tres << endl;
					cerr << "MY: " << res << endl;
					return 0;
				}
			}
		}
		cout.precision(8);
		cout << "Case #" << test_ << ": " << fixed << res << endl;;
		
		cerr << c << " " << v << ": ";
		for (int i = 0; i < have.size(); ++i) {
			cerr << have[i] << " ";
		}
		cerr << endl;
		cerr.precision(8);
		cerr << "Case #" << test_ << ": " << fixed << res << endl << endl;
	}

	return 0;
}