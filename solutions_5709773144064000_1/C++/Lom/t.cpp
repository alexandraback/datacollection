#include <algorithm>

#include <deque>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>

#include <iomanip>
#include <iostream>


using namespace std;

typedef long double tdbl;

int main(int argc, char* argv[]) {
    int numTests = 0;
    cin >> numTests;
    for (int test = 1; test <= numTests; ++test) {
        tdbl C, F, X;
        cin >> C >> F >> X;

        tdbl curTime = 0.0;
        tdbl curC = 0.0;
        tdbl curF = 2.0;
        while (curC < X) {
            tdbl ttX = (X - curC) / curF;
            tdbl ttF = (C - curC) / curF;
            if (ttX <= ttF) {
                curC = X;
                curTime += ttX;
                break;
            } else {
                tdbl ttXnewF = X / (curF + F);
                if (ttXnewF + ttF < ttX) {
                    curC = 0.0;
                    curF += F;
                    curTime += ttF;
                } else {
                    curC = X;
                    curTime += ttX;
                    break;
                }
            }
        }

        cout << "Case #" << test << ": " << fixed << setprecision(15) << curTime << endl;
    }

    return 0;
}
