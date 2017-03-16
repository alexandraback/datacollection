#include <cstdlib>
#include <climits>
#include <sstream>
#include <string>
#include <iostream>
#include <cstdio>

// STL
#include <algorithm>
#include <vector>
#include <map> // contains multimap
#include <set> // contains multiset
#include <queue> // contains priority_queue
#include <deque>
#include <list>
#include <stack>


using namespace std;

int lvl;

int solve(bool * done_1, bool * done_2, int * req_1, int * req_2, int stars) {
    if (stars == 2*lvl) return 0;

    int sol = -1;
    int best = -1;

    int ok = 0;
    for (int i = 0; i < lvl; ++i) {
        // 2 stars ?
        if (!done_1[i] && stars >= req_2[i]) {
            done_1[i] = true;
            done_2[i] = true;
            ++ok;
            stars += 2;
        }
    }
    if (ok != 0) {
        sol = solve(done_1, done_2, req_1, req_2, stars);
        if (sol == -1) return -1;
        return sol + ok;
    }

    for (int i = 0; i < lvl; ++i) {
        if (!done_2[i] && stars >= req_2[i]) {
            done_2[i] = true;
            sol = solve(done_1, done_2, req_1, req_2, stars + 1);
            if (sol == -1) return -1;
            return 1 + sol;
        }
    }

    int max = -1;
    int idx = -1;
    for (int i = 0; i < lvl; ++i) {
        if (!done_1[i] && stars >= req_1[i]) {
            if (req_2[i] > max) {
                max = req_2[i];
                idx = i;
            }
        }

    }            
    if (idx ==-1) return -1;
            done_1[idx] = true;
            sol = solve(done_1,done_2, req_1, req_2, stars + 1);
            if (sol != -1 && best == -1) best = 1 + sol;
            else if (sol != -1)
                best = (sol+1) < best ? (sol+1) : best;

    return best;
}


int main() {
    int numcase;

    freopen("B-large.in", "r", stdin);
    freopen("B-large2.out", "w", stdout);

    cin >> numcase;
    for (int i = 0; i < numcase; ++i) {
        cin >> lvl;
        bool done_1[lvl];
        bool done_2[lvl];
        int req_1[lvl];
        int req_2[lvl];
        for (int j = 0; j < lvl; ++j) {
            done_1[j] = false;
            done_2[j] = false;
            cin >> req_1[j];
            cin >> req_2[j];
        }
        cout << "Case #" << i + 1 << ": ";
        int sol = solve(done_1, done_2, req_1, req_2, 0);
        if (sol == -1)
            cout << "Too Bad" << endl;
        else
            cout << sol << endl;
    }

    return 0;
}
