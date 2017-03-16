#include <iostream>

using namespace std;

int main() {
    int t; // number of test cases
    int curCase = 1;

    cin >> t;
    while (t--) {
        cout << "Case #" << curCase << ": ";
        char delim;
        int p, q;
        cin >> p >> delim >> q;

        int count = 0;
        bool possible = true;
        while (q > 1 && count <= 40 && p != q) {
            if (q % 2 == 1) {
                possible = false;
                break;
            }
            else {
                if (q > p)
                    count++;
                q /= 2;
            }
        }

        if (possible && count <= 40) {
            cout << count << endl;
        }
        else {
            cout << "impossible" << endl;
        }

        curCase++;
    }
}
