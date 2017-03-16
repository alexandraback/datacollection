#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

int main()
{
    istream& in = cin;
    // ifstream in("a_test.in");

    cout.precision(15);
    
    int T;
    in >> T;
    for (int testCase = 0; testCase != T; ++testCase) {

        int A, B;
        in >> A >> B;
        vector<double> p;
        vector<double> q;
        p.resize(A);
        q.resize(A + 1);
        q[0] = 1.0;
        for (int a = 0; a != A; ++a) {
            in >> p[a];
            q[a + 1] = q[a] * p[a];
        }

        // if press enter right now:
        double best_E = 1 + B + 1;

        // check strategies to delete certain number of chars, type rest and press enter
        int remaining = B - A;
        for (int keep = 0; keep <= A; ++keep) {
            int deletes = A - keep;

            // outcomes:
            //   these kept characters are all correct.
            //   one of them is not correct.
            double expected = (q[keep] * double(2 * deletes + remaining + 1)) +
                ((1 - q[keep]) * (2 * deletes + remaining + 1 + B + 1));

            best_E = min(expected, best_E);
        }

        cout << "Case #" << (testCase + 1) << ": " << best_E << endl;
    }
    return 0;
}
