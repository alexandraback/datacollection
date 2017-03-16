#include <iostream>

using namespace std;

int main() {
    int T; cin >> T;
    for (int caseNo = 1; caseNo <= T; ++caseNo) {
        int maxShy = 0;
        cin >> maxShy;
        int * numShy = new int[maxShy + 1];
        string line; cin >> line;
        for (int i = 0; i <= maxShy; ++i) numShy[i] = line[i] - '0';
            int friends = 0;
            int prefSum = 0;
            for (int i = 0; i <= maxShy; ++i) {
            if (prefSum < i) {
                friends += i - prefSum;
                prefSum = i;
            }
            prefSum += numShy[i];
        }
        cout << "Case #" << caseNo << ": " << friends << endl;
    }
    return 0;
}
