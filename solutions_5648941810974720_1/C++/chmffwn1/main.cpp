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
#include <unordered_map>
#include <ctime>
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
const int INF = (int) 1e9;
const long long INF64 = (long long) 1e18;
const long double eps = 1e-9;
const long double pi = 3.14159265358979323846;
using namespace std;

int main() {
	//freopen("A_small.in", "r", stdin);
	//freopen("A_small.out", "w", stdout);
	freopen("A_large.in", "r", stdin);
	freopen("A_large.out", "w", stdout);
	ll T;
	cin >> T;
	for (int t = 0; t < T; t++) {
		string str;
		cin >> str;
		unordered_map<char, int> st;
		unordered_map<int, int> cnt;
		for (char c = 'A'; c <= 'Z'; c++) st[c] = 0;
		for (int i = 0; i < str.size(); i++) {
			st[str[i]]++;
		}
		st[0] = st['Z'];
		st[1] = st['O'] - st['Z'] - st['W'] - st['U'];
		st[2] = st['W'];
		st[3] = st['H'] - st['G'];
		st[4] = st['U'];
		st[5] = st['F'] - st['U'];
		st[6] = st['X'];
		st[7] = st['S'] - st['X'];
		st[8] = st['G'];
		st[9] = (st['N'] - st[1] - st[7]) / 2;
		string res = "";
		for (int i = 0; i < 10; i++) {
			if (st.find(i) == st.end()) continue;
			for (int j = 0; j < st[i]; j++) {
				res += to_string(i);
			}
		}
		cout << "Case #" << (t + 1) << ": " << res << endl;
	}
	return 0;
}