#include <iostream>
#include <map>

using namespace std;

int main()
{
    int t;
    cin >> t;

    for (int tt = 1; tt <= t; tt++) {
        int n;
        cin >> n;

        map<int, int> cnt;
        for (int i = 0; i < 2 * n - 1; i++) {
            for (int j = 0; j < n; j++) {
                int a;
                cin >> a;
                cnt[a]++;
            }
        }

        cout << "Case #" << tt << ": ";

        for (auto kvp : cnt) {
            if (kvp.second % 2 == 1) {
                cout << kvp.first << " ";
            }
        }

        cout << endl;
    }

    return 0;
}
