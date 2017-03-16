#include <functional>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <sstream>
#include <numeric>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <string>
#include <cstdio>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <cmath>
#include <list>
#include <set>
#include <map>
#include <ctime>
#include <iomanip>
#include <unordered_map>
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
const int INF = (int) 1e9;
const long long INF64 = (long long) 1e18;
const long double eps = 1e-9;
const long double pi = 3.14159265358979323846;
using namespace std;



int main() {
	freopen("B_small.in", "r", stdin);
	freopen("B_small.out", "w", stdout);
	//freopen("B_large.in", "r", stdin);
	//freopen("B_large.out", "w", stdout);
	ll T;
	cin >> T;
	for (int t = 0; t < T; t++) {
		string a, b;
		cin >> a >> b;
		queue<int> av, bv;
		for (int i = 0; i < a.size(); i++) {
			int as = av.size();
			int bs = bv.size();
			if (i == 0) {
				as = 1;
				bs = 1;
			}
			for (int j = 0; j < as; j++) {
				int tmp = 0;
				if (!av.empty()) {
					tmp = av.front(); av.pop();
				}
				if (a[i] != '?') {
					av.push(tmp * 10 + (a[i]-'0'));
				}
				else {
					for (int k = 0; k < 10; k++) {
						av.push(tmp * 10 + k);
					}
				}
			}
			for (int j = 0; j < bs; j++) {
				int tmp = 0;
				if (!bv.empty()) {
					tmp = bv.front(); bv.pop();
				}
				if (b[i] != '?') {
					bv.push(tmp * 10 + (b[i] - '0'));
				}
				else {
					for (int k = 0; k < 10; k++) {
						bv.push(tmp * 10 + k);
					}
				}
			}
		}
		vector<int> ast, bst;
		while (!av.empty()) {
			ast.push_back(av.front()); av.pop();
		}
		while (!bv.empty()) {
			bst.push_back(bv.front()); bv.pop();
		}
		sort(ast.begin(), ast.end());
		sort(bst.begin(), bst.end());
		int minv = 123456;
		int mi = -1;
		int mj = -1;

		for (int i = 0; i < ast.size(); i++) {
			for (int j = 0; j < bst.size(); j++) {
				if (abs(ast[i] - bst[j]) < minv) {
					minv = abs(ast[i] - bst[j]);
					mi = i;
					mj = j;
				}
			}
		}
		string resa = to_string(ast[mi]);
		string resb = to_string(bst[mj]);
		//cout << mi << " " << mj << endl;
		cout << "Case #" << (t + 1) << ": ";
		cout << setfill('0') << setw(a.size()) << resa << " " << setw(a.size()) << resb << endl;
	}
	return 0;
}