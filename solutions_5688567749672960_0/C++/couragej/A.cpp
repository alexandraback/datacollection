#include <functional>
#include <algorithm>
#include <stdexcept>
#include <iostream>
#include <sstream>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <utility>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <cctype>
#include <cstdio>
#include <vector>
#include <string>
#include <bitset>
#include <cmath>
#include <queue>
#include <stack>
#include <ctime>
#include <list>
#include <map>
#include <set>

#define REP(i,n) for(int i=0;i<(n);i++)
#define TR(i,x) for(__typeof(x.begin()) i=x.begin();i!=x.end();i++)
#define ALL(x) x.begin(),x.end()
#define SORT(x) sort(ALL(x))
#define CLEAR(x) memset(x,0,sizeof(x))
#define FILL(x,c) memset(x,c,sizeof(x))
#define SIZE(x) (int)(x).size()

#define MP make_pair
#define PB push_back

using namespace std;

typedef long long LL;
typedef pair<int,int> PII;

const int MAXN = 1e6 + 10;

int dis[MAXN], q[MAXN];

int Reverse(int x) {
    int ret = 0;
    for (; x; x /= 10) {
        ret = ret * 10 + x % 10;
    }
    return ret;
}

void Solve() {
    int N;
    cin >> N;
    FILL(dis, 0x3f);
    dis[0] = 0;
    q[0] = 0;
    for (int h = 0, t = 1; h < t; ++h) {
        int u = q[h];
        if (u + 1 <= N && dis[u + 1] > dis[u] + 1) {
            dis[u + 1] = dis[u] + 1;
            q[t++] = u + 1;
        }
        int rev = Reverse(u);
        if (rev <= N && dis[rev] > dis[u] + 1) {
            dis[rev] = dis[u] + 1;
            q[t++] = rev;
        }
        if (dis[N] < 0x3f3f3f3f) break;
    }
    cout << dis[N] << endl;
}

int main() {
//	freopen("A.in","r",stdin);
	freopen("A-small-attempt0.in","r",stdin);freopen("A-small-attempt0.out","w",stdout);
//	freopen("A-small-attempt1.in","r",stdin);freopen("A-small-attempt1.out","w",stdout);
//	freopen("A-small-attempt2.in","r",stdin);freopen("A-small-attempt2.out","w",stdout);
//	freopen("A-large.in","r",stdin);freopen("A-large.out","w",stdout);
    int cas;
    cin >> cas;
    for (int T = 1; T <= cas; ++T) {
        printf("Case #%d: ", T);
        Solve();
        cerr << "Case #" << T << ": done!" << endl;
    }
    return 0;
}

