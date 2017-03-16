#include <iostream>

using namespace std;

int main() {
    int t; // number of test cases
    int curCase = 1;

    cin >> t;
    while (t--) {
        cout << "Case #" << curCase << ": ";

        int a, b, k;
        cin >> a >> b >> k;

        int count = 0;
        for (int i = 0; i < a; i++) {
            for (int j = 0; j < b; j++) {
                if ((i & j) < k) {
                    count++;
                }
            }
        }

        cout << count << endl;
        curCase++;
    }

    return 0;
}
