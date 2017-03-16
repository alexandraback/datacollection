
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int A, B, K;

int calc_brute() {
    int cnt = 0;
    for (int a = 0; a < A; a++)
        for (int b = 0; b < B; b++)
            if ((a & b) < K)
                cnt++;
    return cnt;
}

inline int right_mask(int i) {
    return ~((1 << (i + 1)) - 1);
}

long long calc(int i, int j, int k) {
    long long cnt = 1LL << (i + j);
    for (int l = 29; l >= 0; l--) {
        vector <int> av, bv;

        if (l > i)
            av.push_back(A & (1 << l));
        else if (l == i)
            av.push_back(0);
        else
            av.push_back(0), av.push_back(1 << l);

        if (l > j)
            bv.push_back(B & (1 << l));
        else if (l == j)
            bv.push_back(0);
        else
            bv.push_back(0), bv.push_back(1 << l);

        if (l >= k) {
            int goal = (l == k) ? 0 : (K & (1 << l));
            int num = 0, den = av.size() * bv.size();
            for (int a : av)
                for (int b : bv)
                    if ((a & b) == goal)
                        num++;
            if (num == 0)
                return 0;
            cnt = cnt / den * num;
        }
    }
    return cnt;
}

long long calc() {
    // first index where bit_i(a) = 0, bit_i(A) = 1
    long long cnt = 0;
    for (int i = 0; i < 30; i++) {
        if ((A & (1 << i)) == 0)
            continue;
        for (int j = 0; j < 30; j++) {
            if ((B & (1 << j)) == 0)
                continue;

            for (int k = 0; k < 30; k++) {
                if ((K & (1 << k)) == 0)
                    continue;
                cnt += calc(i, j, k);
            }
        }
    }
    return cnt;
}

void solve() {
    cin >> A >> B >> K;

    long long cnt = calc();

    /*
    int cnt_brute = calc_brute();
    cerr << cnt << " " << cnt_brute << endl;
    if (cnt != cnt_brute)
        cerr << "NOT EQUAL" << endl;
    */

    cout << cnt << endl;
}

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        cout << "Case #" << t << ": ";
        solve();
    }
}

