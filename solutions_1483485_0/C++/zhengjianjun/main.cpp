#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>

using namespace std;

typedef pair<int, int> pii;
typedef long long llong;

#define mp make_pair
#define lowbit(x) ((x) & (-(x)))
#define pf(x) ((x) * (x))
#define two(x) (1 << (x))
#define twoL(x) ((llong) 1 << (x))
#define clr(x, c) memset(x, c, sizeof(x))

void ch_max(int &x, int y) {if (x < y) x = y;}
void ch_min(int &x, int y) {if (x > y) x = y;}

const double pi = acos(-1.0);
const double eps = 1e-9;

char a[1000] = "aoz ejp mysljylc kd kxveddknmc re jsicpdrysi rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd de kr kd eoya kw aej tysr re ujdr lkgc jv";
char b[1000] = "yeq our language is impossible to understand there are twenty six factorial possibilities so it is okay if you want to just give up";

char my[26];
bool vis[26];
char str[1000];

int main() {
	freopen("GCJ\\A-small-attempt0.in", "r", stdin);
//	freopen("GCJ\\in.txt", "r", stdin);
	freopen("GCJ\\out.txt", "w", stdout);
	
	int i, j, k, t, nc = 0;
	int len = strlen(a);
	clr(vis, 0);
	clr(my, 0);
	for (i = 0; i < len; ++i) {
		if (a[i] == ' ') continue;
		my[a[i] - 'a'] = b[i];
		vis[b[i] - 'a'] = 1;
	}
	for (i = 0; i < 26; ++i) {
		if (my[i] == 0) {
			for (j = 0; j < 26; ++j) if (!vis[j]) break;
			my[i] = j + 'a';
		}
	}
	scanf("%d", &t);
	getchar();
	while (t--) {
		gets(str);
		int t0 = strlen(str);
		for (i = 0; i < t0; ++i) {
			if (str[i] == ' ') continue;
			str[i] = my[str[i] - 'a'];
		}
		printf("Case #%d: %s\n", ++nc, str);
	}
	return 0;
}