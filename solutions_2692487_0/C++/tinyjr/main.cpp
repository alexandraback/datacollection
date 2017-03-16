#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <bitset>
#include <list>
#include <sstream>
#include <ctime>
#include <functional>
#define pi 3.14159265358979323846264338327950288
#define pb push_back
#define mp make_pair
#define LL long long
#define LD long double
#define INF 1000000000
#define INFll 1000000000000000000ll
#define Vi vector<int>
#define VI Vi::iterator
#define Mi map<int, int>
#define MI Mi::iterator
#define Si set<int>
#define SI Si::iterator
#define FOR(i,s,e) for (int i=(s); i<(e); i++)
#define FOE(i,s,e) for (int i=(s); i<=(e); i++)
#define FOD(i,s,e) for (int i=(s)-1; i>=(e); i--)
#define CLR(a,x) memset(a, x, sizeof(a))
#define mid (l + r) / 2
#define Left k * 2, l, mid
#define Right k * 2 + 1, mid + 1, r
#define N 1111111
using namespace std;
typedef pair<LL,LL> LLp;
LL o, a[N], b[N], s[N], p[N], ans;
int size[N], n, m, i, j;
int T, cas;
LLp get(int X, int y){
	LL x = X;
	if (x == 1 && x <= y) return mp(x, INF);
	LL tms = 0;
	for (; x <= y; tms++){
		x += x - 1;
	}
	return mp(x + y, tms);
}
int main(){
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	cin >> T;
	for (cas = 1; cas <= T; cas++){
		cin >> p[0] >> n;
		for (i = 1; i <= n; i++)
			cin >> size[i];
		sort (size + 1, size + n + 1);
		for (i = 1; i <= n; i++){
			LLp tmp = get(p[i - 1], size[i]);
			a[i] = a[i - 1] + tmp.second;
			p[i] = tmp.first;
		}
		s[n + 1] = 0;
		for (i = n; i; i--)
			s[i] = s[i + 1] + a[i];
		for (i = 1; i <= n; i++)
			b[i] = min(n - (LL)i, s[i + 1] - s[n + 1]);
		ans = n;
		for (i = 1; i <= n; i++)
			ans = min(ans, a[i] + b[i]);
		printf("Case #%d: %I64d\n", cas, ans);
	}
}
