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

void init() {
}

bool validate(const vector<ll>& ans, int k, int c) {
    vector<int> wasHere(k, 0);
    rep(i, 0, ans.size()) {
        ll ca = ans[i];
        rep(i, 0, c) {
            ll cInd = ca % k;
            ca /= k;
            wasHere[cInd] = 1;
        }
    }
    rep(i, 0, k) {
        if (wasHere[i] == 0) {
            printf("BIDA!!\n");
        }
    }
    return true;
}

void test() {
    ll k, c, s;
    scanf("%lld%lld%lld", &k, &c, &s);
    if (c * s < k) {
        printf("IMPOSSIBLE\n");
        return;
    }
    ll kc = 1;
    rep(i, 0, c) {
        kc *= k;
    }

    int toTake = (k + c - 1) / c;

    int covered = 0;
    vector<ll> curAns;
    rep(taken, 0, toTake) {
        ll cur = covered;
        covered++;
        rep(i, 1, c) {
            if (covered == k)
                cur = cur * k;
            else {
                cur = cur * k + covered;
                covered++;
            }
        }
        //if (cur >= kc) {
        //    printf("BIDA!\n");
        //    throw 1;
        //}
        printf("%lld ", cur + 1);
        curAns.push_back(cur);
    }
    if (curAns.size() > s)
        throw 1;
    validate(curAns, k, c);
    printf("\n");
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