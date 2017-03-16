#include <set>
#include <map>
#include <cmath>
#include <ctime>
#include <vector>
#include <string>
#include <cstdio>
#include <cassert>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

#define pb push_back
#define mp make_pair
#define sz(a) (int)a.size()
#define all(a) a.begin(), a.end()
#define ms(a,x) memset(a,x,sizeof a)
#define ones(x) __builtin_popcount(x)
#define rep(i,n) for (int i = 0; i < n; i++)
#define forit(i,a) for (typeof(a.begin()) i = a.begin(); i != a.end(); i++)

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;

const int N = 1000500;
const int inf = 1<<30;

char str[N];
int s[N], f[500];

int main()
{
	#ifdef LOCAL
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
	#endif

	int tests;
	scanf("%d\n", &tests);

	for (char ch = 'a'; ch <= 'z'; ch++)
		f[ch] = 1;
	f['a'] = f['e'] = f['i'] = f['o'] = f['u'] = 0;

	for (int test = 1; test <= tests; test++) {
		int n;
		scanf("%s%d\n",str,&n);
		int l = strlen(str);
		for (int i = 0; i < l; i++) {
			if (f[str[i]])
				s[i] = (i?s[i-1]:0) + 1;
			else
				s[i] = 0;
		}
		for (int i = l-1; i >= 0; i--)
			s[i] = (s[i] >= n);
/*		for (int i = 0; i < l; i++)
			printf("%d ", s[i]);
		printf("\n");*/
		ll res = 0;
		int last = -1;
		for (int i = n-1; i < l; i++) {
			if (s[i]) last = i;
			if (last != -1) res += last-n+2;
		}
		printf("Case #%d: %I64d\n", test, res);
	}

	return 0;
}
