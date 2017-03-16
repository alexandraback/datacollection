#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ifstream filein;
    ofstream fileout;
    filein.open("D-large.in",ios::in);
    fileout.open("output",ios::out);
    int T,N,j,Q;
    int dec,war;
    filein >> T;
    for (int i = 0;i < T;i++) {
        filein >> N;
        vector<double> naomi(N,0.0);
        vector<double> ken(N,0.0);
        for (j = 0;j < N;j++) {
            filein >> naomi[j];
        }
        for (j = 0;j < N;j++) {
            filein >> ken[j];
        }
        sort (naomi.begin(), naomi.end());
        sort (ken.begin(), ken.end());
        dec = 0;
        Q = N-1;
        double R;
        for (j = N-1;j >= 0;j--) {
            R = naomi[j];
            while (Q >= 0 && ken[Q] > R) Q--;
            if (Q >= 0) {
                dec++;
                Q--;
            }
        }
        war = N;
        Q = N-1;
        for (j = N-1;j >= 0;j--) {
            R = ken[j];
            while (Q >= 0 && naomi[Q] > R) Q--;
            if (Q >= 0) {
                war--;
                Q--;
            }
        }
        fileout << "Case #" << i+1 << ": " << dec << " " << war << endl;
    }
    fileout.close();
}