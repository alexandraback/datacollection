#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <math.h>
using namespace std;

int main()
{
    int T;
    cin >> T;

    for (int t = 0; t < T; ++t) {
        int D;
        cin >> D;

        // input
        vector<int> P(D);
        int Pmax = 0;
        int Pimax = 0;
        for (int i = 0; i < D; ++i) {
            string Ptmp;
            cin >> Ptmp;
            P[i] = atoi(Ptmp.data());
            if (Pmax < P[i]) {
                Pmax = P[i];
                Pimax = i;
            }
        }

        int min_score = INT_MAX;
        for (int groups = 1; groups <= Pmax; ++groups) {
            int jobs = ceil((double)Pmax / groups);
            int score = (groups - 1) + jobs;
            
            for (int i = 0; i < D; ++i) {
                if (i != Pimax && P[i] > jobs) {
                    score += ceil((double)P[i] / groups) - 1;
                }
            }

            min_score = min(score, min_score);
        }

        cout << "Case #" << (t + 1) << ": " << min_score << endl;
    }

    return 0;
}
