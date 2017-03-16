#include <iostream>
#include <cmath>

using namespace std;

const double PI = 3.14159265358979323;

int main()
{
    int T;

    cin >> T;

    for (int i=0; i<T; ++i) {
        double r, t;
        cin >> r >> t;

        double n = .25 * (sqrt(4*r*r - 4*r + 8*t + 1) - 2*r + 1);

        cout << "Case #" << (i+1) << ": " << (int)n << endl;
    }

    return 0;
}
