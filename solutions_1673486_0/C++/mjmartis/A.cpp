#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

int main(int argc, char *argv[]) {
    int T;
    cin >> T;
    
    for(int c = 1; c <= T; c++) {
        int A, B;
        cin >> A >> B;
        
        double E3 = -1;
        double tally = 1;
        
        for(int i = 0; i < A; i++) {
            double P;
            cin >> P;
            tally *= P;
            double t = tally * (A - i - 1 + B - i) + (1 - tally) * (A - i - 1 + B - i + B + 1);
            
            if(E3 < 0 || t < E3) E3 = t;
        }
        
        double E1 = tally * (B - A + 1) + (1 - tally) * (B - A + 1 + B + 1);
        double E2 = 1 + B + 1;
        //if(A == B) E2 = (1 - tally) * E2 + tally * 1;
        
        cout << "Case #" << c << ": " << fixed << setprecision(6) << min(E1, min(E2, E3)) << endl;
    }
}