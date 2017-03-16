#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

inline int Ceil(const int p, const int q) {
    return (p + q - 1) / q;
}

inline bool Possible(const vector<int> &values, const int wait, const int maxTime) {
    int used = 0;
    for (const auto &v: values) {
        int w = 0;
        if (maxTime > 1) {
            w = max(0, Ceil(v - maxTime, maxTime - 1));
            for (; w > 0 && Ceil(v, w) <= maxTime; --w);
        } else {
            w = v - 1;
        }
        used += w;
        if (used > wait)
            return false;
    }
    return true;
}

inline int GetMinTime(const vector<int> &values, const int wait, const int maxTime) {
    int left = wait + 1, right = maxTime - 1, minTime = maxTime;
    while (left <= right) {
        int middle = (left + right) / 2;
        if (Possible(values, wait, middle - wait)) {
            right = middle - 1;
            minTime = middle;
        } else {
            left = middle + 1;
        }
    }
    return minTime;
}

int main() {
    ifstream cin("input.txt");
    ofstream cout("output.txt");
    int testCount;
    cin >> testCount;
    for (int t = 1; t <= testCount; ++t) {
        int n, maxTime = 0;
        vector<int> values;
        cin >> n;
        values = vector<int>(n);
        for (int i = 0; i < n; ++i) {
            cin >> values[i];
            maxTime = max(maxTime, values[i]);
        }
        int answer = maxTime;
        for (int wait = 1; wait <= maxTime; ++wait)
            answer = min(answer, GetMinTime(values, wait, maxTime));
        cout << "Case #" << t << ": " << answer << "\n";
    }
    cin.close();
    cout.close();
    return 0;
}
