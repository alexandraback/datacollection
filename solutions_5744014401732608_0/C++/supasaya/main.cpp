#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <math.h>
#include <iomanip>
#include <sstream>
#include <set>

using namespace std;

int TC = 1, T, B;
long long M;
long long zoufa[60];
int main ()
{
    zoufa[0] = 1;
    zoufa[1] = 1;
    for (int i = 2; i < 60; i++) {
        long long sum = 0;
        for (int j = 0; j < i; j++) {
            sum += zoufa[j];
        }
        zoufa[i] = sum;
    }
    for (cin >> T; TC <= T; TC++) {
        cin >> B >> M;
        long long maxi = zoufa[B-1];
        if (M > maxi) {
            cout << "Case #" << TC << ": IMPOSSIBLE" << endl;
        } else {
            cout << "Case #" << TC << ": POSSIBLE" << endl;
            cout << "0";
            int curpos = 2;
            while (curpos != B+1) {
                if (zoufa[B-curpos] <= M) {
                    cout << "1";
                    M -= zoufa[B-curpos];
                } else {
                    cout << "0";
                }
                curpos++;
            }
            cout << endl;
            for (int i = 2; i < B; i++) {
                for (int j = 1; j <= i; j++) {
                    cout << "0";
                }
                for (int j = i+1; j <= B; j++) {
                    cout << "1";
                }
                cout << endl;
            }
            for (int i = 0; i < B; i++) {
                cout << "0";
            }
            cout << endl;
        }
    }
    return 0;
}