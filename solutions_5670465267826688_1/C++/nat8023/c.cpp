#include <cstdio>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <ctime>
//#include <cmath>
#include <vector>
#include <map>
using namespace std;
typedef long long LL;
typedef pair<int,int> pint;
typedef pair<LL,LL> pll;
#define fi first
#define se second
typedef map<int,int> mapint;
typedef vector<int> vint;
typedef vector<vint> vintp;
#define rep(i,j,k) for (int i = (j);i <= (k);i ++)
#define repd(i,j,k) for (int i = (j);i >= (k);i --)
#define ran2 (rand() % 32000 * 32000 + rand() % 32000)
#define pb push_back
#define mp make_pair
#define SIZE(i) ((int)(i.size()))
int j,k,l,i,o,p,__t;
LL m, n;
char ch;
void read(int &a) {
	for (ch = getchar();(ch < '0' || ch > '9') && (ch != '-');ch = getchar());
	if (ch == '-') a = 0,__t = -1; else a = ch - '0',__t = 1;
	for (ch = getchar();ch >= '0' && ch <= '9';ch = getchar()) a = a * 10 + ch - '0';
	a *= __t;
}

string s;

int a[1010100];

int val(char s) {
	if (s == 'i')
		return 1;
	if (s == 'j')
		return 2;
	if (s == 'k')
		return 3;
	return 0;
}

const int k_add[4][4] = {{0, 1, 2, 3}, {1, 4, 3, 6}, {2, 7, 4, 1}, {3, 2, 5, 4}};


int add(int i, int j) {
	int mul = j / 4, mul2 = i / 4;
	return k_add[i % 4][j % 4] ^ (4 * mul) ^ (4 * mul2);
}

int F[60][3][10][3][10];

int G[2][3][10];

int ans[3][10][3][10], temp[3][10][3][10];

void prepare(int init_sta, int init_last) {
	

	memset(G, 0, sizeof G);
	int now = 0, pre = 1;

	G[now][init_sta][init_last] = 1;

	rep(i, 0, m - 1) {
		now ^= 1, pre ^= 1;
		memset(G[now], 0, sizeof G[now]);

		rep(pre_sta, 0, 2)
		rep(pre_last, 0, 7)
		if (G[pre][pre_sta][pre_last]) {
			if (pre_sta + 1 == pre_last && pre_sta != 2)
				G[now][pre_sta + 1][a[i]] = 1;
			G[now][pre_sta][add(pre_last, a[i])] = 1;
		}
	}

	rep(now_sta, 0, 2)
		rep(now_last, 0, 7)
			F[0][init_sta][init_last][now_sta][now_last] = G[now][now_sta][now_last];
}

void meger(int index) {
	memset(temp, 0, sizeof temp);

	rep(pre_sta, 0, 2)
	rep(suf_sta, pre_sta, 2)
	rep(middle_sta, pre_sta, suf_sta)
	rep(pre_first, 0, 7)
	rep(pre_last, 0, 7)// == suf_first
	rep(suf_last, 0, 7)
	temp[pre_sta][pre_first][suf_sta][suf_last] |= 
		ans[pre_sta][pre_first][middle_sta][pre_last] &
		F[index][middle_sta][pre_last][suf_sta][suf_last];
	memcpy(ans, temp, sizeof temp);
}

void solve() {
	if (n & 1)
		meger(0);	

	for (LL j = 1, k = 2; k <= n; k *= 2LL, j ++) {
		memset(F[j], 0, sizeof F[j]);

		rep(pre_sta, 0, 2)
		rep(suf_sta, pre_sta, 2)
		rep(middle_sta, pre_sta, suf_sta)
		rep(pre_first, 0, 7)
		rep(pre_last, 0, 7)// == suf_first
		rep(suf_last, 0, 7)
		F[j][pre_sta][pre_first][suf_sta][suf_last] |= 
			F[j - 1][pre_sta][pre_first][middle_sta][pre_last] &
			F[j - 1][middle_sta][pre_last][suf_sta][suf_last];

		if (n & k)
			meger(j);
	}
}

int main() {
	freopen("c.in","r",stdin);
	freopen("c.out","w",stdout);

	int cas, result;
	cin >> cas;
	

	for (int id = 1; id <= cas; id ++) {
		cerr << id << endl;
		cin >> m >> n;
		cin >> s;
		rep(i, 0, s.size() - 1)
			a[i] = val(s[i]);
		memset(F[0], 0, sizeof F[0]);
		rep(i, 0, 2) 
		rep(j, 0, 7) {
			prepare(i, j);
		}

		memset(ans, 0, sizeof ans);
		ans[0][0][0][0] = 1;

		solve();

		result = ans[0][0][2][3];

		printf("Case #%d: %s\n", id, result == 1 ? "YES" : "NO");
	}

	//fclose(stdin); fclose(stdout);
}
