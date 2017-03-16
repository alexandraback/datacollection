#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <functional>
#include <cmath>

#define Fill(x,y) memset(x, y, sizeof(x))
#define Cpy(x,y) memcpy(x, y, sizeof(x))
#define fi first
#define se second
#define pb push_back
#define fo(i,a,b) for (int i = a; i <= b; i ++)
#define fd(i,a,b) for (int i = a; i >= b; i --)
#define SQR(x) ((x)*(x))
#define mkp make_pair

using namespace std;

typedef double DB;
typedef long long LL;
typedef pair <LL, LL> PL;
typedef pair <int, int> PI;
typedef pair <DB, DB> PD;
typedef pair <PI, PI> PIII;
typedef pair <PD, DB> LINE;

int Read()
 {
	char c; while (c = getchar(), (c != '-') && (c < '0' || c > '9'));
	bool neg = (c == '-'); int ret = (neg ? 0 : c - 48);
	while (c = getchar(), c >= '0' && c <= '9') ret = ret * 10 + c - 48;
	return neg ? -ret : ret;
 }
 
bool checked;
int R, N, M, K, a[15], ans[15];

bool verify(int x, int y, int z)
 {
	if (x == y) return 1;
	if (z > N || x < y) return 0;
	if (verify(x, y * ans[z], z + 1)) return 1;
	if (verify(x, y, z + 1)) return 1;
	return 0;
 }
 
void guess(int d)
 {
	if (d > N)
	 {
		checked = 1;
		fo (i, 1, K) if (!verify(a[i], 1, 1)) { checked = 0; break; }
		return;
	 }
	fo (i, 2, M)
	 {
		ans[d] = i;
		guess(d + 1);
		if (checked) return;
	 }
 }
 
int main()
 {
	freopen("C.in", "r", stdin), freopen("C.out", "w", stdout);
	int cases = Read(); puts("Case #1:");
	scanf("%d%d%d%d", &R, &N, &M, &K); while (R --)
	 {
		fo (i, 1, K) scanf("%d", &a[i]);
		checked = 0, guess(1);
		fo (i, 1, N) printf("%d", ans[i]);
		puts("");
	 }
 }
