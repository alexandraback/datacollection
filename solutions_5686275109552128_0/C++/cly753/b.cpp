#include <iostream>

using namespace std;

#define HHH 1002

int d;
int p[HHH];

int sol() {
    int best = HHH;
    for (int i = 1; i < HHH; i++) {
        int cur = 0;
        for (int j = 0; j < d; j++) {
            cur += p[j] / i;
            if (p[j] % i == 0)
                cur--;
        }
        cur += i;
        best = min(best, cur);
    }
    return best;
}

int main(int argc, char const *argv[])
{
    int t;
    cin >> t;
    for (int c = 1; c <= t; c++) {
        cin >> d;
        for (int i = 0; i < d; i++)
            cin >> p[i];

        cout << "Case #" << c << ": " << sol() << endl;
    }
}