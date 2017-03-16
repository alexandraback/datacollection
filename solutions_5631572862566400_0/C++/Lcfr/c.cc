#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

int main() {
        int T;
        cin >> T;
        for (int cas = 1; cas <= T; ++cas) {
                int N;
                cin >> N;
                vector<int> bff(N);
                for (int i = 0; i < N; ++i) {
                        int b;
                        cin >> b;
                        bff[i] = b - 1;
                }
                int ans = 3;
                int max_bits = (1 << N);
                for (int kbits = 0; kbits < max_bits; ++kbits) {
                        int bits = kbits;
                        vector<int> circle;
                        int t = 0;
                        while (bits) {
                                if (bits & 1) circle.push_back(t);
                                ++t;
                                bits = bits >> 1;
                        }
                        int num = circle.size();
                        bool flag = false;
                        do {

                        bool debug = false;
                        // if (num == 6 && circle[0] == 6 && circle[1] == 8 && circle[2] == 2 && circle[3] == 9 && circle[4] == 3 && circle[5] == 0) {
                        //         cerr << "xxx" << endl;
                        //         debug = true;
                        // }
                                bool f = true;
                                for (int i = 0; i < num; ++i) {
                                        int left = (i + num - 1) % num;
                                        int right = (i + 1) % num;
                                        // if (debug) {
                                        //         cerr << circle[left] << '\t' << circle[i] << '\t' << circle[right] << '\n';
                                        // }
                                        if (bff[circle[i]] != circle[left] && bff[circle[i]] != circle[right]) {
                                                f = false;
                                                break;
                                        }
                                }
                                if (f) {
                                        flag = true;
                                        break;
                                }
                        } while(next_permutation(circle.begin(), circle.end()));
                        if (flag && num > ans)
                                ans = num;
                }
                cout << "Case #" << cas << ": " << ans << '\n';
        }
        return 0;
}