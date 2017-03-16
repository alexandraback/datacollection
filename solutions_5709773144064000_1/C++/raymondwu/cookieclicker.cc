#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <cfloat>
#include <iomanip>
using namespace std;

int main () {
    cout << setprecision(7) << fixed;
    ifstream input;
    input.open("B-large.in");
    int numCases;
    input >> numCases;
    for (int i = 0; i < numCases; i++) {
        double c, f, x;
        input >> c;
        input >> f;
        input >> x;
        double xtime = x/2;
        double ctime = 0;
        double min = DBL_MAX;
        int round = 0;
        while (true) {
            double curr = xtime + ctime;
            if (curr > min)
                break;
            min = curr;
            round++;
            ctime += c/(((double)round-1)*f + 2);
            xtime = x/((double)round*f + 2);
        }
        cout << "Case #" << (i+1) <<": " << min << endl;
    }
}
