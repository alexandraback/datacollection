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

#ifdef LOCAL_DEBUG
const int SZ = 100;
#else
const int SZ = 200005;
#endif

const ll maxVal = 1e9;

struct quat {
	int oneIdx;
	bool minus;
	quat(int _oneIdx = 0) {
		oneIdx = _oneIdx;
		minus = 0;
	}
	quat operator*=(const quat & other) {
		quat res;
		res.minus = minus ^ other.minus;
		switch (oneIdx) {
		case 0: {
			switch (other.oneIdx)
			{
			case 0:
				res.oneIdx = 0;
				break;
			case 1:
				res.oneIdx = 1;
				break;
			case 2:
				res.oneIdx = 2;
				break;
			case 3:
				res.oneIdx = 3;
				break;
			}
		}
				break;
		case 1: {
			switch (other.oneIdx)
			{
			case 0:
				res.oneIdx = 1;
				break;
			case 1:
				res.oneIdx = 0;
				res.minus ^= 1;
				break;
			case 2:
				res.oneIdx = 3;
				break;
			case 3:
				res.oneIdx = 2;
				res.minus ^= 1;
				break;
			}
		}
				break;
		case 2: {
			switch (other.oneIdx)
			{
			case 0:
				res.oneIdx = 2;
				break;
			case 1:
				res.oneIdx = 3;
				res.minus ^= 1;
				break;
			case 2:
				res.oneIdx = 0;
				res.minus ^= 1;
				break;
			case 3:
				res.oneIdx = 1;
				break;
			}
		}
				break;
		case 3: {
			switch (other.oneIdx)
			{
			case 0:
				res.oneIdx = 3;
				break;
			case 1:
				res.oneIdx = 2;
				break;
			case 2:
				res.oneIdx = 1;
				res.minus ^= 1;
				break;
			case 3:
				res.oneIdx = 0;
				res.minus ^= 1;
				break;
			}
		}
				break;
		}
		*this = res;
		return res;
	}
};

char S[25000];

int chrToQuat(char chr) {
	switch (chr) {
	case 'i':
		return 1;
	case 'j':
		return 2;
	case 'k':
		return 3;
	}
}

void test() {
	int l, x;
	scanf("%d%d", &l, &x);
	scanf(" %s", S);
	int idx = 0;
	int curQuatNeeded = 1;
	int lastPassed = 0;
	quat curQuat;
	bool good = false;
	int totalPassed = 0;
	int loopSize = 4;
	rep(i, 0, 3) {
		rep(j, 0, l) {
			int cq = chrToQuat(S[j]);
			curQuat *= quat(cq);
		}
		if (curQuat.oneIdx == 0 && curQuat.minus == 0) {
			loopSize = i + 1;
			break;
		}
	}

	curQuat = quat(0);
	while (1) {
		if (idx == l) {
			idx = 0;
			x--;
		}
		if (curQuatNeeded == 4 && curQuat.minus == 0 && idx == 0 && curQuat.oneIdx == 0) {
			if (x % loopSize == 0)
				good = true;
			else 
				good = false;
			break;
		}
		if (x == 0)
			break;
		if (lastPassed > 5 * l)
			break;
		int cq = chrToQuat(S[idx++]);
		lastPassed++;
		curQuat *= quat(cq);
		if (curQuat.minus == 0 && curQuat.oneIdx == curQuatNeeded) {
			curQuatNeeded++;
			curQuat.oneIdx = 0;
			lastPassed = 0;
		}
	}
	if (good) {
		printf("YES\n");
	}
	else {
		printf("NO\n");
	}
}

void run()
{
	int t = 0;
	scanf("%d", &t);
	rep(i, 0, t) {
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