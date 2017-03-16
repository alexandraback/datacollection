#include <algorithm>
#include <bitset>
#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <math.h>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

int myabs(int a) {
    if(a < 0) return -a;
    return a;
}

int main() {
    freopen("B-small-attempt0.in", "r", stdin);
    freopen("B-small.out", "w", stdout);
    int T, A, B, K;
    cin >> T;
    for(int t = 1; t <= T; t++) {
        cin >> A >> B >> K;
        /*long long ans = 1;
        for(int i = 1; i < K; i = i*=2) {
            if(i >= A || i >= B) {
                continue;
            }
            long long numzeroa = 1, numzerob = 1;
            for(int j = 0; j < 31; j++) {
                if(!(i & (1<<j))) {
                    if((i | (1<<j)) < A) numzeroa++;
                    if((i | (1<<j)) < B) numzerob++;
                }
            }
            ans += numzeroa * numzerob;
        }*/
        long long ans = 0;
        for(int i = 0; i < A; i++) {
            for(int j = 0; j < B; j++) {
                if((i & j) < K) ans++;
            }
        }
        cout << "Case #" << t << ": " << ans << endl;
    }
}