#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main() {
    int count;
    cin >> count;

    for (int i = 1; i <= count; i++) {

        int N;
        cin >> N;

        if (N == 0) {

            cout << "Case #"<< i <<": INSOMNIA"<< endl;
            continue;
        }

        bool check[10] = {0,};

        int k;
        for (k = 1;; k++) {

            int nk = k * N;
            // cout << nk <<endl;

            while (nk > 0) {
                int digit = nk % 10;
                // cout << digit;
                check[digit] = true;
                nk /= 10;
            }

            // if condition meet, break
            bool condition = true;
            for (int j = 0; j < 10; j++) {
                if (check[j] == false) {
                    condition = false;
                    break;
                }
            }

            if (condition == true) {
                break;
            }

        }

        cout << "Case #"<< i <<": "<< k * N << endl;

    }

    return 0;
}