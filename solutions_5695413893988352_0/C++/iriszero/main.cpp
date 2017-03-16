#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <utility>
#include <string.h>
#include <assert.h>
#include <string>
#include <iostream>

#define SUBMIT 1
using namespace std;

int cnt[256];
int res[10];
void file_reopen() {
	freopen("c:\\codejam\\input3.txt", "r", stdin);
	freopen("c:\\codejam\\output3.txt", "w", stdout);
}
string a, b; vector<char> va, vb;
bool solve_a_b_equal(int i) {

	if (i == a.length()) return true;
	if (a[i] == b[i]) {
		if (a[i] == '?') {
			va.push_back('0');
			vb.push_back('0');
		}
		else {
			va.push_back(a[i]);
			vb.push_back(b[i]);
		}
		
	}
	else if (a[i] == '?') {
		va.push_back(b[i]);
		vb.push_back(b[i]);
	}
	else if (b[i] == '?') {
		va.push_back(a[i]);
		vb.push_back(a[i]);
	}
	else {
		return false;
	}
	return solve_a_b_equal(i + 1);
}
bool solve_a_larger(int i, bool is_a_already_larger) {
	if (i == a.length()) return true;
	if (a[i] == b[i]) {
		if (a[i] == '?') {
			if (is_a_already_larger) {
				va.push_back('0');
				vb.push_back('9');
				if (solve_a_larger(i + 1, true)) {
					return true;
				}
				else {
					va.pop_back(); vb.pop_back();
				}
			}
			else {
				va.push_back('0');
				vb.push_back('0');
				if (solve_a_larger(i + 1, false)) {
					return true;
				}
				else {
					va.pop_back(); vb.pop_back();
				}

				va.push_back('1');
				vb.push_back('0');
				if (solve_a_larger(i + 1, true)) {
					return true;
				}
				else {
					va.pop_back(); vb.pop_back();
				}
			}
		}
		else {
			va.push_back(a[i]);
			vb.push_back(b[i]);
			if (solve_a_larger(i + 1, true)) {
				return true;
			}
			else {
				va.pop_back(); vb.pop_back();
			}
		}
	}
	else {
		if (a[i] == '?') {
			if (is_a_already_larger) {
				va.push_back('0');
				vb.push_back(b[i]);
				if (solve_a_larger(i + 1, true)) {
					return true;
				}
				else {
					va.pop_back(); vb.pop_back();
				}
			}
			else {
				va.push_back(b[i]);
				vb.push_back(b[i]);

				if (solve_a_larger(i + 1, false)) {
					return true;
				}
				else {
					va.pop_back(); vb.pop_back();
				}
				
				if (b[i] != '9') {
					va.push_back(b[i] + 1);
					vb.push_back(b[i]);
					if (solve_a_larger(i + 1, true)) {
						return true;
					}
					else {
						va.pop_back(); vb.pop_back();
					}
				}
			}
		}
		else if (b[i] == '?') {
			if (is_a_already_larger) {
				va.push_back(a[i]);
				vb.push_back('9');
				if (solve_a_larger(i + 1, true)) {
					return true;
				}
				else {
					va.pop_back(); vb.pop_back();
				}
			}
			else {
				va.push_back(a[i]);
				vb.push_back(a[i]);
				if (solve_a_larger(i + 1, false)) {
					return true;
				}
				else {
					va.pop_back(); vb.pop_back();
				}
				if (a[i] > '0') {
					va.push_back(a[i]);
					vb.push_back(a[i] - 1);

					if (solve_a_larger(i + 1, true)) {
						return true;
					}
					else {
						va.pop_back(); vb.pop_back();
					}
				}
			}
		
		}
		else {
			//a[i], b[i] are already determinded
			if (is_a_already_larger) {
				va.push_back(a[i]);
				vb.push_back(b[i]);
				if (solve_a_larger(i + 1, true)) {
					return true;
				}
				else {
					va.pop_back(); vb.pop_back();
				}
			}
			else {
				if (a[i] < b[i]) return false;
				if (a[i] > b[i]) {
					va.push_back(a[i]); vb.push_back(b[i]);
					if (solve_a_larger(i + 1, true)) {
						return true;
					}
					else {
						va.pop_back(); vb.pop_back();
					}
				}
			}
		}
	}
	return false;
}
void print_result(vector<char> par_vec_a, vector<char> par_vec_b) {
	for (char c : par_vec_a) {
		printf("%c", c);
	}
	printf(" ");
	for (char c : par_vec_b) {
		printf("%c", c);
	}
}
long long get_abs_diff(vector<char> a, vector<char> b) {
	long long res = 0;
	long long w = 1;
	for (int i = a.size() - 1; i >= 0; i--, w*=10) {
		res += long long(a[i] - b[i]) * w;
	}
	return (res > 0 ? res : -res);
}
void solve() {
	va.clear(); vb.clear();
	if (solve_a_b_equal(0)) {
		print_result(va, vb);
		return;
	}
	va.clear(); vb.clear();
	bool ret = solve_a_larger(0, false);
	long long  diff1 = 0, diff2 = 0; //this value couldn't be 0 if return value is true
	vector<char> t1, t2;

	if (ret) {
		diff1 = get_abs_diff(va, vb);
		for (auto c : va) {
			t1.push_back(c);
		}
		for (auto c : vb) {
			t2.push_back(c);
		}
	}

	va.clear(); vb.clear();
	swap(a, b);
	bool ret2 = solve_a_larger(0, false);
	if (ret2) {
		diff2 = get_abs_diff(va, vb);
	}

	//result of a larger is stored in diff1, t1, t2 , ret
	//result of b larger is stored in diff2, va, vb , ret2
	
	if (diff1 == diff2) {
		//print b larger
		if (diff1 != 0) {
			if (t1 < vb || (t1 == vb && t2 < vb)) print_result(t1, t2);
			else print_result(vb, va);
		}
		else assert(0);
	}
	else {
		if (diff1 != 0 && diff2 != 0) {
			if (diff1 < diff2) {
				print_result(t1, t2);
			}
			else {
				print_result(vb, va);
			}
		}
		else if (diff1 == 0 && diff2 != 0) {
			print_result(vb, va);
		}
		else if (diff1 != 0 && diff2 == 0) {
			print_result(t1, t2);
		}
		else assert(0);
	}

}
int main(void) {
	if (SUBMIT) file_reopen();

	int T; scanf("%d", &T);

	for (int tc = 1; tc <= T; tc++) {
		printf("Case #%d: ", tc);
		
		cin >> a >> b;
		solve();
		
		printf("\n");
	}	
	return 0;
}