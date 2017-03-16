// -*- C++ -*-
// File: fallingdiamonds.cpp
// Copyright (C) 2013
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <cmath>
#include <sstream>
#include <map>
#include <set>
#include <numeric>
#include <memory.h>
#include <cstdio>
#include <assert.h>

using namespace std;

#define pb push_back
#define INF 1011111111
#define FOR(i,a,b) for (int _n(b), i(a); i < _n; i++)
#define rep(i,n) FOR(i,0,n)
#define CL(a,v) memset((a),(v),sizeof(a))
#define mp make_pair
#define X first
#define Y second
#define all(c) (c).begin(), (c).end()
#define SORT(c) sort(all(c))

typedef long long ll;
typedef vector<int> VI;
typedef pair<int,int> pii;

/*** TEMPLATE CODE ENDS HERE */

double cnk(int n, int k) {
    if(n<0 || k < 0 || k > n) return 0;
    k = min(k, n-k);
    double c = 1;
    rep(i,k) c *= 1.*(n-i)/(i+1);
    return c;
}

double solve() {
    int N, X, Y;
    cin >> N >> X >> Y;

    if(X < 0) X = -X;

    int level = 0;

    for(; ; ++level) {
        if(N >= 4*level+1) {
            N -=  4*level + 1;
        }
        else
            break;
    }

    int x = X, y = Y;
    // detect in which level the target is
    while(y>0) {
        y --;
        x ++;
    }

    if(x%2==1) return 0.0; // impossible

    x /= 2;

    if(x < level) return 1.0; // done for sure

    if(x>level) return 0.0; // can't reach it

    if(Y+2*level+1 <= N) return 1.0; // for sure

    double p = 0;
    // count probability
    // int nn = max(0, (N - 2*level));
    int nn = 0;
    // cout << "Y: " << Y << " N: " << N << endl;

    FOR(k,Y+1,2*level+1) {
        p += cnk(N-nn,k-nn);

        // cout << "N: " << N-nn << " k: " << k-nn << " cnk: " <<  cnk(N-nn,k-nn) << endl;
    }

    rep(i,N-nn) p /= 2;

    double al = 0;
    nn = max(0, (N - 2*level));

    FOR(k,nn,2*level+1) {
        al += cnk(N,k);
        // cout << "N: " << N-nn << " k: " << k-nn << " cnk: " <<  cnk(N-nn,k-nn) << endl;
    }

    rep(i,N) al /= 2;


    return p/al;
}

int main() {

#ifdef LOCAL_HOST
    freopen("B-small-attempt1.in","r",stdin);
    freopen("output.txt","w",stdout);
#endif

    // ios_base::sync_with_stdio(false);

    int T;
    cin >> T;

    FOR(cs,1,T+1) {
        cout << "Case #" << cs << ": ";
        printf("%.7f\n", solve());
    }


// #ifdef LOCAL_HOST
//     printf("TIME: %.3lf\n",double(clock())/CLOCKS_PER_SEC);
// #endif

    return 0;
}
