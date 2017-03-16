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
#include <limits>

#ifdef _MSC_VER
#  include <intrin.h>
#  define __builtin_popcount __popcnt
#endif

using namespace std;

template<typename T> T mabs(const T &a){ return a<0 ? -a : a; }
#define rep(x,y,z) for(int x=(y),e##x=(z);x<e##x;x++)
#define SQR(x) ((x)*(x))
#define all(c) (c).begin(), (c).end()

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef short int si;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ll, int> pli;
typedef pair<int, ll> pil;


void init() {
	//return;
	//memset(dyn, -1, sizeof(dyn));
	//dyn[1] = 1;
	//bfs();
}

static constexpr ll mmax = numeric_limits<ll>::max();

ll bestRes, bestA, bestB;

ll getDiff(const std::string& first, const string& second, int position, int sgn) {
    ll numA = 0, numB = 0;
    for (int i = 0; i < first.size(); i++) {
        numA *= 10;
        numB *= 10;
        char ca = first[i], cb = second[i];
        if (ca == '?') {
            if (cb == '?') {
                if (i < position) {
                }
                else if (i == position) {
                    if (sgn > 0) 
                        numA += 1;
                    else
                        numB += 1;
                }
                else {
                    if (sgn > 0)
                        numB += 9;
                    else
                        numA += 9;
                }
            }
            else {
                int cbi = cb - '0';
                numB += cbi;
                if (i < position) {
                    numA += cbi;
                }
                else if (i == position) {
                    if (sgn > 0) {
                        if (cbi == 9)
                            return mmax;
                        numA += cbi + 1;
                    }
                    else {
                        if (cbi == 0)
                            return mmax;
                        numA += cbi - 1;
                    }
                }
                else {
                    if (sgn < 0)
                        numA += 9;
                }
            }
        }
        else {
            int cai = ca - '0';
            if (cb == '?') {
                numA += cai;
                if (i < position) {
                    numB += cai;
                }
                else if (i == position) {
                    if (sgn > 0) {
                        if (cai == 0)
                            return mmax;
                        numB += cai - 1;
                    }
                    else {
                        if (cai == 9)
                            return mmax;
                        numB += cai + 1;
                    }
                }
                else {
                    if (sgn > 0)
                        numB += 9;
                }
            } else {
                int cbi = cb - '0';
                numA += cai;
                numB += cbi;
                if (i < position) {
                    if (cai != cbi)
                        return mmax;
                } if (i == position) {
                    if (sgn > 0) {
                        if (cai < cbi)
                            return mmax;
                    }
                    else
                    {
                        if (cbi < cai)
                            return mmax;
                    }
                }
            }
        }
    }
    ll curRes = numA - numB;
    if (curRes < 0)
        curRes = -curRes;
    if (curRes < bestRes || curRes == bestRes && numA < bestA || 
        curRes == bestRes && numA == bestA && numB < bestB) {
        bestRes = curRes;
        bestA = numA;
        bestB = numB;
    }
    return curRes;
}

void printNum(ll num, int count) {
    ll pt = 1;
    rep(i, 0, count - 1)
        pt *= 10;
    rep(i, 0, count) {
        printf("%d", num / pt);
        num %= pt;
        pt /= 10;
    }
}

void test() {
    char A[30], B[30];
    bestRes = mmax;
    scanf(" %s %s", A, B);
    int n = strlen(A);
    rep(i, 0, n + 1) {
        for (int j = -1; j <= 1; j += 2) {
            getDiff(A, B, i, j);
        }
    }
    printNum(bestA, n);
    printf(" ");
    printNum(bestB, n);
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
	freopen("test.in", "r", stdin);
	freopen("test.out", "w", stdout);
	time_t st = clock();
#else 
#ifdef prob
	freopen(prob".in", "r", stdin);
	freopen(prob".out", "w", stdout);
#endif
#endif

	run();

#ifdef LOCAL_DEBUG
	fprintf(stderr, "\n=============\n");
	fprintf(stderr, "Time: %.2lf sec\n", (clock() - st) / double(CLOCKS_PER_SEC));
#endif

	return 0;
}