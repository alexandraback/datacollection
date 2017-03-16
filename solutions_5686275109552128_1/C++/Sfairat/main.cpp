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
typedef pair<double, int> pdi;

#ifdef LOCAL_DEBUG
const int SZ = 100;
#else
const int SZ = 200005;
#endif

const ll maxVal = 1e9;

void test() {
	int minSteps = 0, maxSteps = 200000;
	//int minSteps = 0, maxSteps = 2;
	int d;
	scanf("%d", &d);
	vector<int> cookies;
	rep(i, 0, d) {
		int cur;
		scanf("%d", &cur);
		cookies.push_back(cur);
	}
	int bestRes = maxSteps;
	while (minSteps <= maxSteps) {
		int mid = (minSteps + maxSteps) / 2;
		int cm = mid;
		priority_queue<pii> pq;
		vector<int> counts(d, 1);
		rep(i, 0, d) {
			pq.push({ (cookies[i] + counts[i] - 1) / counts[i], i });
		}

		bool can = false;
		while (cm > 0) {
			pii tp = pq.top();
			if (tp.first <= cm) {
				can = true;
				break;
			}
			pq.pop();
			int idx = tp.second;
			counts[idx]++;
			pq.push({ (cookies[idx] + counts[idx] - 1) / counts[idx], idx });
			cm--;
		}
		if (can) {
			bestRes = mid;
			maxSteps = mid - 1;
		}
		else
			minSteps = mid + 1;
	}
	printf("%d\n", bestRes);
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