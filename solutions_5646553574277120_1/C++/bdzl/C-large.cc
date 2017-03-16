#include <bits/stdc++.h>
using namespace std;

const int kMaxV = 1e4 + 1;

typedef bitset<kMaxV> knapsack_mask;

void AddToKnapsack(int val, knapsack_mask& mask, int c)
{                                       
    for (int i = kMaxV - 1; i >= 0; --i) {
        if (mask[i]) {
            for (int j = 1; j <= c; ++j) {
                if (i + j * val >= kMaxV) {
                    break;
                }
                if (mask[i + j * val]) {
                    break;
                }
                mask[i + j * val] = true;
            }
        }
    }
}
 
int main()
{
    freopen("C-large.in", "r", stdin);
    freopen("C-large.out", "w", stdout);
    
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int tests;
    cin >> tests;
    for (int test = 0; test < tests; ++test) {
        int c, d, v;
        cin >> c >> d >> v;
        knapsack_mask mask;
        mask[0] = true;
        for (int i = 0; i < d; ++i) {
            int x;
            cin >> x;
            AddToKnapsack(x, mask, c);
        }
        int ans = 0;
        for (int p = 0; p < min(kMaxV, v + 1); ++p) {
            if (!mask[p]) {
                ++ans;
                AddToKnapsack(p, mask, c);
            } 
        }
        cout << "Case #" << test + 1 << ": ";
        cout << ans;
        cout << endl;
    }
    return 0;
}
