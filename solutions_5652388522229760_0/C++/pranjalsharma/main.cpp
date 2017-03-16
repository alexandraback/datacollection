#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream fin("A-small-attempt0.in");
    ofstream fout("outputsmall.txt");
    int T, d;
    long long n, r, p;
    int digitsCovered;
    bool digit[10];
    fin >> T;
    for(int i = 0; i < T; i++) {
        //cout << "iteration " << i + 1 << " :\n";
        fin >> n;
        //cout << "   n = " << n << "\n";
        digitsCovered = 0;
        if(n == 0){
            fout << "Case #" << i+1 << ": " << "INSOMNIA" <<"\n";
            //cout << "   No need to go further as n == 0\n";
            //cout << "   ANSWER = INSOMNIA\n";
            continue;
        }
        for(int j = 0; j < 10; j++) {
            digit[j] = false;
        }
        for(int k = 1; digitsCovered != 10; k++) {
            //cout << "       Subiteration " << k << "\n";
            r = k*n;
            p = r;
            //cout << "       Operating on k*n = " << p << "\n";
            while(p != 0) {
                //cout << "           Sub-Subiteration on shifted p " << p << "\n";
                d = p%10;
                p = p/10;
                if(!digit[d]){
                    //cout << "           digit d " << d << " now noted\n";
                    digit[d] = true;
                    digitsCovered++;
                }
            }
        }
        //cout << "   ANSWER " << r << "\n";
        fout << "Case #" << i+1 << ": " << r <<"\n";
    }
    return 0;
}
