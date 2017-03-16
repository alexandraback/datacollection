#include <iostream>
#include <string>

using namespace std;

int main() {
    int tmax, max;
    string s;
    cin >> tmax;
    for (int t = 1; t <= tmax; t++) {
        cin >> max >> s;
        int totalCount = 0;
        int added = 0;
        for (int i = 0; i <= max; i++) {
            if (s[i] - '0' > 0) {
                while (totalCount < i) {
                    added++;
                    totalCount++;
                }
                totalCount += s[i] - '0';
            }
        }
        cout << "Case #" << t << ": " << added << endl;
    }
}