#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(int argc, char **argv)
{
        int T;
        cin >> T;
        for (int t = 0; t < T; t++) {
                int64_t K, C, S;
                cin >> K >> C >> S;
                cout << "Case #" << t+1 << ":";
                if (C == 1) {
                        if (S < K) {
                                cout << " IMPOSSIBLE";
                        }
                        else {
                                for (int i = 0; i < K; i++)
                                        cout << " " << i + 1;
                        }
                }
                else {
                        if (S < (K + 1) / 2) {
                                cout << " IMPOSSIBLE";
                        }
                        else {
                                vector<int64_t> r(K);
                                int64_t k = 1;
                                for (int i = 0; i < C; i++) {
                                        for (int j = 0; j < K; j++)
                                                r[j] += j * k;
                                        k *= K;
                                }
                                for (int i = 0; i < K / 2; i++)
                                        cout << " " << r[i*2] + 2;
                                if (K & 1)
                                        cout << " " << r[K-1] + 1;
                        }
                }
                cout << endl;
        }
        return 0;
}
