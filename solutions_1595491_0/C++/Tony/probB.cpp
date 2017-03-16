
#include <algorithm>
#include <iostream>

using namespace std;

int N, S, p;
int t[100];

int maxSur[32], maxNot[32];

void precompute() {
    for (int i = 0; i <= 30; i++)
        maxSur[i] = maxNot[i] = -1;

    for (int i = 0; i <= 10; i++)
        for (int j = i; j <= 10 && j <= i + 2; j++)
            for (int k = j; k <= 10 && k <= i + 2; k++) {
                int sum = i + j + k;
                if (k == i + 2)
                    maxSur[sum] = max(maxSur[sum], k);
                else
                    maxNot[sum] = max(maxNot[sum], k);
            }

    /*
    for (int i = 0; i <= 30; i++)
        cout << i << "\t" << maxSur[i] << "\t" << maxNot[i] << endl;
    */
}

bool used[100];

int solve() {
    for (int i = 0; i < N; i++)
        used[i] = false;

    int total = 0;

    // can't be surprising
    for (int i = 0; i < N; i++) {
        int mSur = maxSur[t[i]], mNot = maxNot[t[i]];
        if (mSur != -1)
            continue;
        used[i] = true;
        if (mNot >= p)
            total++;
    }

    // can be surprising, should make surprising
    for (int i = 0; i < N; i++) {
        int mSur = maxSur[t[i]], mNot = maxNot[t[i]];
        if (used[i])
            continue;
        if (mSur >= p && mNot < p) {
            used[i] = true;
            if (S > 0)
                total++, S--;
        }
    }

    // can be surprising, makes no difference
    for (int i = 0; i < N; i++) {
        int mSur = maxSur[t[i]], mNot = maxNot[t[i]];
        if (used[i])
            continue;
        used[i] = true;
        if (mSur >= p)
            total++;
    }

    return total;
}

int main() {
    precompute();

    int T;
    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> N >> S >> p;
        for (int j = 0; j < N; j++)
            cin >> t[j];

        cout << "Case #" << i + 1 << ": " << solve() << endl;
    }
}
