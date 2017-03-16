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
map<S, map<S, S>> m;
int pre[10000], arr[10000];
int mat[4][4] = {
    {0, 1, 2, 3},
    {1, 4, 3, 6},
    {2, 7, 4, 1},
    {3, 2, 5, 4},
};

int mult(int a, int b) {
    int minus = 0;
    if (a >= 4) {
        minus ^= 1;
        a-=4;
    }
    if (b >= 4) {
        minus ^= 1;
        b-=4;
    }
    if (minus && mat[a][b] >= 4) {
        return mat[a][b] - 4;
    }
    return mat[a][b] + minus * 4;
    
}

int divide(int a, int b) {
    rep(i, 8) {
        if (mult(b, i) == a) {
            return i;
        }
    }
    cout<<a<<" "<<b<<"\n";
    assert(0);
}

int multi(int i, int j) {
    if (i==0) {
        return pre[j];
    }
    return divide(pre[j], pre[i-1]);
}

map<char, int> toi;
int main () {
    toi['i'] = 1;
    toi['j'] = 2;
    toi['k'] = 3;
    freopen("/Users/mahesh/Desktop/Codejam/Codejam/test.txt", "r", stdin);
    freopen("/Users/mahesh/Desktop/Codejam/Codejam/out.txt", "w", stdout);
    int T = SS;
    rep(t, T) {
        int L = SS, X = SS;
        S s;
        cin>>s;
        S str = "";
        rep(i, X) {
            str += s;
        }
        int N = L*X;
        rep(i, N) {
            arr[i] = toi[str[i]];
        }
        pre[0] = arr[0];
        fori(i, 1, N) {
            pre[i] = mult(pre[i-1], arr[i]);
        }
/*        rep(i, 3) cout<<pre[i]<<" ";
        puts("");
        cout<<multi(0, 0)<<" "<<multi(1, 1)<<" "<<multi(2, 2);*/
        S ans = "NO";
        fori(i, 1, N-1) {
            fori(j, i, N-1) {
                if (multi(0, i-1) == toi['i'] && multi(i, j) == toi['j'] && multi(j+1, N-1) == toi['k']) {
                    ans = "YES";
                }
            }
        }
        cout<<"Case #"<<t+1<<": "<<ans<<endl;
    }
}