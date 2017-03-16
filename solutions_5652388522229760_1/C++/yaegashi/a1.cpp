#include <iostream>

using namespace std;

int main(int argc, char **argv)
{
        int T;
        cin >> T;
        for (int t = 0; t < T; t++) {
                int64_t N;
                cin >> N;
                int64_t n = 0;
                if (N > 0) {
                        int seen = 0;
                        while (seen < 1023) {
                                n += N;
                                //cerr << n << endl;
                                for (int64_t d = n; d > 0; d /= 10)
                                        seen |= 1 << (d % 10);
                        }
                }
                cout << "Case #" << t+1 << ": ";
                if (n > 0)
                        cout << n;
                else
                        cout << "INSOMNIA";
                cout << endl;
        }
        return 0;
}
