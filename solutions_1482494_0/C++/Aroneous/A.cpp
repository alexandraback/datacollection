#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

enum lstate {
    ZERO, ONE, TWO
};

struct level {
    int one;
    int two;
    lstate state;

    level(int o, int t) {
        state = ZERO;
        one = o;
        two = t;
    }

    bool operator<(const level& o) const {
        return two < o.two;
    }
};

void doCase(int caseNum) {
    int N;
    cin >> N;

    vector<level> levels;

    for (int i = 0; i < N; i++) {
        int ai, bi;
        cin >> ai >> bi;
        level l(ai, bi);
        levels.push_back(l);
    }
    sort(levels.begin(), levels.end());

    int stars = 0;
    int turns = 0;

    bool solved = false;
    bool changed = true;
    while (!solved && changed) {
        changed = false;
        solved = true;
        for (vector<level>::iterator it = levels.begin();
                it != levels.end();
                it++) {
            level& l = *it;

            if (l.two > stars) {
                // sorted by two...can't win more this round
                solved = false;
                break;
            }
            if (l.state != TWO) {
                solved = false;

                if (l.two <= stars) {
                    //cout << "Solving " << l.one << "," << l.two << " from ";
                    // solvable
                    if (l.state == ZERO) {
                        //cout << "zero";
                        stars += 2;
                    } else {
                        //cout << "one";
                        stars++;
                    }
                    //cout << " to two" << endl;
                    turns++;
                    l.state = TWO;
                    changed = true;
                }
            }
        }

        if (!changed) {
            // Check ones
            for (vector<level>::reverse_iterator it = levels.rbegin();
                    it != levels.rend();
                    it++) {
                level& l = *it;
                if (l.state == ZERO) {
                    if (l.one <= stars) {
                        //cout << "Solving " << l.one << "," << l.two <<
                        //    " from zero to one" << endl;
                        // solvable
                        stars++;
                        turns++;
                        l.state = ONE;
                        changed = true;
                        break;
                    }
                }
            }
        }
    }

    if (solved) {
        cout << "Case #" << caseNum << ": " << turns << endl;
    } else {
        cout << "Case #" << caseNum << ": Too Bad" << endl;
    }
}

int main() {
    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        doCase(i+1);
    }
}
