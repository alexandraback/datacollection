
#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <cassert>

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
#define MP make_pair
#define FOR(v,p,k) for(int v=p;v<=k;++v)
#define FORD(v,p,k) for(int v=p;v>=k;--v)
#define REP(i,n) for(int i=0;i<(n);++i)
#define VAR(v,i) __typeof(i) v=(i)
#define FORE(i,c) for(__typeof(c.begin()) i=(c.begin());i!=(c).end();++i)
#define PB push_back
#define ST first
#define ND second
#define SZ(x) (int)(x).size()
#define ALL(c) c.begin(),c.end()
#define ZERO(x) memset(x,0,sizeof(x))

void go(int x, char dec, char inc) {
    swap(dec, inc);
    while (x > 0) {
        cout << inc << dec;
        --x;
    }
}

int main() {
    int d;
    cin >> d;
    for (int i = 0; i < d; ++i) {
        cout << "Case #" << i + 1 << ": ";
        int x, y;
        cin >> x >> y;
        if (x < 0) {
            go(-x, 'E', 'W');
        } else {
            go(x, 'W', 'E');
        }
        if (y < 0) {
            go(-y, 'N', 'S');
        } else {
            go(y, 'S', 'N');
        }
        cout << endl;
    }
}
