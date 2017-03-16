#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>

using namespace std;

#define REP(i,N) for((i)=0;(i)<int(N);(i)++)
#define REPI(i,N) for((i)=1;(i)<=int(N);(i)++)
#define foreach(c,it) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
#define all(c) (c).begin(), (c).end()
#define pb push_back
#define mp make_pair
#define ST first
#define ND second

#define MAXN 109

int a[MAXN], b[MAXN];


int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int T, N, i, ans;
    long long A;

    cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        cin >> A >> N;
        REP(i,N) scanf("%d", a+i);
        sort(a,a+N);
        if (A == 1) {
            ans = N;
        } else {
            ans = 0;
            REP(i, N) {
                while (A <= a[i]) {
                    ans++;
                    A += A - 1;
                }
                A += a[i];
                b[i] = ans;
            }
            ans = min(ans, N);
            REP(i, N) ans = min(ans, b[i] + N - i - 1);
        }
        cout << "Case #" << tc << ": " << ans << endl;
    }
}
