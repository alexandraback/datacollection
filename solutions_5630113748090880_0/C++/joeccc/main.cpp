#include <iostream>
#include <map>

using namespace std;

int main() {
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        int n;
        cin >> n;

        map<int, int> count;

        int rowCount = n * 2 - 1;
        for (int j = 0; j < rowCount; j++) {
            for (int k = 0; k < n; k++) {
                int h;
                cin >> h;
                count[h]++;
            }
        }

        cout << "Case #" << i << ":";
        for (int j = 1; j <= 2500; j++) {
            if (count[j] % 2 != 0) {
                cout << " " << j;
            }
        }
        cout << endl;

    }
    return 0;
}