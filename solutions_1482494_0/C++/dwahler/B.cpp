#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <string>
#include <sstream>
#include <deque>
#include <queue>
#include <set>
#include <tr1/unordered_set>
#include <tr1/unordered_map>

#define D(x)

using namespace std;
using namespace std::tr1;

int main() {
    int T;
    cin >> T;

    for (int testCase = 1; testCase <= T; testCase++) {
        int N;
        cin >> N;

        vector<int> a(N), b(N);
        for (int i = 0; i < N; i++) {
            cin >> a[i] >> b[i];
        }

        int currentStars = 0;
        int completedLevels = 0;
        int levelCount = 0;
        vector<int> stars(N);

        bool failed = false;
        while (completedLevels < N) {
            int bestCandidate = -1;
            int bestStars = -1;
            bool bestIsTwoStar = false;

            for (int i = 0; i < N; i++) {
                if (stars[i] < 2 && b[i] <= currentStars) {
                    bestCandidate = i;
                    bestStars = 2;
                    break;
                } else if (stars[i] < 1 && a[i] <= currentStars) {
                    if (bestCandidate == -1 || b[i] > b[bestCandidate]) {
                        bestCandidate = i;
                        bestStars = 1;
                    }
                }
            }

            if (bestCandidate == -1) {
                failed = true;
                break;
            } else {
                D(cerr << "best candidate is " << bestCandidate << "[" << bestStars << "]" << endl);
                currentStars += bestStars - stars[bestCandidate];
                levelCount++;
                if (bestStars == 2) completedLevels++;
                stars[bestCandidate] = bestStars;
            }
        }

        cout << "Case #" << testCase << ": ";
        if (failed) {
            cout << "Too Bad";
        } else {
            cout << levelCount;
        }
        cout << endl;
    }
}
