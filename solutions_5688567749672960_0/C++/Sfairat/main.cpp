#include <iostream>
#include <iomanip>
#include <cstdio>
#include <bitset>
#include <memory>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <list>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <stack>
#include <complex>
#include <wchar.h>
#include <wctype.h>
#include <cmath>
#include <queue>
#include <ctime>
#include <numeric>
#include <unordered_map>
#include <unordered_set>

using namespace std;

template<typename T> T mabs(const T &a){ return a<0?-a:a;}
#define rep(x,y,z) for(int x=(y),e##x=(z);x<e##x;x++)
#define SQR(x) ((x)*(x))
#define all(c) (c).begin(), (c).end()

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef short int si;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<ll,int> pli;
typedef pair<int,ll> pil;

int dyn[(int)1e8];

ll calcRev(ll num) {
	int res = 0;
	while (num > 0) {
		int rem = num % 10;
		num /= 10;
		res = res * 10 + rem;
	}
	return res;
}

void bfs() {
	queue<int> pos;
	pos.push(1);
	dyn[1] = 1;
	int maxVal = 5e6;
	while (!pos.empty()) {
		int num = pos.front();
		pos.pop();
		int v1 = num + 1;
		if (v1 < maxVal && dyn[v1] == -1) {
			dyn[v1] = dyn[num] + 1;
			pos.push(v1);
		}
		int v2 = calcRev(num);
		if (v2 < maxVal && dyn[v2] == -1) {
			dyn[v2] = dyn[num] + 1;
			pos.push(v2);
		}
	}
}

ll getFirstHalf(ll num, ll tp, ll ctp) {
	ll res = 0;
	rep(i, 0, ctp / 2) {
		res *= 10;
		res += num / tp % 10;
		tp /= 10;
	}
	return res;
}

ll getSecondHalf(ll num, ll tp, ll ctp) {
	ll res = 0;
	ll mtp = 1;
	rep(i, 0, (ctp + 1) / 2) {
		res += num / mtp % 10 * mtp;
		mtp *= 10;
	}
	return res;
}

ll calcFast(ll num) {
	ll ctp = 1;
	ll ctpc = 1;
	ll count = 0;
	if (num < 10)
		return num;
	count = 1;
	while (ctp * 10 <= num) {
		ll tp1 = 1;
		rep(i, 0, (ctpc + 1) / 2) {
			tp1 *= 10;
		}
		ll tp2 = 1;
		rep(i, 0, ctpc / 2) {
			tp2 *= 10;
		}
		count += tp1 - 1 + tp2 - 1 + 1;
		if (ctp == 1) {
			count--;
		}
		ctpc++;
		ctp *= 10;
	}
	ll firstHalf = getFirstHalf(num, ctp, ctpc), secondHalf = getSecondHalf(num, ctp, ctpc);
	ll fhRev = calcRev(firstHalf);
	if (secondHalf == 0) {
		count = calcFast(num - 1) + 1;
	}
	else if (fhRev == 1) {
		count += secondHalf;
	}
	else {
		count += fhRev + 1 + secondHalf - 1;
	}
	return count;
}

void init() {
	//return;
	memset(dyn, -1, sizeof(dyn));
	dyn[1] = 1;
	bfs();
}

void test() {
	ll num;
	scanf(" %lld", &num);

	ll res = calcFast(num);
	//if (res != dyn[num])
	//	throw 1;
	//printf("%lld %lld\n", res, dyn[num]);
	printf("%lld\n", res);

	//rep(n, 1, 5e7) {
	//	ll num = n;
	//	ll trueRes = dyn[num];
	//	ll fastRes = calcFast(num);
	//	if (trueRes != fastRes) {
	//		printf("BIDA!! %lld %lld %lld\n", num, trueRes, fastRes);
	//	}
	//}
}

void run()
{
	init();
	int tc;
	scanf("%d", &tc);
	rep(i, 0, tc) {
		printf("Case #%d: ", i + 1);
		test();
	}
}

//#define prob "fence"

int main()
{
#ifdef LOCAL_DEBUG
    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);
    time_t st=clock();
#else 
#ifdef prob
    freopen(prob".in","r",stdin);
    freopen(prob".out","w",stdout);
#endif
#endif

    run();

#ifdef LOCAL_DEBUG
    fprintf(stderr, "\n=============\n");
    fprintf(stderr, "Time: %.2lf sec\n",(clock()-st)/double(CLOCKS_PER_SEC));
#endif
    
    return 0;
}