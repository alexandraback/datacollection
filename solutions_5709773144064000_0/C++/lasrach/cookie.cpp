/**
 * @author: Ruben S. Andrist
 * @version: 0.1
 * @date: 2014-04-11
 * Contact: lasrach[at]gmail.com
 */

#include <set>
#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
    int cases = 0;
    scanf(" %d", &cases);
    for (int caseno = 1; caseno <= cases; caseno++) {
        printf("Case #%d: ", caseno);

        double C=0, F=0, X=0;
        scanf(" %lf %lf %lf", &C, &F, &X);


        int farms = 0;
        double time = 0.0;
        double income = 2.0;
        double finish = X/income;
        double estimate = 0.0;
        while (true) {
            farms++;
            time += C/income;
            income += F;
            estimate = time + X/income;
            if (estimate > finish) {
                break;
            } else {
                finish = estimate;
            }
        }
        printf("%.7lf\n", finish);

    }
    return 0;
}

// vim: set ff=unix ai tw=80 ts=4 sts=4 sw=4 et:
