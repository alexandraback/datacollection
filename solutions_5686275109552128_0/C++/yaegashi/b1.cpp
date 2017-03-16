#include <iostream>
#include <vector>
#include <string>
#include <climits>

using namespace std;

int main()
{
    int T;
    cin >> T;
    for (int testcase = 0; testcase < T; testcase++) {
        int D, p, max = 0, h[1001] = {};
        cin >> D;
        for (int i = 0; i < D; i++) {
            cin >> p;
            h[p]++;
            if (p > max)
                max = p;
        }
        int min = INT_MAX;
        for (int i = 1; i <= max; i++) {
            int count = 0;
            for (int j = i+1; j <= max; j++)
                count += h[j] * (((j+i-1) / i) - 1);
            count += i;
            if (count < min)
                min = count;
        }
        cout << "Case #" << testcase+1 << ": " << min << endl;
    }
    return 0;
}

// vim: set sw=4:
