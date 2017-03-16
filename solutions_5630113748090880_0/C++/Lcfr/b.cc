#include <iostream>
#include <vector>

using namespace std;

int main() {
        int T;
        cin >> T;
        for (int i = 1; i <= T; ++i) {
                int N;
                cin >> N;
                int num = (2 * N - 1) * N;
                vector<int> h(2501, 0);
                while (num--) {
                        int t;
                        cin >> t;
                        h[t] += 1;
                }
                cout << "Case #" << i << ":";
                for (int j = 1; j <= 2500; ++j) {
                        if (h[j] % 2 == 1)
                                cout << " " << j;
                }
                cout << endl;
        }
        return 0;
}