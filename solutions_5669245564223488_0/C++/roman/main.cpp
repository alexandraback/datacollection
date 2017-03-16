#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

typedef long long i64;
i64 MOD = 1000000007;

bool is_valid(int n, string ts[], int ind[]) {
    char last = '\0';
    bool used[26] = {0};
    for (int i = 0; i < n; ++i) {
        string &cur = ts[ind[i]];
        for (int j = 0; j < (int)cur.size(); ++j) {
            if (last == cur[j])
                continue;
            last = cur[j];
            if (used[last - 'a'])
                return false;
            used[last - 'a'] = true;
        }
    }
    return true;
}

i64 get_res(int n, string ts[]) {
    int ind[n];
    for (int i = 0; i < n; ++i) {
        ind[i] = i;
    }

    i64 res = is_valid(n, ts, ind);
    while (next_permutation(ind, ind + n)) {
        if (is_valid(n, ts, ind))
            ++res;
    }
    return res % MOD;
}

int main() {
    int tcn, n;
    cin >> tcn;
    for (int tc = 0; tc < tcn; ++tc) {
        cerr << tc << endl;
        cin >> n;
        string ts[n];
        for (int i = 0; i < n; ++i) {
            cin >> ts[i];
        }

        cout << "Case #" << tc + 1 << ": " << get_res(n, ts) << endl;
    }
    return 0;
}
