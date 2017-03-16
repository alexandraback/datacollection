/* 
 * File:   main.cpp
 * Author: tlatif
 *
 * Created on May 3, 2014, 10:30 AM
 */

#include <iostream>
#include <string>
#include <algorithm>
#include <functional>
#include <utility>
#include <numeric>
#include <vector>
#include <set>
#include <map>
#include <list>
#include <queue>
#include <stack>
#include <deque>
#include <bitset>
#include <limits>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <cctype>
#include <climits>
#include <cfloat>
#include <ctime>
#include <cassert>

#define INF 999999999
#define pb push_back
typedef long long LL;

using namespace std;

/*
 * 
 */
int main() {
    freopen("input.in", "r", stdin);
    freopen("output.txt", "w", stdout);
    int tc = 0, t;
    cin>>t;
    while (tc++ < t) {
        int a, b, k;
        int i, j;
        LL vals[1010];
        memset(vals, 0, sizeof(vals));
        cin>>a>>b>>k;
        for (i = 0; i < a; i++) {
            for (j = 0; j < b; j++) {
                vals[i & j]++;
            }
        }
//        for (i = 0; i < k; i++) {
//            cout<<vals[i]<<" ";
//        }
//        cout<<endl;
        LL res = 0;
        for (i = 0; i < k; i++) {
            res += vals[i];
        }
        printf("Case #%d: ", tc);
        cout<<res<<endl;
    }
    return 0;
}

