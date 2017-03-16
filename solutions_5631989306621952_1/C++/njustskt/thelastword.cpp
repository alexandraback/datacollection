/*************************************************************************
	> File Name: thelastword.cpp
	> Author: skt
	> Mail: sktsxy@gmail.com
	> Created Time: 2016年04月16日 星期六 09时05分02秒
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
const int N = 1000 + 5;
int T, Cas = 1;
char str[N];

void work() {
    printf("Case #%d: ", Cas ++);
    scanf("%s", str + 1);
    int n = strlen(str + 1);
    string ans = "";
    for (int i = 1; i <= n; i ++) {
        if (i == 1) {
            ans = ans + str[i];
        } else {
            string ans1 = ans + str[i];
            string ans2 = str[i] + ans;
            if (ans1 > ans2) {
                ans = ans1;
            } else {
                ans = ans2;
            }
        }
    }
    cout << ans << endl;
}
int main() {
    scanf("%d", &T);
    while (T --) {
        work();
    }
    return 0;
}
