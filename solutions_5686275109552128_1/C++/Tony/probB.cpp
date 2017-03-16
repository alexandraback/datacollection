
#include <algorithm>
#include <iostream>

using namespace std;

int n;
int p[1024];
int pcur[1024];

bool can_solve(int limit) {
    // use i moves
    for (int i = 0; i < limit; i++) {
        for (int j = 0; j < n; j++)
            pcur[j] = p[j];

        int minutes = limit - i;
        int used = 0;
        for (int j = n - 1; j >= 0; j--) {
            if (pcur[j] <= minutes)
                break;

            while (pcur[j] > minutes) {
                pcur[j] -= minutes;
                used++;
            }
            if (used > i)
                break;
        }
        if (used <= i)
            return true;
    }
    return false;
}

int solve() {
    sort(p, p + n);

    int low = 1, high = p[n - 1];
    while (low < high) {
        int mid = (low + high) / 2;
        if (can_solve(mid))
            high = mid;
        else
            low = mid + 1;
    }
    return low;
}

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        cin >> n;
        for (int i = 0; i < n; i++)
            cin >> p[i];

        cout << "Case #" << t << ": " << solve() << endl;
    }
}