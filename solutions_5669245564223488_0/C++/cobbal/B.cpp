#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int main()
{
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {
        int N;
        cin >> N;
        vector<string> cars;
        for (int n = 0; n < N; n++) {
            string a;
            cin >> a;
            cars.push_back(a);
        }

        vector<int> order;
        for (int n = 0; n < N; n++) {
            order.push_back(n);
        }

        bool hit[256];
        char last_seen = 0;
        long count = 0;

        do {
            fill(hit, hit + 256, false);
            char last_seen = 0;
            bool fail = false;
            for (int i : order) {
                for (char c : cars[i]) {
                    if (c != last_seen) {
                        if (hit[c]) {
                            fail = true;
                            break;
                        }
                        hit[c] = true;
                        last_seen = c;
                    }
                }
                if (fail) {
                    break;
                }
            }
            if (!fail) {
                count++;
            }
        } while (next_permutation(order.begin(), order.end()));

        cout << "Case #" << t + 1 << ": " << count << endl;
    }
    return 0;
}
