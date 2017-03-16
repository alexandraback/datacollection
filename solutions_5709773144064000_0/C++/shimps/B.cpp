#include <iostream>
#include <iomanip>

using namespace std;

void do_case(int cn) {
    double c, f, x;
    cin >> c >> f >> x;
    double n = 0, p = 2;
    double bres = 0, res = x / p;
    while (true) {
        n++;
        double bnres = bres + (c / p);
        double np = p + f;
        double nres = (x / np);
        if(bnres + nres < bres + res) {
            bres = bnres;
            p = np;
            res = nres;
        } else {
            break;
        }
    }
    cout << "Case #" << cn << ": " << fixed << setprecision(9) << bres + res << endl;
}

int main() {
    int T, cn = 1;
    cin >> T;
    while(T) {
        do_case(cn);
        cn++;
        T--;
    }
    return 0;
}
