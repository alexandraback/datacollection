#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

int warScore(vector<double> const & a, vector<double> b) {
    int score = 0;
    int n = a.size();
    int min = 0;
    for (int i = n - 1; i >= 0; --i) {
        double x = a[i];
        bool found = false;
        for (int j = 0; j < n; ++j) {
            if (b[j] > x) {
                b[j] = -1;
                found = true;
                break;
            }
        }
        if (!found) {
            b[min++] = -1;
            ++score;
        }
    }
    return score;
}

typedef vector<double>::const_iterator It;


int dp[1001][1001];

int dWarScore(vector<double> const & a, vector<double> const & b, int from, int to) {
    if (from == to) {
        return 0;
    }
    if (dp[from][to] >= 0) {
        return dp[from][to];
    }
    int score = 0;
    if (a[to - 1] > b[to - from - 1]) {
        score = max(score, 1 + dWarScore(a, b, from, to - 1));
    }
    score = max(score, dWarScore(a, b, from + 1, to));
    return dp[from][to] = score;
}

int dWarScore(vector<double> const & a, vector<double> const & b) {
    return dWarScore(a, b, 0, a.size());
}

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        int n;
        cin >> n;
        vector<double> ar(n);
        vector<double> br(n);
        for (int i = 0; i < n; ++i) {
            cin >> ar[i];
        }
        for (int i = 0; i < n; ++i) {
            cin >> br[i];
        }
        sort(ar.begin(), ar.end());
        sort(br.begin(), br.end());

        //for (int i = 0; i < n; ++i) cout << ar[i] << " "; cout << "\n";
        //for (int i = 0; i < n; ++i) cout << br[i] << " "; cout << "\n";
        memset(dp, 255, sizeof(dp));
        cout << "Case #" << t << ": ";
        cout << dWarScore(ar, br) << " ";
        cout << warScore(ar, br) << "\n";
    }
}
