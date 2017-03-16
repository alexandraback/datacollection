#include <bits/stdc++.h>

using namespace std;

bool dones[11];
bool done(long long cur) {
    do {
        dones[cur % 10] = true;
        cur /= 10;
    } while (cur > 0);
    for (int i = 0; i < 10; i++) {
        if (!dones[i]) return false;
    }
    return true;
}

int main() {
    int t;
    cin >> t;
    for (int test = 1; test <= t; test++) {
        long long n;
        cin >> n;
        if (n == 0) {
            cout << "Case #" << test << ": INSOMNIA" << endl;
            continue;
        }
        memset(dones, 0, sizeof(dones));
        for (long long j = 1; j < 9999999999LL; j++) {
            if (done(n * j)) {
                cout << "Case #" << test << ": " << (j * n) << endl;
                break;
            }
        }
    }
}