//By Lin
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <bitset>
#include <cmath>
#include <string>
#include <cstdlib>
#include <vector>
#include <queue>

#define X first
#define Y second
#define mp make_pair
#define sqr(x) ((x) * (x))
#define Rep(i, n) for(int i = 0; i<(n); i++)
#define foreach(it, n) for(__typeof(n.begin()) it = n.begin(); it != n.end(); it++)

using namespace std;
typedef long long LL;
typedef pair<int, int> pii;

#define esp 1e-8
#define N 100010
#define MOD 1000000007

int n;
char s[N];
string ans;

int main() {
	int cas, tt = 0;
	cin >> cas;
	while (cas --) {
		scanf("%s", s);
		ans = "";
		ans += s[0];
		for (int i = 1; s[i]; i++) 
			if (s[i] >= ans[0]) ans = s[i] + ans;
			else ans = ans + s[i];
		printf("Case #%d: %s\n", ++tt, ans.c_str());
	}
	return 0;
}
