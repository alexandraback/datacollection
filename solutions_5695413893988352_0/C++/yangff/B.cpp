#include <cstdio>
#include <cctype>
#include <cstring>
#include <iostream>
#include <iomanip>

using namespace std;

char buf1[22], buf2[22];

int a[22], b[22];

struct _ans {
	long long x, y, v;
	void init(){
		y = v = x = 0x7FFFFFFFFFFFFFFFLL;
	}
};

bool gFlag = false;

bool cmp(_ans a, _ans b){
	if (a.v < b.v)
		return true;
	else 
		if (a.v == b.v)
			if (b.x > a.x)
				return true;
			else if (b.x == a.x && b.y > a.y)
				return true;
	return false;
}

void update(_ans &t, _ans a){
	if (cmp(a, t)) 
		t = a;
}

_ans ans[20][2];

_ans calc(int *a, int *b, int n){
	for (int i = 0; i <= n; i++)
		for (int j = 0; j < 2; j++)
			ans[i][j].init();
	ans[0][0].x = ans[0][0].y = 0; ans[0][0].v = 0;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < 2; j++)
			if (ans[i][j].v != 0x7FFFFFFFFFFFFFFFLL) {
				for (int x = 0; x < 10; x++) if (a[i + 1] == -1 || a[i + 1] == x)
				for (int y = 0; y < 10; y++) if (b[i + 1] == -1 || b[i + 1] == y) {
					int cp = gFlag ? y - x : x - y;
					if (j == 0 && cp < 0) continue;
					_ans next; next.v = ans[i][j].v * 10LL + cp;
					next.x = ans[i][j].x * 10LL + x;
					next.y = ans[i][j].y * 10LL + y;
					update(ans[i + 1][(j == 1) || (j == 0 && cp > 0)], next);
				}
			}
	if (cmp(ans[n][0], ans[n][1]))
		return ans[n][0];
	else
		return ans[n][1];
}

int main() {
	freopen("B.in", "r", stdin);
	freopen("B.out", "w", stdout);

	int T; scanf("%d", &T);
	for (int cas = 1; cas <= T; cas++){
		printf("Case #%d: ", cas);
		scanf("%s%s", buf1, buf2);
		int n = strlen(buf1);
		for (int i = 0; i < n; i++) {
			if (isdigit(buf1[i])) a[i + 1] = buf1[i] - '0'; else a[i + 1] = -1;
			if (isdigit(buf2[i])) b[i + 1] = buf2[i] - '0'; else b[i + 1] = -1;
		}
		gFlag = false;
		_ans ans1 = calc(a,b,n);
		gFlag = true;
		_ans ans2 = calc(a,b,n);
		_ans Ans;
		if (cmp(ans1, ans2))
			Ans = ans1;
		else Ans = ans2;
		cout << setfill('0') << setw(n) << Ans.x;
		cout << " ";
		cout << setfill('0') << setw(n) << Ans.y << endl;
	}
}