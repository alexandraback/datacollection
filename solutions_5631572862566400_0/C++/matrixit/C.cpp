#define _CRT_SECURE_NO_WARNINGS
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
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
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>

using namespace std;

typedef long long int64;
typedef unsigned long long uint64;
#define two(X) (1<<(X))
#define twoL(X) (((int64)(1))<<(X))
#define contain(S,X) (((S)&two(X))!=0)
#define containL(S,X) (((S)&twoL(X))!=0)
const double pi = acos(-1.0);
const double eps = 1e-11;
template<class T> inline void checkmin(T &a, T b) { if (b<a) a = b; }
template<class T> inline void checkmax(T &a, T b) { if (b>a) a = b; }
template<class T> inline T sqr(T x) { return x*x; }
typedef pair<int, int> ipair;
#define SIZE(A) ((int)A.size())
#define LENGTH(A) ((int)A.length())
#define MP(A,B) make_pair(A,B)
#define PB(X) push_back(X)

#define MAX 1010
int T;
int N;
int must[MAX];
int visited[MAX];

//bool valid(vector<int> &v) {
//    for (int i = 0; i < v.size(); ++i) {
//        if (v[(i + v.size() - 1) % v.size()] != must[v[i]] && v[(i + v.size() + 1) % v.size() != must[v[i]]]) {
//            return false;
//        }
//    }
//    return true;
//}
//int ok(int x) {
//    vector<int> per;
//    for (int i = 0; i < x; ++i) {
//        per.push_back(i + 1);
//    }
//    do {
//        if (valid(per)) {
//            return true;
//        }
//    }
//    while (next_permutation(per.begin(), per.end()));
//    return false;
//}
int loop = 0;
int start_from(int s) {
    memset(visited, 0, sizeof(visited));
    memset(visited + N + 1, 1, sizeof(int) * (MAX - N - 1));
    visited[0] = 1;
    int head, tail;
    int cnt = 1;
    for (head = tail = s, visited[s] = 1; !visited[must[tail]]; ) {
        tail = must[tail];
        visited[tail] = 1;
        ++cnt;
    }
    int ans = cnt;
    if (!(must[tail] == head)) {
        ans = 0;
    }
    else {
        if (ans == 2) ++loop;
    }
    return ans;
}

vector<int> get_path(int s) {
    vector<int> ans;
    if (visited[s]) {
        return ans;
    }
    int head, tail;
    int cnt = 1;
    ans.push_back(s);
    for (head = tail = s, visited[s] = 1; !visited[must[tail]]; ) {
        tail = must[tail];
        ans.push_back(tail);
        visited[tail] = 1;
        ++cnt;
    }
    return ans;
}

int merge(int s1, int s2) {
    memset(visited, 0, sizeof(visited));
    memset(visited + N + 1, 1, sizeof(int) * (MAX - N - 1));
    visited[0] = 1;
    auto p1 = get_path(s1);
    auto p2 = get_path(s2);
    int ans = 0;
    bool flag = must[p1.back()] == p1[p1.size() - 2];
    if (p2.size() == 0) {
        return flag ? p1.size() : 0;
    }
    if (must[p2.back()] == p1.back()) {
        ans = flag ? p1.size() + p2.size() : 0;
    }
    else if (flag) {
        ans = p1.size();
    }
    return ans;
}

int main() {
    std::ios::sync_with_stdio(false);
    freopen("C-small-attempt4.in", "r", stdin);
    freopen("C-small-attempt4.out", "w", stdout);
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        cin >> N;
        for (int i = 1; i <= N; ++i) {
            cin >> must[i];
        }
        
        int ans = 0;
        loop = 0;
        for (int i = 1; i <= N; ++i) {
            ans = max(ans, start_from(i));
        }
        for (int i = 1; i <= N; ++i) {
            for (int j = i + 1; j <= N; ++j) {
                ans = max(ans, merge(i, j));
            }
        }
        cout << "Case #" << t << ": ";
        cout << max(ans, loop) << endl;
    }
    return 0;
}

