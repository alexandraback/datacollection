#include <stdio.h>
#include <algorithm>

using namespace std;

const int MAXN = 10010;
int tr[128];
int n, x, nx;
char s[MAXN];
int a[MAXN];

const int I = 2, J = 3, K = 4;
int table[5][5] = {
	{ 0,  0,  0,  0,  0},
	{ 0,  1,  I,  J,  K},
	{ 0,  I, -1,  K, -J},
	{ 0,  J, -K, -1,  I},
	{ 0,  K,  J, -I, -1}};

int mul(int a, int b)
{
	int c = 1;
	if (a < 0) a = -a, c = -c;
	if (b < 0) b = -b, c = -c;
	return c * table[a][b];
}

void init()
{
	scanf("%d%d", &n, &x);
	nx = n * min(8, x);
	scanf("%s", s);
	for (int i = 0; i < n; ++i) a[i] = tr[s[i]];
}

int find(int i, int tar)
{
	int s = 1;
	for (; i < nx; ++i) {
		s = mul(s, a[i % n]);
		if (s == tar) return i;
	}
	return -1;
}

bool check()
{
	int s = 1, ss = 1;
	for (int i = 0; i < n; ++i) s = mul(s, a[i]);
	for (int i = 0; i < x % 4; ++i) ss = mul(ss, s);
	if (ss != -1) return false;
	int i = find(0, I);
	if (i == -1) return false;
	return find(i + 1, J) != -1;
}

int main()
{
	tr['1'] = 1, tr['i'] = I, tr['j'] = J, tr['k'] = K;
	int dat;
	scanf("%d", &dat);
	for (int cas = 1; cas <= dat; ++cas) {
		init();
		printf("Case #%d: %s\n", cas, check() ? "YES" : "NO");
	}
}
