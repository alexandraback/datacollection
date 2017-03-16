#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cstdio>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <utility>
#include <vector>

using namespace std;

typedef long long ll;

#define REP(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
#define FOR(i,b,e) for(int (i)=(b);(i)<(int)(e);(i)++)
#define CFOR(i,b,e) for(int (i)=(b);(i)<=(int)(e);(i)++)
#define FOREACH(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)
#define PI 3.1415926535897932384626433832795
#define INF 0x7FFFFFFF

int T;
int R, C, W;
int a[20+2];


int main(int argc, char **argv)
{
    cin >> T;
    for (int t = 0;t < T;t++) {
        memset(a, 0, sizeof(a));
        cin >> R >> C >> W;

        a[W] = 0;
        for (int c = W + 1;c <= C;c++) {
            int best = INF;
            for (int i = 0;i < c;i++) {
                if (i < W && c - i - 1 < W) {
                    best = 1;
                } else if (i < W && c - i - 1 >= W) {
                    int temp = a[c - i - 1] + 1;
                    best = min(best, temp);
                } else if (i >= W && c - i - 1 < W) {
                    int temp = a[i] + 1;
                    best = min(best, temp);
                } else {
                    int temp = a[i] + a[c - i - 1] + 2;
                    best = min(best, temp);
                }
            }
            a[c] = best;
        }

        int ans = a[C] * R + R - 1 + W;

        cout << "Case #" << t + 1 << ": ";

        cout << ans;
        cout << endl;
    }

    return 0;
}

