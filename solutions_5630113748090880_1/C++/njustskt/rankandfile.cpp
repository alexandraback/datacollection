/*************************************************************************
	> File Name: rankandfile.cpp
	> Author: skt
	> Mail: sktsxy@gmail.com
	> Created Time: 2016年04月16日 星期六 09时13分28秒
 ************************************************************************/

#include <cstring>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <queue>
#include <bitset>
#include <algorithm>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <complex>
#include <cassert>
// #pragma comment(linker,"/STACK:102400000,102400000")
using namespace std;
#define LL long long
#define pb push_back
#define mp make_pair
#define x first
#define y second
template <typename T> inline void checkMax(T &a, T b) {a = a>b?a:b;}
template <typename T> inline void checkMin(T &a, T b) {a = a<b?a:b;}
typedef pair<int, int> PII;
typedef vector<int> vi;
const double PI = acos(-1.0);
const double eps = 1e-8;
const int N = 50 + 5;
int T, Cas = 1, n;

int a[N * 2][N];
vector<int> vec, ans;

void work() {
    vec.clear();
    ans.clear();
    printf("Case #%d: ", Cas ++);
    scanf("%d", &n);
    for (int i = 1; i <= 2 * n - 1; i ++) {
        for (int j = 1; j <= n; j ++) {
            scanf("%d", &a[i][j]);
            vec.push_back(a[i][j]);
        }
    }
    sort(vec.begin(), vec.end());
    for (int i = 0; i < vec.size(); i ++) {
        int sz = 0;
        for (int j = 0; j < vec.size(); j ++) {
            if (vec[i] == vec[j]) {
                sz ++;
            }
        }
        if (sz & 1) {
            ans.push_back(vec[i]);
        }
    }
    sort(ans.begin(), ans.end());
    ans.erase(unique(ans.begin(), ans.end()), ans.end());
    for (int i = 0; i < ans.size(); i ++) {
        printf("%d%c", ans[i], " \n"[i + 1 == (int)ans.size()]);
    }
}
int main() {
    scanf("%d", &T);
    while (T --) {
        work();
    }
    return 0;
}
