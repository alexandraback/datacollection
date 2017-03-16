#include <iostream>
#include <map>
#include <vector>
#include <set>

using namespace std;

vector<int> res1;
vector<int> res2;


bool foo(int sum, int i, vector<int> & a) {
    if (i > 0 && sum == 0) {
        return true;
    }

    if (i == a.size()) {
        return false;
    }

    if (foo(sum + a[i], i + 1, a)) {
        res1.push_back(a[i]);
        return true;
    }

    if (foo(sum - a[i], i + 1, a)) {
        res2.push_back(a[i]);
        return true;
    }
    return foo(sum, i + 1, a);
}

int main() {
    int T;
    cin >> T;
    for (int k = 1; k <= T; ++k) {
        int n;
        cin >> n; 
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        cout << "Case #" << k << ":\n";
        res1.clear();
        res2.clear();

        if (foo(0, 0, a)) {
            for (int i = 0; i < res1.size(); ++i) {
                cout << res1[i] << " ";
            }
            cout << "\n";
            for (int i = 0; i < res2.size(); ++i) {
                cout << res2[i] << " ";
            }
            cout << "\n";
        } else {
            cout << "Impossible\n";
        }

    }
    return 0;
}
