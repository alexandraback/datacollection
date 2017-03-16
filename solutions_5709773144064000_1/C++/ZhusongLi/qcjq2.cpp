#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main() {
    ifstream filein;
    ofstream fileout;
    filein.open("B-large.in",ios::in);
    fileout.open("output",ios::out);
    int T,n,m;
    double C,F,X;
    double t1,t2;
    fileout.precision(10);
    fileout.setf(ios::fixed);
    fileout.setf(ios::showpoint);
    filein >> T;
    for (int i = 0;i < T;i++) {
        double t = 0.0;
        double j = 0.0;
        filein >> C >> F >> X;
        while (1 > 0) {
            t1 = X/(2.0 + j*F);
            t2 = C/(2.0 + j*F) + X/(2.0 + (j+1)*F);
            if (t1 < t2) {
                t = t + t1;
                break;
            }
            else {
                t = t + C/(2.0 + j*F);
                j = j + 1.0;
            }
        }
        fileout << "Case #" << i+1 << ": " << t << endl;
    }
    fileout.close();
}