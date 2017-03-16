/* [themighty] deathsurgeon (Rupesh Maity)
* 2nd year, B.Tech in IT
* IIIT - Allahabad
*/

#include <iostream>
#include <cstdio>
#include <math.h>
#include <string>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <stack>
#include <queue>
#include <vector>
#include <map>

using namespace std;

typedef long long LL;
typedef unsigned uint;
typedef pair<int, int> pii;

#define MOD 1000000007
#define MAX 1000000
#define pb push_back
#define yes puts("YES")
#define no puts("NO")
#define sd(x) scanf("%d", &x)
#define PI 3.14159265

double d[101][101][101];
double ans;
int k, l, s;
string str;
string res;
int cnt[200];
int z;
double p;

void play(string a, int idx) {
	if (idx == s) {
	//	cout << a << endl;
		int w = 0;
		for (int i = 0; i <= z; i++) {
			if (a[i] == res[0]) {
				for (int j = 1; j < l; j++) {
					if (res[j] != a[i + j])
						goto RUP;
				}
				++w;
			}
		RUP:;
		}

		ans += w*p;
		return;
	}

	for (int i = 0; i < k; i++) {
		play(a + str[i], idx + 1);
	}
}

int main() {
//	freopen("5input.txt", "r", stdin);
	//freopen("5output.txt", "w", stdout);
	int t;
	cin >> t;

	for (int cas = 1; cas <= t; cas++) {
		printf("Case #%d: ", cas);
		ans = 0;
		cin >> k >> l >> s;
		z = s - l;
		cin >> str;
		p = 1;
		for (int i = 0; i < s; i++)
			p /= k;

		for (int i = 0; i < 200; i++)
			cnt[i] = 0;

		for (int i = 0; i < k; i++)
			++cnt[str[i]];

		cin >> res;

		if (l > s) {
			puts("0.0");
			continue;
		}

		bool f = false;
		for (int i = 0; i < l; i++) {
			if (!cnt[res[i]]) {
				puts("0.0");
				f = true;
				break;
			}
		}
		if (f)
			continue;

		int mx = 1;
		for (int i = 1; i < l; i++) {
			if (res[0] == res[i]) {
				for (int j = i + 1; j < l; j++) {
					if (res[j - i] != res[j])
						goto OVER;
				}
				int m = s - i;
				while (m >= l){
					++mx;
					m -= i;
				}
				break;
			}
		OVER:;
		}
		if (mx == 1)
            mx = s/l;

		play("", 0);
		// count expectancy
		// s:l:mx
		printf("%.7lf\n", mx - ans);
	}

	return 0;
}
