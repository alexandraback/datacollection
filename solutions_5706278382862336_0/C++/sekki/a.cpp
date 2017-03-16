#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int ngen(long long top, long long bot)
{
    int pow2 = 1;
    while ((top*pow(2,pow2)) < bot) {
        pow2++;
    }
    return pow2;
}

int main()
{
    int ncases;
    cin >> ncases;

    for (int i = 0; i < ncases; i++) {
        long long top, bot;
        char c;
        cin >> top >> c >> bot;

        long long nances = pow(2,40);
        cout << "Case #" << i+1 << ": ";
        if ((nances % bot) == 0) {
            //something p/q simplification
            int gen = ngen(top, bot);
            cout << gen << endl;
        } else {
            cout << "impossible" << endl;
        }
    }

    return 0;
}
