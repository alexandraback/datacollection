#include <iostream>
#include <vector>

using namespace std;

int caseCount;
int r, c, w;

int f[70000];

int convertStates(vector<int> &states) {
    int result = 0;
    for (int i = 0; i < c; ++i) {
        result = result * 3 + states[i];
    }
    return result;
}

void printstate(vector<int> &states) {
    for (int i = 0; i < c; ++i) {
        cout << states[i] << " ";
    }
}

void solve(int notFixed, int ones, vector<int> &states) {
    int best = -1;
//    cout << notFixed << ", " << ones << ": ";
//    printstate(states); cout << endl;
    if (ones > notFixed) {
        best = - 1;
    } else if (ones == 0) {
        bool start = false;
        int startPoint = -1, i;
        for (i = 0; i < c; ++i) {
            if (states[i] == 2 && !start) {
                start = true;
                startPoint = i;
            } else if (states[i] == 1 && start) {
                break;
            }
        }
//        std::cout << i << " - " << startPoint << " ? " << w << endl;
        if (i - startPoint == w) best = 0;
    } else {
        for (int i = 0; i < c; ++i) {
            if (states[i] == 0) {
                int bestForBrother = -1;
                for (int ship = 1; ship <= 2; ++ship) {
                    states[i] = ship;
                    int stateNum = convertStates(states);
                    if (f[stateNum] == -2) solve(notFixed - 1, ones - ((ship == 2) ? 1 : 0), states);
                    if (f[stateNum] >= 0 && f[stateNum] + 1 > bestForBrother) {
                        bestForBrother = f[stateNum] + 1;
                    }
                }
                if (bestForBrother >= 0 && (best == -1 || best > bestForBrother)) {
                    best = bestForBrother;
                }
                states[i] = 0;
            }
        }
    }
    f[convertStates(states)] = best;
//    printstate(states);
//    cout << f[convertStates(states)] << endl;
}

int main(int argc, char *argv[]) {
    cin >> caseCount;
    vector<int> states;
    for (int caseNum = 1; caseNum <= caseCount; ++caseNum) {
        cin >> r >> c >> w;
        for (int i = 0; i < 70000; ++i) { f[i] = -2; }
        states.clear();
        for (int i = 0; i < c; ++i) states.push_back(0);
        solve(c, w, states);
        cout << "Case #" << caseNum << ": " << f[0] << endl;
    }
    return 0;
}
