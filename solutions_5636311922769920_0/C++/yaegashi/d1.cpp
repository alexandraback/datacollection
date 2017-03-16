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
                vector<int64_t> r(K);
                int64_t k = 1;
                for (int i = 0; i < C; i++) {
                        for (int j = 0; j < K; j++)
                                r[j] += j * k;
                        k *= K;
                }
                cout << "Case #" << t+1 << ":";
                for (auto i: r)
                        cout << ' ' << i+1;
                cout << endl;
        }
        return 0;
}
