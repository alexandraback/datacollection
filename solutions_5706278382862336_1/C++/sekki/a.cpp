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

long long gcd(long long top, long long bot)
{
    while(true) {
        if (bot < top)
            top = (top % bot);
        else 
            bot = (bot % top);

        if (top <= 1)
            break;
        if (bot <= 1)
            break;
    }
    if ((top == 1) || (bot == 1))
        return 1;
    else
        return max(top, bot);
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

        long long div = gcd(top,bot);

        if ((nances % (bot/div)) == 0) {
            //something p/q simplification
            int gen = ngen(top, bot);
            cout << gen << endl;
        } else {
            cout << "impossible" << endl;
        }
    }

    return 0;
}
