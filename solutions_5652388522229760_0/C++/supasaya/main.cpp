#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int TC = 1, T, N;
int sum = 0;
int a[10];

void check(long long num) {
    int digit;
    while (num) {
        digit = num % 10;
        num = num / 10;
        if (a[digit] == 0) {
            sum++;
            a[digit] = 1;
        }
    }
}

int main ()
{
    for (cin >> T; TC <= T; TC++) {
        memset(a, 0, sizeof(a));
        sum = 0;
        cin >> N;
        if (N == 0) {
            cout << "Case #" << TC << ": " << "INSOMNIA" << endl;
        } else {
            int i = 1;
            while (true) {
                check(i*N);
                if (sum == 10) {
                    break;
                }
                i++;
            }
            cout << "Case #" << TC << ": " << i*N << endl;
        }

    }
    return 0;
}
