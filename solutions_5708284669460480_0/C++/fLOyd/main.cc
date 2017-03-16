#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int caseCount, keyCount, targetLen, typeTimes;

string keys, target, current;

double res;

void solve(int d, string &current) {
    if (d == typeTimes) {
        for (int i = 0; i + targetLen <= typeTimes; ++i) {
            int count = 0;
            for (int j = i; j < i + targetLen; ++j) {
                if (current[j] == target[j - i]) {
                    count++;
                } else {
                    break;
                }
            }
            if (count == targetLen) {
                res++;
            }
        }
    } else {
        for (int i = 0; i < keyCount; ++i) {
            current[d] = keys[i];
            solve(d + 1, current);
        }
    }
}

int main(int argc, char *argv[]) {
    cin >> caseCount;
    cout << fixed << setprecision(8);
    for (int caseNum = 1; caseNum <= caseCount; ++caseNum) {
        cin >> keyCount >> targetLen >> typeTimes;
        cin >> keys;
        cin >> target;
        for (int i = 0; i < targetLen; ++i) {
            current.push_back('*');
        }
        res = 0;
        solve(0, current);
        if (res != 0) {
            for (int i = 0; i < typeTimes; ++i) {
                res = res / keyCount;
            }
            res = typeTimes - targetLen + 1 - res;
        }
        cout << "Case #" << caseNum << ": " << res * 1.0 << endl;
    }
    return 0;
}
