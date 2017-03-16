/*                    _oo0oo_
                     o8888888o
                     88" . "88
                     (| -_- |)
                     0\  =  /0
                   ___/`---'\___
                 .' \\|     |// '.
                / \\|||  :  |||// \
               / _||||| -:- |||||_ \
              |   | \\\  _  /// |   |
              | \_|  ''\___/''  |_/ |
              \  .-\__  '_'  __/-.  /
            ___'. .'  /--.--\  `. .'___
         ."" '<  `.___\_<|>_/___.'  >' "".
        | | :  `- \`.;`\ _ /`;.`/ -`  : | |
        \  \ `_.   \_ __\ /__ _/   ._` /  /
    =====`-.____`.___ \_____/ ___.`____.-`=====
                      `=---='


    ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

             ·ð×æ±£ÓÓ         ÓÀÎÞBUG
*/

#include<iostream>
#include<iomanip>
#include<fstream>
#include<sstream>
#include<cstring>
#include<cctype>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<vector>
#include<list>
#include<map>
#include<set>
#include<deque>
#include<queue>
#include<stack>
#include<bitset>
#include<utility>
#include<string>
#include<ctime>
#include<numeric>
#include<functional>
using namespace std;

#define _FIO_

#define eps 1e-8
const double PI = acos(-1.0);
#define LL long long
#define ULL unsigned long long
#define MP make_pair
#define wait system( "pause" );
#define sqr(x) ((x)*(x))

LL reverse(LL n) {
	stringstream ss;
	ss << n;
	string str = ss.str();
	LL ans = 0;
	int len = str.size();
	for (int i = len - 1; i >= 0; --i)
		ans = ans * 10 + str[i] - '0';
	return ans;
}

#define MAXN 10000000
LL ans[MAXN];
queue<LL> q;

int main() {
#ifdef _FIO_
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _FIO_
	memset(ans, 0, sizeof(ans));
	while (!q.empty())
		q.pop();
	q.push(1);
	ans[1] = 1;
	LL v;
	while (!q.empty()) {
		LL u = q.front();
		q.pop();
		v = u + 1;
		if (v < MAXN)
			if (!ans[v]) {
				ans[v] = ans[u] + 1;
				q.push(v);
			}
		v = reverse(u);
		if (v < MAXN)
			if (!ans[v]) {
				ans[v] = ans[u] + 1;
				q.push(v);
			}
		if (u % 10 == 0) {
			v = reverse(v);
			if (v < MAXN)
				if (!ans[v]) {
					ans[v] = ans[u] + 1;
					q.push(v);
				}
		}
	}
	//printf("READY\n");
	int t;
	LL n;
	scanf("%d", &t);
	for (int ca = 1; ca <= t; ++ca) {
		scanf("%lld", &n);
		printf("Case #%d: %lld\n", ca, ans[n]);
	}
#ifdef _FIO_
	fclose(stdin);
	fclose(stdout);
#endif // _FIO_
	return 0;
}
