#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int main() {
    int nCases;
    cin >> nCases;
    for (int cnum = 1; cnum <= nCases; cnum++) {
        long double r, t;
        cin >> r >> t;
        //long double ndub = (-(2*r-1)+sqrt(pow(2*r-1, 2)+8*t))/4;
        long double ndub = (2*t)/((2*r-1)+sqrt(pow(2*r-1, 2)+8*t));
        printf("Case #%d: ", cnum);
        cout << (long long)floor(ndub) << endl;
    }
}
