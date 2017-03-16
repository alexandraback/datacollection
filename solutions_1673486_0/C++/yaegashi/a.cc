#include <sstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;


void
calc(int A, int B, double *p, double *a, int *r)
{
        for (int i = 0; i < A; i++)
                cerr << " " << r[i];

        double prob = 1.0;
        for (int i = 0; i < A; i++)
                if (r[i]) prob *= 1 - p[i];
                else prob *= p[i];
        cerr << " " << prob;
        cerr << endl;

        bool fail = false;
        for (int i = A-1; i >= 0; i--) {
                if (r[A-i-1]) fail = true;
                a[i] += prob * (fail ? 2*B+2*i+2 : B+2*i+1);
        }
}


void
rec(int A, int B, double *p, double *a, int *r, int n)
{
        if (A == n) {
                calc(A, B, p, a, r);
                return;
        }
        r[n] = 0;
        rec(A, B, p, a, r, n+1);
        r[n] = 1;
        rec(A, B, p, a, r, n+1);
}


int
main(int argc, char **argv)
{
        int T;

        string lineT;
        getline(cin, lineT);
        stringstream ssT(lineT);
        ssT >> T;

        for (int i = 0; i < T; i++) {

                int A, B;
                string line1, line2;
                getline(cin, line1);
                getline(cin, line2);
                stringstream ss1(line1), ss2(line2);

                ss1 >> A; ss1 >> B;
                double p[A];
                double a[A+2];
                int r[A];
                for (int j = 0; j < A; j++)
                        ss2 >> p[j];
                for (int j = 0; j < A; j++)
                        a[j] = 0.0;
                a[A] = B+2*A+1;
                a[A+1] = A+B+2;
                rec(A, B, p, a, r, 0); 
                double answer = B * 10.0;
                for (int j = 0; j < A+2; j++)
                        if (a[j] < answer)
                                answer = a[j] ;

                printf("Case #%d: %lf\n", i+1, answer-A);
                //cout << "Case #" << i+1 << ": " << answer-A << endl;

        }

        return 0;
}
