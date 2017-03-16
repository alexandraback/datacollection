#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;
    for (int i = 0; i < T; i++) {
        int N;
        cin >> N;
        unordered_set<int> seen;
        int counter = 0;
        if (N == 0) {
            cout << "Case #" << i + 1 << ": INSOMNIA" << endl;
        }
        else {
            for (int j = 1; j < 100; j++) {
                int acc = N * j;
                while (acc > 0) {
                    if (seen.find(acc % 10) == seen.end()) {
                        seen.insert(acc % 10);
                        counter++;
                    }
                    acc = acc / 10;
                }
                if (counter == 10) {
                    cout << "Case #" << i+1 << ": " << j * N << endl;
                    break;
                }
            }
        }
    }
    return 0;
}
