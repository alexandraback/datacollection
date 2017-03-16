#include <cstdio>
#include <cmath>
#include <iostream>

using namespace std;

double C, F, X;

double solve() {
    //cerr << C << " " << F << " " << X << endl;
    double ans = 0;
    int numFarms = 0;
    while (true) {
        long double cur = X / (2. + F * numFarms);
        long double next = X / (2. + F * (numFarms + 1)) + C / (2. + F * numFarms);
        if (cur < next) {
            ans += cur;
            break;
        } else {
            ans += C / (2. + F * numFarms);
            ++numFarms;
        }
    }
    return ans;
}

int main() {
    int numCases;
    scanf("%d", &numCases);
    for (int caseNo = 0; caseNo < numCases; ++caseNo) {
        scanf("%lf %lf %lf", &C, &F, &X);
        printf("Case #%d: %.8lf\n", caseNo + 1, solve());
    }
    return 0;
}


