#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int doit() {
    int N;
    vector <int> F;

    cin >> N;
    for (int i = 0; i < N; i++) {
        int f;
        cin >> f;
        F.push_back(f - 1);
        // cout << F[i] << endl;
    }

    vector <int> maxLine(N, 0);
    vector <int> current(N, -1);
    vector <int> last(N, -1);
    int maxCycle = 0;
    vector <pair <int, int> > pairs;

    for (int i = 0; i < N; i++) {
        if (F[F[i]] == i) {
            pairs.push_back(make_pair(i, F[i]));
            maxCycle = max(maxCycle, 2);
            continue;
        }
        current[i] = i;
        last[i] = 0;
        int j = i;
        for (int k = 1; k <= N; k++) {
            j = F[j];
            if (current[j] == i) {
                maxCycle = max(maxCycle, k - last[j]);
                break;
            }
            current[j] = i;
            last[j] = k;
            maxLine[j] = max(maxLine[j], k);
            if (F[F[j]] == j) {
                break;
            }
        }
    }
    // for (int i = 0; i < N; i++) cout << maxLine[i] << " ";
    // cout << endl;
    int best = maxCycle;
    int c = 0;
    for (vector <pair <int, int> >::iterator it = pairs.begin(); it != pairs.end(); it++) {
        // cout << it->first << " " << it->second << endl;
        c += 2 + maxLine[it->first] + maxLine[it->second];
    }
    return max(best, c / 2);
}

int main(int argc, char *argv[]) {
    int C;
    cin >> C;
    for (int i = 1; i <= C; i++) {
        int res = doit();
        cout << "Case #" << i << ": " << res << endl;
    }
    return 0;
}
