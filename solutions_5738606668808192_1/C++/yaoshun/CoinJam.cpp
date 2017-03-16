#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <stack>
using namespace std;

int main() {
    int T;
    cin >> T;
    
    for (int i = 0; i < T; i++) {
        int N, J;
        cin >> N >> J;
        cout << "Case #" << (i + 1) << ": " << endl;
        
        int n = N / 2 - 2;
        // "10 .. 11 .. 11 .. 01" series.
        // When n = 6, there are 15 possibilities.
        for (int j = 0; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                cout << "10";
                cout << string(j * 2, '0');
                cout << "11";
                cout << string((k - j - 1) * 2, '0');
                cout << "11";
                cout << string((n - 1 - k) * 2, '0');
                cout << "01";
                cout << " 3 2 3 2 7 2 3 2 3" << endl;
                if (--J == 0) return 0;
            }
        }
         
        // "11 .. 01 .. 10 .. 11" series, 15 possibilities.
        // "11 .. 10 .. 01 .. 11" series, 15 possibilities.
        for (int j = 0; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                cout << "11";
                cout << string(j * 2, '0');
                cout << "01";
                cout << string((k - j - 1) * 2, '0');
                cout << "10";
                cout << string((n - 1 - k) * 2, '0');
                cout << "11";
                cout << " 3 2 3 2 7 2 3 2 3" << endl;
                if (--J == 0) return 0;
            }
        }
         
        for (int j = 0; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                cout << "11";
                cout << string(j * 2, '0');
                cout << "10";
                cout << string((k - j - 1) * 2, '0');
                cout << "01";
                cout << string((n - 1 - k) * 2, '0');
                cout << "11";
                cout << " 3 2 3 2 7 2 3 2 3" << endl;
                if (--J == 0) return 0;
            }
        }

        // "11 .. 11 .. 11" series: 6 possibilities.
        for (int j = 0; j < n; j++) {
            cout << "11";
            cout << string(j * 2, '0');
            cout << "11";
            cout << string((n - 1 - j) * 2, '0');
            cout << "11";
            cout << " 3 2 3 2 7 2 3 2 3" << endl;
            if (--J == 0) return 0;
        }

        // "10 .. 01 .. 10 .. 01 .. 10 .. 01" series.
        // When n = 6, there are 15 possibilities.
        for (int j = 0; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                for (int x = k + 1; x < n; x++) {
                    for (int y = x + 1; y < n; y++) {
                        cout << "10";
                        cout << string(j * 2, '0');
                        cout << "01";
                        cout << string((k - j - 1) * 2, '0');
                        cout << "10";
                        cout << string((x - k - 1) * 2, '0');
                        cout << "01";
                        cout << string((y - x - 1) * 2, '0');
                        cout << "10";
                        cout << string((n - 1 - y) * 2, '0');
                        cout << "01";
                        cout << " 3 2 3 2 7 2 3 2 3" << endl;
                        if (--J == 0) return 0;
                    }
                }
            }
        }
    }
    return 0;
}
