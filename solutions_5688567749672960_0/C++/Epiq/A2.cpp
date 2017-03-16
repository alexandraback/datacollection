#include <iostream>
#include <bits/stdc++.h>

using namespace std;
#define mp(x,y) make_pair((x),(y))
#define pb(x) push_back(x)
#define sz(x) ((int)(x).size())
#define debug(x) (cerr << #x << " = " << (x) << endl)
template<class I> void debug2(I b, I e) { while (b != e) cerr << *b++ << " "; cerr << endl; }

typedef long long int ll;
typedef unsigned long long int ull;

#define MAX 1000000

int M[MAX + 1];

int rev(int n) {
    int r = 0;
    while (n) {
        r = 10 * r + n % 10;
        n /= 10;
    }
    return r;
}

void init() {
    M[0] = 0;
    for (int i = 1; i <= MAX; i++) {
        int j = rev(i);
        M[i] = min(i, 1 + M[i - 1]);
        if (j < i) {
            int k = rev(j);
            if (i == k) {
                M[i] = min(M[i], 1 + M[j]);
            }
        }
    }
}

int solve() {
    int n;
    cin >> n;
    
    return M[n];
}

int main(){
    init();
    
    int tests;
    cin >> tests;
    for (int test = 1; test <= tests; test++) {
        printf("Case #%d: ", test);
        cout << solve() << endl;
    }
    
    return 0;
}
