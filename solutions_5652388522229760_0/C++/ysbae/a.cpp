#include <cstdio>
#include <cstdlib>
#include <iostream>

using namespace std;

void markDigit(long long n, int *check) {
    while (n > 0) {
        check[n % 10] = 1;
        n /= 10;
    }
}

int main() {
    int tc, t, n, j;
    long long i;
    int check[10];

    cin >> t;
    for (tc = 1; tc <= t; tc++) {
        cin >> n;
        cout << "Case #" << tc << ": ";
        if (n == 0) 
            cout << "INSOMNIA" << endl;
        else {
            memset(check, 0, sizeof(check));
            for (i = 1; ; i++) {
                markDigit(n * i, check);
                for (j = 0; j < 10; j++) 
                    if (check[j] == 0) break;
                if (j == 10) {
                    cout << n * i << endl;
                    break;
                }
            }
        }
    }

    return 0;
}
