#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <string>

#define D(x) 

using namespace std;

int main() {
    int numCases;
    cin >> numCases;

    for (int testCase = 1; testCase <= numCases; testCase++) {
        int D;
        cin >> D;

        vector<int> P(D);
        int largest = 0;
        for (int i = 0; i < D; i++) {
            cin >> P[i];
            largest = max(largest, P[i]);
        }

        int best = largest;
        for (int maxSize = 1; maxSize <= largest; maxSize++) {
            int moves = 0;
            for (int i = 0; i < D; i++) {
                moves += (P[i] - 1) / maxSize;
                D(cerr << " pile=" << P[i] << " moves=" << ((P[i]-1)/maxSize) << endl);
            }
            moves += maxSize;

            D(cerr << "maxSize=" << maxSize << " moves=" << moves << endl);
            best = min(best, moves);
        }

        cout << "Case #" << testCase << ": " << best << endl;
    }
}
