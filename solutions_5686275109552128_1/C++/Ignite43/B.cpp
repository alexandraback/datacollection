#include <algorithm>
#include <queue>
#include <map>
#include <vector>
#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

int solve(int max_plate, const vector<int>& plates) {
        int min_time = max_plate;
        for (int i=1; i<max_plate; ++i) {
                int time = i;
                for (int j=0; j<plates.size(); ++j) {
                        if (plates[j] > i) {
                                time += plates[j] % i == 0 ? plates[j]/i-1 : plates[j]/i;
                        }
                }
            min_time = min(min_time, time);
        }

        return min_time;
}

int main(int argc, char *args[]) {
        if (argc == 2 && strcmp(args[1], "small") == 0) {
                freopen("B-small-attempt7.in", "rt", stdin);
                freopen("B-small.out", "wt", stdout);
        }
        else if (argc == 2 && strcmp(args[1], "large") == 0) {
                freopen("B-large.in", "rt", stdin);
                freopen("B-large.out", "wt", stdout);
        }
        else {
                freopen("b.txt", "rt", stdin);
        }

        int N;
        cin >> N;
        for (int i=0; i<N; ++i) {
                int D;
                cin >> D;
                vector<int> plates;
                int max_plate = 0;
                for (int j=0; j<D; ++j) {
                        int pancakes;
                        cin >> pancakes;
                        plates.push_back(pancakes);
                        max_plate = max(max_plate, pancakes);
                }

                cout << "Case #" << i+1 << ": " << solve(max_plate, plates) << endl;
        }

        return 0;
}
