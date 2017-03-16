#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <string>
#include <sstream>
#include <deque>
#include <queue>
#include <set>
#include <tr1/unordered_set>
#include <tr1/unordered_map>

#define D(x) x

using namespace std;
using namespace std::tr1;

int main() {
    int T;
    cin >> T;

    cout.setf(ios::fixed);
    cout.precision(8);
    cerr.setf(ios::fixed);
    cerr.precision(8);

    for (int testCase = 1; testCase <= T; testCase++) {
        int A, B;
        cin >> A >> B;

        vector<double> p(A);
        for (int i = 0; i < A; i++) {
            cin >> p[i];
        }

        double best = 1+B+1;
        D(cerr << "start over: " << best << endl);

        double allOK = 1.0;
        for (int i = 0; i < A; i++) {
            allOK *= p[i];
        }
        double keepGoing = allOK*(B-A+1)+(1-allOK)*(B-A+1+B+1);
        D(cerr << "keep going: p=" << allOK << " keys=" << keepGoing << endl);
        best = min(best, keepGoing);

        double okSoFar = 1.0;
        for (int i = 0; i < A; i++) {
            okSoFar *= p[i];
            double bs = okSoFar*(2*(A-i-1)+(B-A)+1)+(1-okSoFar)*(2*(A-i-1)+B-A+1+B+1);
            D(cerr << "backspace to " << i << ": p=" << okSoFar << " keys=" << bs << endl);
            best = min(best, bs);
        }

        cout << "Case #" << testCase << ": " << best;

        cout << endl;
    }
}
