#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

inline bool StandingOvation(const vector<int> &audience) {
    int standing = 0, total = 0;
    for (int i = 0; i < int(audience.size()); ++i) {
        total += audience[i];
        if (standing >= i)
            standing += audience[i];
    }
    return standing == total;
}

int main() {
    ifstream cin("input.txt");
    ofstream cout("output.txt");
    int testCount;
    cin >> testCount;
    for (int t = 1; t <= testCount; ++t) {
        int n;
        string audienceString;
        cin >> n >> audienceString;
        vector<int> audience = vector<int>(n + 1);
        for (int i = 0; i <= n; ++i)
            audience[i] = int(audienceString[i] - '0');
        int left = 0, right = n - 1, add = n;
        while (left <= right) {
            int middle = (left + right) / 2;
            audience[0] += middle;
            if (StandingOvation(audience)) {
                right = middle - 1;
                add = middle;
            } else {
                left = middle + 1;
            }
            audience[0] -= middle;
        }
        cout << "Case #" << t << ": " << add << "\n";
    }
    cin.close();
    cout.close();
    return 0;
}
