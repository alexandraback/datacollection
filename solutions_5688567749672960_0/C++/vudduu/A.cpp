// Problem Problem A. Counter Culture
// Para mi esposa Susana <3
#include <iostream>
#include <sstream>
#include <utility>
#include <cstdlib>
#include <cstdio>
#include <cctype>
#include <cmath>
#include <functional>
#include <algorithm>
#include <numeric>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <list>
#include <map>
#include <set>
#include <stdio.h>
#include <string.h>
using namespace std;

#define FOR(i,a,b)  for(int i=(a),_##i=(b);i<_##i;++i)
#define F(i,a)      FOR(i,0,a)
#define ALL(x)      x.begin(),x.end()
#define PB          push_back
#define MP          make_pair
#define S           size()
typedef long long   LL;

int N;

int reverseInt(int x) {
    int r = 0;
    while(x) {
        int a = x%10;
        r = r*10 + a;
        x /= 10;
    }
    return r;
}

int DP[1000010];

int solve(){
    memset(DP, -1, sizeof(DP));
    DP[1] = 1;
    FOR(i, 2, N+1) {
        if(DP[i] == -1)
            DP[i] = DP[i-1]+1;
        else
            DP[i] = min(DP[i-1]+1, DP[i]);

        int a = reverseInt(i);
        if(a < 1000010 && a > i)
            DP[a] = DP[i]+1;
    }
    return DP[N];
}

int main(){
	// freopen("a.in.txt", "r", stdin);
	freopen("A-small-attempt0.in", "r", stdin);
	// freopen("A-large.in", "r", stdin);
	freopen("a.out.txt", "w", stdout);
	int T;
    scanf("%d", &T);
    F(cas, T) {
        cin >> N;
        printf("Case #%d: %d\n", cas+1, solve());
    }
}
