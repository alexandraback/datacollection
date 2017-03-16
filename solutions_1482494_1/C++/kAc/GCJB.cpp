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

//kAc
const double pi = acos(-1.0), eps = 1e-9;
const int dx[8] = {1, -1, 0, 0, 1, 1, -1, -1};
const int dy[8] = {0, 0, 1, -1, 1, -1, -1, 1};
const int MO = (int)(1e9 + 7);

#define ALL(x) x.begin(), x.end()
#define fr(x, E) for (__typeof(E.begin()) x = E.begin(); x != E.end(); x++)
#define MP make_pair
#define PB push_back
#define FR first
#define SC second
#define ERR cerr << "ERROR" << endl
#define LL long long
#define LD long double
#define PII pair<int, int>
#define PIII pair<PII, int>
#define PDI pair<double, int>
#define PID pair<int, double>
#define SZ(a) (int)((a).size())
#define VEC vector
#define STR string
#define ISS istringstream
#define OSS ostringstream
#define CLR(a, b) memset(a, b, sizeof(a))
#define gmin(a, b) { if (b < a) a = b; }
#define gmax(a, b) { if (b > a) a = b; }

using namespace std;
int n, now;
int num1[1000001], num2[1000001];
bool vis1[1000001], vis2[1000001];
int get1()
{
	int minn = 0, who = -1;
	for (int i = 1; i <= n; i++) if (!vis1[i] && !vis2[i] && num2[i] >= minn && now >= num1[i]){
		minn = num2[i], who = i;
	}
	return who;
}
int get2()
{
	int minn = 0x3f3f3f3f, who = n + 1;
	for (int i = 1; i <= n; i++) if (!vis2[i]){
		if ((num2[i] < minn) || (num2[i] == minn && vis1[i] && !vis1[i]))
		minn = num2[i], who = i;
	}
	return minn <= now ? who : -1;
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("temp.in", "r", stdin); freopen("temp.out", "w", stdout);
#endif
int TEST; scanf("%d", &TEST);
for (int ti = 1; ti <= TEST; ti++){
	printf("Case #%d: ", ti);
	scanf("%d", &n); 
	for (int i = 1; i <= n; i++) scanf("%d%d", &num1[i], &num2[i]);
	memset(vis1, 0, sizeof(vis1));
	memset(vis2, 0, sizeof(vis2));
	num1[n + 1] = 0x3f3f3f3f; num2[n + 1] = 0;
	int ans = 0; now = 0; int g = 0;
	while(1){
		if (g == n) { printf("%d\n", ans); goto fail; }
		int t = get2();
		if (t != -1 && num2[t] <= now){
			++g; ++ans;
			if (vis1[t]){
				++now; vis2[t] = true;
			}
			else{
				now += 2; vis2[t] = true;
			}
			continue;
		}
		t = get1();
		if (t != -1){
			++ans; ++now;
			vis1[t] = true; 
		}
		else { puts("Too Bad"); goto fail;}
	}
fail:;
}
	
}
