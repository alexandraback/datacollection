#include <iostream>
#include <iomanip>

using namespace std;

int main(){
    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        int A, B;
        cin >> A >> B;
        double p[100005];
        double temp;
        cin >> temp;
        p[0] = temp;
        for (int i = 1; i < A; ++i) {
            cin >> temp;
            p[i] = p[i-1] * temp;
        }
        double minkey = B + 2;
        for (int k = 0; k < A; ++k) {
            // cerr << (1-p[A-1-k])*(B+1) << endl;
            double prob = (1.0-p[A-1-k]) * (B+1)*1.0 + (1+B-A+2*k)*1.0;
            // cerr << prob << endl;
            minkey = min(minkey, prob);
        }
        cout << "Case #" << t << ": " << fixed << setprecision(6) << minkey << endl;
    }
}