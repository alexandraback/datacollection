#include <algorithm>
#include <cstdio>
#include <stack>

typedef long long llint;

using namespace std;

int T;

llint N;
llint dp[1000010], prev[1000010];

llint rev_dig(llint x) {

    llint ret = 0;
    while (x > 0) {
        ret *= 10; ret += x % 10;
        x /= 10;
    }

    return ret;

}

int len(llint x) {
    int ret = 0;
    while (x > 0) {
        x /= 10;
        ++ret;
    }
    return ret;
}   

llint power(llint b, llint e) {
    llint ret = 1;
    for (int i = 0; i < e; ++i) ret *= b;
    return ret;
}

void solve(int t) {

    scanf("%lld", &N);
   
    if (N < 10) {
        printf("Case #%d: %lld\n", t, N);
        return;
    }

    
    llint sol = N;
    
    while (N > 0) {
   
        llint _N = N;
        int digs = len(_N); 
        for (int i = 0; i < digs / 2; ++i) {
            _N /= 10; 
        }
    
        llint last = power(10, digs - 1);
        last += rev_dig(_N);

        llint rev_last = rev_dig(last);
        if (last >= N || rev_last > N || last >= rev_last || rev_dig(rev_last) != last) { --N; continue; }

        sol -= rev_dig(last) - last - 1; 
        N = last;
    }
    
    printf("Case #%d: %lld\n", t, sol);

}

int main(void) {

    scanf("%d", &T);
    for (int i = 0; i < T; ++i) solve(i + 1);

    return 0;

}
