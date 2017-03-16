#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
    int T;
    cin >> T;
    for (int c = 1; c <= T; c++) {
        int D, p, largest = 0, steps = 0;
        vector<int> pancakes;
        cin >> D;
        for (int i = 0; i < D; i++) {
            cin >> p;
            pancakes.push_back(p);
        }

        int minsteps = 999999, total = 0;
        for (int k = 1; k <= 1000; k++) {
            int cursteps = k;
            for (int i = 0; i < pancakes.size(); i++)
                cursteps += (pancakes[i]-1) / k;
//            cout << k << ": " << cursteps << endl;
            if (cursteps < minsteps) minsteps = cursteps;
        }

        cout << "Case #" << c << ": " << minsteps << endl;
    }

    return 0;
}
