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
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
const int INF = (int) 1e9;
const long long INF64 = (long long) 1e18;
const long double eps = 1e-9;
const long double pi = 3.14159265358979323846;
using namespace std;

int main() {
	freopen("A_small.in", "r", stdin);
	freopen("A_small.out", "w", stdout);
	//freopen("A_large.in", "r", stdin);
	//freopen("A_large.out", "w", stdout);
	ll T;
	cin >> T;
	for (int t = 0; t < T; t++) {
		string str;
		cin >> str;
		string res = "";
		for (int i = 0; i < str.size(); i++) {
			if (i == 0) res += str[i];
			else {
				if (str[i] < res[0]) res += str[i];
				else res = str[i] + res;
			}
		}
		cout << "Case #" << (t + 1) << ": " << res << endl;
	}
	return 0;
}