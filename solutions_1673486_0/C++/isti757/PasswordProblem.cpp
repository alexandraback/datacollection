#include <vector>
#include <stdio.h>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int T;
    cin >> T;

    for(int TT = 1; TT <= T; TT++) {
        int A, B;
        cin >> A >> B;

        vector<double> p(A, 0);
        for(int i = 0; i < A; i++)
            cin >> p[i];

        double keep = -1-B;
        for(int i = 0; i < p.size(); i++) {
            keep *= p[i];
        }
        keep += 2+2*B-A;

        double enter = 2+B;

        vector<double> backspace(A, 0);
        backspace[A-1] = -B-1;
        for(int i = A-2; i >= 0; i--) {
            backspace[i] = backspace[i+1]*p[A-i-2];
        }

        for(int i = 1; i <= backspace.size(); i++) {
            backspace[i-1] += i+2*B-(A-i)+2;
        }


        double best = min(keep, enter);
        for(int i = 0; i < backspace.size(); i++)
            best = min(backspace[i], best);

        printf("Case #%d: %.6f\n", TT, best);
    }

    return 0;
}


