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
    int RES, t, T, NUM = 0;
    long long A, B, i, num[40];

    for (i=1LL; i*i<=100000000000000LL; i++) if (ispal(i) && ispal(i*i)) num[NUM++] = i*i;

    cin >> T;
    for (t=1; t<=T; t++) {
        cin >> A >> B; RES = 0;
        for (i=0; i<NUM; i++) if (num[i] >= A && num[i] <= B) RES++;
        cout << "Case #" << t << ": " << RES << endl;
    }

    return 0;
}
