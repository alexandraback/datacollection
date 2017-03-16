#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <fstream>
#include <map>
#include <set>
#include <queue>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
using namespace std;

const int N = 110;
int n, m;
int newnum[N];
bool e[N][N];
bool flag[N];
bool del[N];
int q[N];

struct zip{
	string str;
	int num;
	bool operator < (const zip & b) const {
		return str < b.str;
	}
} allzip[N];

int a[N];

string ans;

int main() {
	int T;
	cin >> T;
	for (int test = 1; test <= T; ++test) {
		cin >> n >> m;
		for (int i = 1; i <= n; ++i) {
			cin >> allzip[i].str;
			allzip[i].num = i;
		}
		sort(allzip + 1, allzip + n + 1);
		for (int i = 1; i <= n; ++i) {
			newnum[allzip[i].num] = i;
		}
		memset(e, 0, sizeof(e));
		for (int i = 0; i < m; ++i) {
			int a, b;
			cin >> a >> b;
			a = newnum[a];
			b = newnum[b];
			e[a][b] = e[b][a] = true;
		}
		for (int i = 1; i <= n; ++i) {
			a[i] = n - i + 1;
		}
		int allround = 1;
		for (int i = 1; i <= n; ++i) allround = allround * i;
		//for (int i = 1; i <= n; ++i) cout << allzip[i].str << ' ' << allzip[i].num << endl;
		//for (int i = 1; i <= n; ++i) {for (int j = 1; j <= n; ++j) cout << e[i][j] << ' ';cout << endl;}
		while (allround--) {
			next_permutation(a + 1, a + n + 1);
			int top = 0;
			q[top] = a[1];
			bool flag = true;
			for (int i = 2; i <= n; ++i) {
				int k = a[i];
				while (top >= 0 && !e[q[top]][k]) --top;
				if (top < 0) {
					flag = false;
					break;
				}
				++top;
				q[top] = k;
			}
			if (flag) break;
		}
		//for (int i = 1; i <= n; ++i) cout << a[i] << endl;
		ans = "";
		for (int i = 1; i <= n; ++i)
			ans += allzip[a[i]].str;
		cout << "Case #" << test << ": " << ans << endl;
	}
	return 0;
}