#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <time.h>
#include <cctype>
#include <functional>
#include <deque>
#include <iomanip>
#include <bitset>
#include <assert.h>
#include <numeric>
#include <sstream>
#include <utility>

#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(a) (a).begin(),(a).end()
#define FOR(i,a,b) for (int i=(a);i<(b);i++)
#define FORD(i,a,b) for (int i=(a); i>=(b); i--)
#define REP(i,b) FOR(i,0,b)
#define ll long long
#define sf scanf
#define pf printf
using namespace std;
const int maxint = -1u>>1;
const double pi = 3.14159265358979323;
const double eps = 1e-8;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<int>::iterator vit;
const int totdic = 521196;

ll now;
int n, ans;
vector<int> vec;
int main() {
    freopen("A-large.in", "r", stdin);
    freopen("A-large.out", "w", stdout);
    int T, Case = 1;
    cin >> T;
    while (T--) {
        cin >> now >> n;
        vec.resize(n);
        for (int i = 0, x; i < n; i++) {
            cin >> vec[i];
        }
        sort(vec.begin(), vec.end());
        int l = 0;
        while (l < n) {
            if (now > vec[l]) now += vec[l++];
            else break;
        }
        int ans = n - l;
        if (now != 1) {
            int tmp = 0;
            for (int i = l; i < n; i++) {
                while (now <= vec[i]) {
                    now += now - 1;
                    tmp++;
                }
                now += vec[i];
                ans = min(ans, tmp + n - i - 1);
            }
        }
        printf("Case #%d: ", Case++);
        cout << ans << endl;
    }
    return 0;
}
