#include <iostream>
using namespace std;

int main()
{

    int T;
    cin >> T;

    for (int i = 0; i < T; i++) {
        unsigned long long n;
        unsigned long long m = 0;
        unsigned long long k;
        cin >> n;
        int seen = 0;

        if (n == 0) {
            cout << "case #" << i + 1 << ": INSOMNIA\n";
            continue;
        }
        m = n;

        unsigned long long prev_m = m;
        while (seen != 0x000003ff) {
            k = m;

            while (k) {
                size_t d = k % 10;
                k /= 10;
                seen |= (1 << d);
            }

            prev_m = m;
            m += n;
        }
        cout << "case #" << i + 1 << ": " << prev_m << "\n";

    }
    return 0;
}
