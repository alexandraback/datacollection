// -*- C++ -*-
// File: osmos.cpp
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


int solve() {
    int A, N, a[111];
    cin >> A >> N;
    rep(i,N) cin >> a[i];
    sort(a,a+N);

    if(A==1 && a[0]>1) return N;

    int ans = N;
    int moves = 0;

    rep(i,N) {
        while(A <= a[i]) {
            // if(A==1) return N;
            A += A-1;
            moves ++;
        }
        A += a[i];
        ans = min(ans, moves + N-i-1);
    }

    return ans;
}

int main() {
#ifdef LOCAL_HOST
    freopen("A-large.in","r",stdin);
    freopen("output.txt","w",stdout);
#endif

    ios_base::sync_with_stdio(false);

    int T;
    cin >> T;

    FOR(cs,1,T+1) {
        cout << "Case #" << cs << ": " << solve() << endl;
    }

// #ifdef LOCAL_HOST
//     printf("TIME: %.3lf\n",double(clock())/CLOCKS_PER_SEC);
// #endif

    return 0;
}
