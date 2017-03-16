#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef long double ld;

const int hmax = 3000;

int main()
{

    ifstream cin("B-small-attempt0.in");
    ofstream cout("outbsmall.txt");

    ios_base::sync_with_stdio(false);

    int tt;
    cin >> tt;

    for (int step = 0; step < tt; ++step) {
        int n;
        cin >> n;
        vector<int> h(hmax, 0);
        for (int i = 0; i < 2 * n - 1; ++i) {
            for (int j = 0; j < n; ++j) {
                int x;
                cin >> x;
                ++h[x];
            }
        }
        cout << "Case #" << step + 1 << ": ";
        for (int i = 0; i < hmax; ++i) {
            if (h[i] & 1) {
                cout << i << " ";
            }
        }
        cout << "\n";
    }

}
