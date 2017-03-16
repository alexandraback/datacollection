#include <cstdio>
#include <cassert>
#include <algorithm>
#include <vector>
#include <iostream>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <cstring>
#include <cstdlib>
#include <cmath>
#define For(i, n) for (int i = 0; i < (int) n; ++i)
#define SIZE(x) ((int) (x).size())
#define mp(a, b) make_pair(a, b)
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

#ifndef DG
#define DG 0
#endif
#define LOG(...) (DG ? fprintf(stderr, __VA_ARGS__) : 0)

int main(){
    int T;
    scanf("%d", &T);
    For(cases, T) {
        ll c, d, v;
        scanf("%lld %lld %lld", &c, &d, &v);
        vector <ll> denominations(d);
        For(i, d) scanf("%lld", &denominations [i]);
        ll next = 1, result = 0, point = 0;
        while (next <= v) {
//                cerr  << "mimo " <<next << ' ' << denominations [point] << endl;
            while (point < d && next >= denominations [point]) {
                next += c*denominations [point];
                point ++;
//                cerr << "vnutri po " << next << ' ' << denominations [point] << endl;
            }
            if (next > v) break;
            next += c* next;
            result ++;
        }

        printf("Case #%d: %lld\n", cases + 1, result);
    }

}
