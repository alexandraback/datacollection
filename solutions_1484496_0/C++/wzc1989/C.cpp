/*
 * Author: code6
 * Created Time:  2012/5/6 0:31:39
 * File Name: C.cpp
 */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <queue>
#include <bitset>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <ctime>
#include <string>

using namespace std;
#define out(v) cerr << #v << ": " << (v) << endl
#define SZ(v) ((int)(v).size())
const int maxint = -1u>>1;
template <class T> bool get_max(T& a, const T &b) {return b > a? a = b, 1: 0;}
template <class T> bool get_min(T& a, const T &b) {return b < a? a = b, 1: 0;}
typedef long long ll;
const double PI=acos(-1.0);
const double eps=1e-11;

#define two(i) (1LL << (i))

int n;
ll v[1000];

void pp(int m)
{
    bool first = true;
    int i;
    for (i = 0; i < n; i++) {
        if (two(i) & m) {
            if (!first) {
                cout<<" ";
            }
            cout<<v[i];
            first = false;
        }
    }
    printf("\n");
}

void small(int cas)
{
    printf("Case #%d:\n", cas);
    map<int, int> M;
    int i, j;
    for (i = 0; i < (1 << n); i++) {
        int sum = 0;
        for (j = 0; j < n; j++) {
            if (two(j) & i) {
                sum += v[j];
            }
        }
        if (M.find(sum) != M.end()) {
            int pre = M[sum];
            pp(pre);
            pp(i);
            return;
        } else {
            M[sum] = i;
        }
    }
    puts("Impossible");
}

int main() {
    freopen("C-small-attempt0.in", "r", stdin);
    freopen("C-small-attempt0.out", "w", stdout);
    //freopen("C-large.in", "r", stdin);
    //freopen("C-large.out", "w", stdout);
    int t, cas = 0;
    int i, j;
    scanf("%d", &t);
    while (t--) {
        cas ++;
        cin >> n;
        for (i = 0; i < n; i++) {
            cin>>v[i];
        }
        small(cas);
    }
    return 0;
}

