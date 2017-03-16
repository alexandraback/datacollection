/*
 * Author: fatboy_cw
 * Created Time:  2015/4/11 11:06:50
 * File Name: B.cpp
 */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
const int maxint = -1u>>1;
template <class T> bool get_max(T& a, const T &b) {return b > a? a = b, 1: 0;}
template <class T> bool get_min(T& a, const T &b) {return b < a? a = b, 1: 0;}

const int maxn = 1000 + 5;
int t, ca, n, d;
vector<int> v;

int calc(const vector<int> &v, int c) {
    int res = 0;
    for(int i = 0; i < v.size(); i++) {
        res += v[i] / c + (v[i] % c != 0) - 1;
    }
    return res;
}

int main() {
    freopen("B.out", "w", stdout);
    scanf("%d", &t);
    while(t--) {
        v.clear();
        scanf("%d", &n);
        for(int i = 0; i < n; i++) {
            scanf("%d", &d);
            v.push_back(d);
        }
        int ans = maxint;
        for(int i = 1; i <= 1000; i++) {
            get_min(ans, i + calc(v, i));
        }
        printf("Case #%d: %d\n", ++ca, ans);
    }
    return 0;
}

