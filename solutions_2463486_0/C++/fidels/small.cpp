#include <iostream>
using namespace std;

bool ispal(long long n) {
    int d[16], D = 0;
    while (n) {
        d[D++] = n%10;
        n /= 10;
    }
    for (int i=0; i<D/2; i++) if (d[i] != d[D-1-i]) return false;
    return true;
}

int main() {
    int RES, t, T;
    long long A, B, i;

    cin >> T;
    for (t=1; t<=T; t++) {
        cin >> A >> B; RES = 0;
        for (i=1LL; i*i<=B; i++) if (i*i >= A && ispal(i) && ispal(i*i)) RES++;
        cout << "Case #" << t << ": " << RES << endl;
    }

    return 0;
}
