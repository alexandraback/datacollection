#include <iostream>
#include <cstring>
using namespace std;

void mainB() {
    unsigned int T,N,S,p;
    int minNormal, minSurprise;
    unsigned int countNormal, countSurprise;
    unsigned int score;

    cin >> T;
    for (unsigned int i=0;i<T;++i) {
        cin >> N >> S >> p;

        if (p == 0) {
            minNormal = 0;
            minSurprise = 0;
        } else if (p == 1) {
            minNormal = 1;
            minSurprise = 1;
        } else {
            minNormal = 3*p-2;
            minSurprise = 3*p-4;
        }

        countNormal = 0;
        countSurprise = 0;

        for (unsigned int j=0;j<N;++j) {
            cin >> score;
            if ((int)score >= minNormal) ++countNormal;
            else if ((int)score >= minSurprise) ++countSurprise;
        }
        if (countSurprise > S) countSurprise = S;

        cout << "Case #" << (i+1) << ": " << countNormal+countSurprise << endl;
    }
}

