#include <iostream>
#include <algorithm>

using namespace std;

bool cmp(int a, int b) {
    if (a > b) {
        return true;
    } else {
        return false;
    }
}

int main() 
{
    int T, min, max, count, n;
    int d[1020];
    cin >> T;
    for (int I = 0; I < T; ++I)
    {
        cin >> n;
        for (int i = 0; i < n; ++i)
        {
            cin >> d[i];
        }
        sort(d, d + n, cmp);
        max = d[0];
        min = d[0];
        for (int act = 0; act <= min; ++act) {
            while (max > 1) {
                max--;
                count = 0;
                for (int i = 0; i < n; ++i) {
                    count += (d[i] - 1) / max;
                    if (d[i] <= max) {
                        break;
                    }
                }
                if (count > act) {
                    max++;
                    break;
                }
            }
            if (max + act < min) {
                min = max + act;
            }
            if (act > min) {
                break;
            }
        }
        cout << "Case #" << I + 1 << ": ";
        cout << min << endl;
    }
    return 0;
}