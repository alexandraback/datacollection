#include <iostream>
#include <string>
#include <array>
#include <cstring>
#include <queue>

using namespace std;

int dives(int i, int j) {
    return (i + j - 1) / j;
}

int p[1005];
pair<int, int> maxs[1005];
int main() {
    int tmax, d;
    cin >> tmax;
    for (int t = 1; t <= tmax; t++) {
        cin >> d;
        int max = 0;
        for (int i = 0; i < d; i++) {
            cin >> p[i];
            if (p[i] > max) {
                max = p[i];
            }
        }
        int min = 9999;
        for (int i = 0; i < max; i++) {
            for (int j = 0; j < d; j++) {
                maxs[j] = make_pair(p[j], 1);
            }
            for (int k = 1; k <= i; k++) {
                int maxIndex = -1;
                int maxVal = -1;
                for (int j = 0; j < d; j++) {
                    if (dives(maxs[j].first, maxs[j].second) > maxVal) {
                        maxVal = dives(maxs[j].first, maxs[j].second);
                        maxIndex = j;
                    }
                }
                maxs[maxIndex] = make_pair(maxs[maxIndex].first, maxs[maxIndex].second + 1);
            }

            int maxIndex = -1;
            int maxVal = -1;
            for (int j = 0; j < d; j++) {
                if (dives(maxs[j].first, maxs[j].second) > maxVal) {
                    maxVal = dives(maxs[j].first, maxs[j].second);
                    maxIndex = j;
                }
            }
            if (maxVal + i < min) {
                min = maxVal + i;
            }
        }
        cout << "Case #" << t << ": " << min << endl;
    }
}