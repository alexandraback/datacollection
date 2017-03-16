#include <iostream>

using namespace std;

int main()
{
        freopen("pass.in", "r", stdin);

        int T, A, B;

        cin >> T;
        for (int i = 0; i < T; i++) {
                cin >> A >> B;
                double probs[A], eval1, eval2 = 100003, pprobs[A];
                for (int j = 0; j < A; j++) {
                        cin >> probs[j];
                        pprobs[j] = probs[j];
                }
                for (int j = A-2; j >= 0; j--)
                        pprobs[j] *= pprobs[j+1];
                eval1 = (B-A+1)*pprobs[0]+(2*B-A+2)*(1-pprobs[0]);
                for (int j = A-1; j >= 0; j--)
                        eval2 = min(eval2, (B-A+1+2*(A-j))*(1-pprobs[j])+(2*B-A+2+2*(A-j))*pprobs[j]);
                cout.precision(6);
                cout.setf(ios::fixed, ios::floatfield);
                cout << "Case #" << (i+1) << ": " << min(min(eval1, eval2), (double) (B+2)) << endl;
        }
} 

