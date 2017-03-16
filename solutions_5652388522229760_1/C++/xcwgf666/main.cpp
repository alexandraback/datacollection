#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long lastBeforeAsleep (int n) {
    if (n == 0)
        return -1;
    vector<bool> seen;
    seen.resize(10);
    for(int i = 0; i < 10; i++)
        seen[i] = false;
    for(long long currentNumber = n; ; currentNumber += n) {
        long long k = currentNumber;
        while (k > 0) {
            seen[k % 10] = true;
            k /= 10;
        }
        bool seenAll = true;
        for(int i = 0; i < 10; i++)
            if (!seen[i]) {
                seenAll = false;
                break;
            }
        if (seenAll)
            return currentNumber;
    }
}

int main(int argc, const char * argv[]) {
    int testCases;
    cin >> testCases;
    for (int currentCase = 1; currentCase <= testCases; currentCase++) {
        int n;
        cin >> n;
        long long answer = lastBeforeAsleep(n);
        if (answer == -1)
            cout << "Case #" << currentCase << ": INSOMNIA" << endl;
        else
            cout << "Case #" << currentCase << ": " << answer << endl;
    }
    return 0;
}
