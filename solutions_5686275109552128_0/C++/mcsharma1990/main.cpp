//
//  main.cpp
//  Codejam
//
//  Created by Mahesh Sharma on 4/10/15.
//  Copyright (c) 2015 Mahesh Sharma. All rights reserved.
//

/* Author: Mahesh */

/* 1. Did u interpret the qns correctly ?
 2. Is your i/o correct ?
 3. Int overflow, double precesion
 4. Array size correct ?
 5. Clearing/resetting vector, map etc.
 6. Stack ovrflow
 7. Global/local conflict
 8. Check for obvious typo(most imp)
 9. Think about edge cases
 */

#include <vector>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cctype>
#include <cstring>
#include <memory.h>
#include <cassert>

using namespace std;

#define ford(i, a, b, c)        for(int i=(a); i<(b); i+=(c))
#define fori(i, a, b)           ford(i,a,b,1)
#define rep(i, n)               fori(i,0,n)
#define ifor(i, a, b)           for(int i=(a); i>=(b); i--)
#define iter(i, a)              for(typeof((a).begin()) i=(a).begin(); i!=(a).end(); i++)
#define si(x)                   ((int)x.size())
#define SS                      ({int x;scanf("%d",&x);x;})
#define pb                      push_back
#define mp                      make_pair
#define all(a)                  a.begin(),a.end()
#define fill(a, v)              memset(a, v, sizeof(a))
#define inf                     (int)1e9
#define linf                    (long long)1e18
#define V                       vector
#define S                       string
#define XX                      first
#define YY                      second
#define P(v)                    rep(i, si(v)) cout<<v[i]<<" "; puts("")

typedef V<int> vi;
typedef V<S> vs;
typedef long long ll;
typedef pair<int,int> pii;

/* Program Body starts here */

set<pii> ins(set<pii> s, pii p) {
    int f = -1;
    iter(i, s) {
        if (i->first == p.first) {
            f = i->second;
            break;
        }
    }
    assert(f != 0);
    if (f > 0) {
        s.erase(mp(p.first, f));
        s.insert(mp(p.first, f+p.second));
    } else {
        s.insert(p);
    }
    return s;
}

int arr[1000];

int rec(map<int, int> m, set<pii> s) {
    int x = s.rbegin()->first, f = s.rbegin()->second;
    s.erase(*(s.rbegin()));
    m[x] = 0;
    if (x <=2) return x;
    int ans = x;
    fori(i, 1, x) {
        map<int, int> m2 = m;
        set<pii> s2 = s;
        if (i > x-i) break;
        if (i  == x - i) {
            s.erase(mp(x/2, m[x/2]));
            s.insert(mp(x/2, m[x/2] + 2*f));
            m[x/2] += 2*f;
        } else {
            s.erase(mp(i, m[i]));
            s.insert(mp(i, m[i] + f));
            m[i] += f;
            s.erase(mp(x-i, m[x-i]));
            s.insert(mp(x-i, m[x-i] + f));
            m[x-i] += f;
        }
        ans = min(ans, rec(m, s) + f);
        m = m2;
        s = s2;
    }
    return ans;
}
int main () {
    freopen("/Users/mahesh/Desktop/Codejam/Codejam/test.txt", "r", stdin);
    freopen("/Users/mahesh/Desktop/Codejam/Codejam/out.txt", "w", stdout);
    int T = SS;
    rep(t, T) {
        int n = SS;
        map<int, int> m;
        m.clear();
        rep(i, n) {
            cin>>arr[i];
            m[arr[i]]++;
        }
        set<pii> s;
        s.clear();
        iter(i, m) {
            s.insert(mp(i->first, i->second));
        }
        //        int ans = 0;
        printf("Case #%d: %d\n", t+1, rec(m, s));
        /* rep(i, n) {
         cout<<arr[i]<<" ";
         }
         puts("");
         cout<<"ans: "<<ans<<endl;*/
    }
}