#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <deque>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>

using namespace std;

int main() {
    ifstream ifs("in.in");
    ofstream ofs("out.out");

    int T;
    ifs >> T;
    for (int t = 1; t <= T; ++t) {
        int N;
        ifs >> N;

        deque<int> naomi;
        for (int n = 0; n < N; ++n) {
            string weight;
            ifs >> weight;
            weight.erase(0, 2);

            for (size_t i = 0; i < 6 - weight.length(); ++i) {
                weight.append("0");
            }

            istringstream iss(weight);
            int w;
            iss >> w;

            naomi.push_back(w);
        }

        deque<int> ken;
        for (int n = 0; n < N; ++n) {
            string weight;
            ifs >> weight;
            weight.erase(0, 2);

            for (size_t i = 0; i < 6 - weight.length(); ++i) {
                weight.append("0");
            }

            istringstream iss(weight);
            int w;
            iss >> w;

            ken.push_back(w);
        }

        sort(naomi.begin(), naomi.end());
        sort(ken.begin(), ken.end());

        deque<int> naomi2 = naomi;
        deque<int> ken2 = ken;

        // Deceitful War
        int naomiScore = 0;
        for (int n = 0; n < N; ++n) {
            int naomiMin = naomi.front();
            int kenMin = ken.front();

            if (naomiMin < kenMin) {
                naomi.pop_front();
                ken.pop_back();
            } else {
                ++naomiScore;
                naomi.pop_front();
                ken.pop_front();
            }
        }

        // War
        int naomiScore2 = 0;
        for (int n = 0; n < N; ++n) {
            // Naomi
            int naomiWeight = naomi2.back();
            naomi2.pop_back();

            // Ken
            int kenWeightIndex = -1;
            for (size_t i = 0; i < ken2.size(); ++i) {
                if (ken2[i] > naomiWeight) {
                    kenWeightIndex = i;
                }
            }

            if (kenWeightIndex == -1) {
                ++naomiScore2;
                ken2.pop_front();
            } else {
                ken2.erase(ken2.begin() + kenWeightIndex);
            }
        }

        ofs << "Case #" << t << ": " << naomiScore << ' ' << naomiScore2 << endl;
    }

    return 0;
}
