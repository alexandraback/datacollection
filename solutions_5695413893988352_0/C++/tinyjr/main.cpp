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
#define X first
#define Y second
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
#define SZ(x) ((int)x.size())
#define mid (l + r) / 2
#define Left k * 2, l, mid
#define Right k * 2 + 1, mid + 1, r
#define N 1111111
using namespace std;
LL LC, LJ;
LL ans;
int n, m, len;
char c[20], j[20];
char a[20], b[20];
int cas, cases;
LL Labs(LL x) {
	return x > 0 ? x : -x;
}

LL trans(char a[], int len) {
	LL ans = 0;
	for (int i = 0; i < len; i++)
		ans = ans * 10 + a[i] - '0';
	return ans;
}

void check(char a[], char b[], int len) {
	LL A = trans(a, len), B = trans(b, len);
	LL temp = Labs(A - B);
	if (temp < ans) {
		ans = temp;
		LC = A;
		memcpy(c, a, len);
		LJ = B;
		memcpy(j, b, len);
	}
	else
	if (temp == ans) {
		if (A < LC) {
			LC = A;
			memcpy(c, a, len);
			LJ = B;
			memcpy(j, b, len);
		}
		else
        if (A == LC) {
            if (B < LJ) {
                LC = A;
                memcpy(c, a, len);
                LJ = B;
                memcpy(j, b, len);
            }
        }
	}
}
//0 : equal
//1 : C > J
//-1 : C < J
void dfs(int dep, int stat) {
	char ta = a[dep], tb = b[dep];
	if (dep == len) check(a, b, len);
	else {
		if (a[dep] == '?' && b[dep] == '?') {
			if (stat == 0) {
				a[dep] = b[dep] = '0';
				dfs(dep + 1, 0);
				a[dep] = '1', b[dep] = '0';
				dfs(dep + 1, -1);
				a[dep] = '0', b[dep] = '1';
				dfs(dep + 1, 1);
			}
			if (stat == 1) {
				a[dep] = '9'; b[dep] = '0';
				dfs(dep + 1, stat);
			}
			if (stat == -1) {
				a[dep] = '0'; b[dep] = '9';
				dfs(dep + 1, stat);
			}
			dfs(dep + 1, stat);
		}
		else
		if (a[dep] == '?') {
			if (stat == 0) {
				a[dep] = b[dep];
				dfs(dep + 1, stat);
				a[dep] = b[dep] + 1;
				if (a[dep] > '9') a[dep] = '9';
				if (a[dep] > b[dep])
				dfs(dep + 1, -1);
				a[dep] = b[dep] - 1;
				if (a[dep] < '0') a[dep] = '0';
				if (a[dep] < b[dep])
				dfs(dep + 1, 1);
			}
			if (stat == 1) {
				a[dep] = '9';
				dfs(dep + 1, stat);
			}
			if (stat == -1) {
				a[dep] = '0';
				dfs(dep + 1, stat);
			}
			dfs(dep + 1, stat);
		}
		else
		if (b[dep] == '?') {
			if (stat == 0) {
				b[dep] = a[dep];
				dfs(dep + 1, 0);
				b[dep] = a[dep] + 1;
				if (b[dep] > '9') b[dep] = '9';
				if (a[dep] < b[dep])
				dfs(dep + 1, 1);
				b[dep] = a[dep] - 1;
				if (b[dep] < '0') b[dep] = '0';
				if (a[dep] > b[dep])
				dfs(dep + 1, -1);
			}
			if (stat == 1) {
				b[dep] = '0';
				dfs(dep + 1, stat);
			}
			if (stat == -1) {
				b[dep] = '9';
				dfs(dep + 1, stat);
			}

		}
		else {
			if (stat == 0) {
				int flag = a[dep] != b[dep];
				int ff = a[dep] > b[dep] ? -1 : 1;
				dfs(dep + 1, flag ? ff : 0);
			}
			else
				dfs(dep + 1, stat);
		}
	}
	a[dep] = ta; b[dep] = tb;
}
int main() {
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
	scanf("%d", &cas);
	for (cases = 1; cases <= cas; cases ++) {
		ans = LC = LJ = INFll;
		scanf("%s%s", a, b);
		len = strlen(a);
		dfs(0, 0);
		printf("Case #%d: ", cases);
		for (int i = 0; i < len; i++)
			printf("%c", c[i]);
		printf(" ");
		for (int i = 0; i < len; i++)
			printf("%c", j[i]);
		printf("\n");
	}
}
