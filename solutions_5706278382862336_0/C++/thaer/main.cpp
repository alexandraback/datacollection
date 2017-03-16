/* 
 * File:   main.cpp
 * Author: tlatif
 *
 * Created on May 11, 2014, 5:29 AM
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

LL gcd(LL a, LL b) {
    LL t;
    while (a != 0) {
        t = a;
        a = b % a;
        b = t;
    }
    return b;
}
/*
 * 
 */
int main() {
    freopen("input.in", "r", stdin);
    freopen("output.txt", "w", stdout);
    vector<LL> pows;
    int i, j, k = 0;
    LL next;
    pows.pb(1);
    while (1) {
        next = pows.back() * 2;
        pows.pb(next);
        if (next > 1000000000000L) break;
    }
    int tc = 0, t;
    cin>>t;
    while (tc++ < t) {
        LL p, q, g;
        k = 0;
        scanf("%lld/%lld", &p, &q);
        LL num = p; LL den = q;
        g = gcd(p, q);
        num = p / g;
        den = q / g;
        //cout<<num<<" "<<den<<" "<<g<<endl;
        LL res = 0;
        bool notPossible = true;
        for (i = 0; i < pows.size(); i++) {
            if (den == pows[i]) {
                notPossible = false;
                break;
            }
        }
        if (!notPossible) {
            while (1) {
                num *= 2;
                k++;
                if (num >= den) {
                    res = k;
                    break;
                }
            }
        }
        printf("Case #%d: ", tc);
        if (res == 0) {
            printf("impossible\n");
        } else {
            cout<<res<<endl;
        }
        
        
        
    }
    return 0;
}

