#include <iostream>
#include <algorithm>
#include <vector>

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

int dWarScore(It a0, It a1, It b0, It b1) {
    if (a0 == a1) {
        return 0;
    }
    int score = 0;
    if (*(a1 - 1) > *(b1 - 1)) {
        score = max(score, 1 + dWarScore(a0, a1 - 1, b0, b1 - 1));
    }
    score = max(score, dWarScore(a0 + 1, a1, b0, b1 - 1));
    return score;
}

int dWarScore(vector<double> const & a, vector<double> const & b) {
    return dWarScore(a.begin(), a.end(), b.begin(), b.end());
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

        cout << "Case #" << t << ": ";
        cout << dWarScore(ar, br) << " ";
        cout << warScore(ar, br) << "\n";
    }
}
