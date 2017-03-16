#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <utility>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <functional>

using namespace std;

#define uchar unsigned char
#define ushort unsigned short
#define ull unsigned ll
#define ll long long
#define ull unsigned ll

#define E 2.718281828
#define PI 3.14159265358979323846264338328

bool flag[2501];

void solve() {
	for (int i = 1; i <= 2500; i++)
		flag[i] = false;
	int n;
	cin >> n;
	for (int i = 0; i < 2 * n - 1; i++)
		for (int j = 0; j < n; j++) {
			int num;
			cin >> num;
			flag[num] = !flag[num];
		}
	for (int i = 1; i <= 2500; i++)
		if (flag[i])
			cout << " " << i;
	cout << endl;
}

int main() {
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	for (int i = 1; i <= t; i++) {
		cout << "Case #" << i << ":";
		solve();
	}
	return 0;
}