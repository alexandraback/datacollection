#include <iostream>
#include <vector>

using namespace std;

void out(const vector<int>& a, int msk)
{
    bool first = true;
    for(int i = 0; i < a.size(); ++i) {
        if (msk & (1 << i)) {
            if (!first) cout << " ";
            first = false;
            cout << a[i];
        }
    }
    cout << endl;
}

void solve(const vector<int>& a)
{
    vector<int> used(2e+6 + 1, 0);
    for(int msk = 0; msk < (1 << a.size()); ++msk) {
        int sum = 0;
        for(int i = 0; i < a.size(); ++i) {
            if (msk & (1 << i)) {
                sum += a[i];
            }
        }
        if (used[sum]) {
            cout << endl;
            out(a, used[sum]);
            out(a, msk);
            return ;
        } else {
            used[sum] = msk;
        }
    }
    cout << "Impossible" << endl;
}

int main()
{
    int tst;
    cin >> tst;
    for(int iter = 0; iter < tst; ++iter) {
        int n;
        cin >> n;
        vector<int> a(n);
        for(int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        printf("Case #%d:", iter + 1);
        solve(a);
    }
    return 0;
}
