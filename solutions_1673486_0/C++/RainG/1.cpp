#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<double> prob;
vector<double> c;

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        prob.clear();
        c.clear();
        int curr, total;

        cin >> curr >> total;
        for (int j = 0; j < curr; ++j) {
            double p;
            cin >> p;
            prob.push_back(p);
        }

        c.push_back(prob[0]);
        for (int j = 1; j < curr; ++j) {
            c.push_back(c[j-1]*prob[j]);
        }

        double ex = c[curr-1] * (total - curr + 1) + (1-c[curr-1]) * (total - curr + total + 2);
        ex = min(ex, 1 + total + 1.0);

        for (int j = 1; j <= curr; ++j) {
            int correct = (j + (total - curr + j) + 1);
            int inc = correct + total + 1;
            double k1;
            if (curr - j - 1 < 0) 
                k1 = correct;
            else 
                k1 = correct * (c[curr - j - 1]) + inc * (1-c[curr-j-1]);
            ex = min(ex, k1);
        }

        printf("Case #%d: %.6f\n", i+1, ex);
    }

    return 0;
}

