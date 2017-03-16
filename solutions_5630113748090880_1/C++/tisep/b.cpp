#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main()
{
    int T; cin >> T;
    for (int cas = 1; cas <= T; ++cas) {
        int N; cin >> N;
        map<int, int> height2freq;

        for (int I = 0; I < 2*N-1; ++I) {
            for (int J = 0; J < N; ++J) {
                int h; cin >> h;
                height2freq[h]++;
            }
        }

        vector<int> missing_heights;
        for (const auto &p: height2freq) {
            if (p.second % 2 == 1) // odd occured
                missing_heights.push_back(p.first);
        }

        // sort(missing_heights.begin(), missing_heights.end());
        cout << "Case #" << cas << ":";
        for (auto h: missing_heights)
            cout << " " << h;
        cout << "\n";
    }

    return 0;
}


