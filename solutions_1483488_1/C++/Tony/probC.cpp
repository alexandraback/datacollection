
#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
#define MAX 2000000

using namespace std;

int A, B;

inline vector <int> get_dig(int N) {
    vector <int> d;
    while (N > 0)
        d.push_back(N % 10), N /= 10;
    reverse(d.begin(), d.end());
    return d;
}

vector <int> mVals[MAX + 1];

void precompute() {
    for (int n = 1; n <= MAX; n++) {
        vector <int> d = get_dig(n);
        int numDig = d.size();
        set <int> mSet;
        for (int j = 1; j < numDig; j++) {
            // first digit can't be zero
            if (d[j] == 0)
                continue;
            int m = 0;
            for (int k = 0; k < numDig; k++)
                m = 10 * m + d[(j + k) % numDig];
            if (m > n)
                mSet.insert(m);
        }
        mVals[n] = vector <int> (mSet.begin(), mSet.end());
    }
}

int solve() {
    int total = 0;
    for (int n = A; n <= B; n++) {
        for (int i = 0; i < mVals[n].size(); i++) {
            int m = mVals[n][i];
            if (m <= B)
                total++;
            else
                break;
        }
    }
    return total;
}

int main() {
    precompute();

    int T;
    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> A >> B;
        cout << "Case #" << i + 1 << ": " << solve() << endl;
    }
}
