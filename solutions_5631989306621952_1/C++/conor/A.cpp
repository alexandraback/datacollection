/**
* Change is impossible in this fog of ignorance.
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <climits>
#include <cstdio>
#include <cstring>
#include <cctype>
#include <cassert>
#include <cmath>
using namespace std;

#define trace(x) {cerr << #x << "=" << x <<endl;}
#define trace2(x, y) {cerr << #x << "=" << x << " " << #y << "=" << y <<endl;}
#define track(x) {cerr << #x << ":" << endl; for (int q = 0; q < x.size(); q++) {cerr << x[q] << " ";} cerr << endl;}
#define trackarr(x, n) {cerr << #x << ":" << endl; for (int q = 0; q < n; q++) {cerr << x[q] << " ";} cerr << endl;}
#define trackvv(x) {cerr << #x << ":" << endl; for (int i = 0; i < x.size(); i++) { cerr << "i:" << i << endl; for (int j = 0; j < x[i].size(); j++){cerr << x[i][j] << " ";} cerr << endl;} cerr << endl;}
#define trackcr(x) {cerr << #x << ":" << endl; for (auto i = x.begin(); i != x.end(); i++) {cerr << *i << " ";} cerr << endl;}
template <typename Tk, typename Tv> ostream& operator<<(ostream& os, const pair<Tk, Tv> &p){os << "{" << p.first << ',' << p.second << "}";return os;}

typedef long long ll;

const int MAX = 100005;
const int MOD = 1000000000+7;
const int INF = 1000000000;

void inout() {
    freopen("A-large.in", "r", stdin);
    freopen("A-large.out", "w", stdout);
}

void doTask() {
    string s;
    cin >> s;
    char t[5005];
    int start = 1005, stop = 1005;
    t[1005] = s[0];
    for (int i = 1; i < s.size(); i++) {
        if (s[i] >= t[start]) {
            t[--start] = s[i];
        } else {
            t[++stop] = s[i];
        }
    }
    for (int i = start; i <= stop; i++) {
        cout << t[i];
    }
    cout << endl;
}

int main() {
    inout();
    int tc;
    scanf("%d", &tc);
    for (int t = 1; t <= tc; t++) {
        printf("Case #%d: ", t);
        doTask();
    }
}
