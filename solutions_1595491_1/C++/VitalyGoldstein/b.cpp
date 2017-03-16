#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int tst;
    cin >> tst;
    for(int iter = 0; iter < tst; ++iter) {
        int n, s, p;
        cin >> n >> s >> p;
        int ans = 0;
        for(int i = 0; i < n; ++i) {
            int sum;
            cin >> sum;
            if (sum >= 3 * p - 2) ++ans;
            else if (s > 0 && sum >= p + 2 * std::max(p - 2, 0)) {
                ++ans;
                --s;
            }
        }
        cout << "Case #" << iter + 1 << ": " << ans << endl;
    }
    return 0;
}
