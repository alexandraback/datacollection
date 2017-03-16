#include <iostream>
#include <vector>

using namespace std;

int t;
int n;

int main() {
    cin >> t;
    for (int _ = 1; _ <= t; _++) {
        cin >> n;
        vector<int> buffer(2501, 0);
        for (int k = 1; k <= 2 * n - 1; k++) {
            for (int l = 1; l <= n; l++) {
                int tmp;
                cin >> tmp;
                buffer[tmp]++;
            }
        }
        // print
        cout << "Case #" << _ << ": ";
        for (int i = 1; i <= 2500; i++) {
            if (buffer[i] % 2 == 1) {
                cout << i << " ";
            }
        }
        cout << endl;
    }
    return 0;
}