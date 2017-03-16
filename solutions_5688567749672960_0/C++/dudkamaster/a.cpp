# define _USE_MATH_DEFINES
#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <ctime>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <functional>
#include <fstream>
#include <iostream>
#include <map>
#include <memory.h>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <sstream>
#include <vector>
#include <utility>
#include <cmath>
using namespace std;

#define pb push_back
#define mp make_pair
#define sz(a) (int)(a).size()
#define all(a) (a).begin(), (a).end()

#define forn(i,n) for (int i=0; i<int(n); ++i)

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;


const int INF = (int) 1e9;
const long long INF64 = (long long) 1e18;
const long double eps = 1e-9;
const long double pi = 3.14159265358979323846;

const int nmax = 1000100;

int n, d[nmax];

int rev(int num) {
    string snum;
    stringstream ss;
    ss << num;
    ss >> snum;
    reverse(all(snum));
    ss.clear();
    ss << snum;
    ss >> num;
    return num;
}

void read(){
    scanf("%d", &n);
}

void solve(){
    memset(d, -1, sizeof d);
    queue <int> q;
    q.push(1);
    d[1] = 1;
    while (!q.empty()) {
        int num = q.front();
        q.pop();
        if (1 <= num+1 && num+1 <= n && d[num+1] == -1) {
            d[num+1] = d[num]+1;
            q.push(num+1);
        }
        if (1 <= rev(num) && rev(num) <= n && d[rev(num)] == -1) {
            d[rev(num)] = d[num] + 1;
            q.push(rev(num));
        }
    }
    printf("%d\n", d[n]);
}

int main(){
#ifdef dudkamaster
    freopen("input.txt","rt",stdin);
    freopen("output.txt","wt",stdout);
#endif
    int t;
    scanf("%d", &t);
    for (int test = 1; test <= t; test++) {
        read();
        printf("Case #%d: ", test);
        solve();
    }
    return 0;
}
