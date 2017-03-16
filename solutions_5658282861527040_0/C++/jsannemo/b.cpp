#include <cmath>
#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <bitset>
#include <algorithm>
#include <cstring>

using namespace std;

#define rep(i, a, b) for(int i = (a); i < int(b); ++i)
#define trav(it, v) for(typeof((v).begin()) it = (v).begin(); it != (v).end(); ++it)

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int a, b, c;

long long dp[32][2][2][2][2];

bool has(int num, int p){
    return num&p;
}

bool may(int num, int p, bool on){
    return !on || has(num, p);
}

long long sol(int bit, bool onA, bool onB, bool onC, bool exc){
    if(bit == -1) return exc;
    long long& ans = dp[bit][onA][onB][onC][exc];
    if(ans == -1LL){
	int p = 1<<bit;
	ans = 0;
	if(may(a, p, onA) && may(b, p, onB)){
	    ans += sol(bit - 1, onA && has(a, p), onB && has(b, p), onC && has(c, p), p > c || (onC && !has(c, p)) || exc);
	}
	if(may(a, p, onA)){
	    ans += sol(bit - 1, onA && has(a, p), onB && !has(b, p), onC && !has(c, p), exc);
	}
	if(may(b, p, onB)){
	    ans += sol(bit - 1, onA && !has(a, p), onB && has(b, p), onC && !has(c, p), exc);
	}
	ans += sol(bit - 1, onA && !has(a, p), onB && !has(b, p), onC && !has(c, p), exc);
    }
    return ans;
}

bool solve(int tc){
    scanf("%d%d%d", &a, &b, &c);
    a--; b--; c--;
    memset(dp, -1, sizeof(dp));
    long long ans;
    if(a <= c || b <= c){
	ans = 0;
    } else {
	ans = sol(31, true, true, true, false);
    }
    long long mult = a + 1;
    mult *= b + 1;
    mult -= ans;
    printf("Case #%d: %lld\n", tc, mult);
    return true;
}

int main(){
    int n = 0;
    if(!n) cin >> n;
    for(int i = 1; i <= n && solve(i); ++i);
}
