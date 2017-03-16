#include <iostream>

using namespace std;

int T, R, N, M, K;
int s[16];

string guess() {
    int n3 = 0, n2 = 0, n4 = 0, n5 = 0;
    for (int i = 0; i < K; ++i) {
        int t = s[i];
        int x = 0;
        while (t % 2 == 0) {
            x += 1;
            t /= 2;
        }
        n2 = max(n2, x & 1);
        n4 = max(n4, x >> 1);

        x = 0;
        while (t % 3 == 0) {
            x += 1;
            t /= 3;
        }
        n3 = max(n3, x);

        x = 0;
        while (t % 5 == 0) {
            x += 1;
            t /= 5;
        }
        n5 = max(n5, x);
    }

    int cn = n4 + n2 + n3 + n5;
    n3 += (n3 + 1) * (N - cn) / (cn + 4);
    n4 += (n4 + 1) * (N - cn) / (cn + 4);
    n5 += (n5 + 1) * (N - cn) / (cn + 4);
    n2 = N - n3 - n4 - n5;
    string s;
    s.append(n2, '2').append(n3, '3').append(n4, '4').append(n5, '5');
    return s;
}

int main() {
    cin >> T;
    cin >> R >> N >> M >> K;
    cout << "Case #1:" << endl;
    for (int r = 0; r < R; ++r) {
        for (int i = 0; i < K; ++i) {
            cin >> s[i];
        }
        cout << guess() << endl;
    }
    
    return 0;
}
