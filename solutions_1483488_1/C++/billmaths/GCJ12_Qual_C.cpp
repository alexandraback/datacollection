#include <iostream>
#include <cstdio>
#include <fstream>
#include <sstream>
#include <string>
#include <set>
#include <algorithm>

using namespace std;

int main() {
    ifstream fin("C-large.in");
    ofstream fout("C-large.out");
    int ncase;
    fin >> ncase;
    for (int ni = 1; ni <= ncase; ++ni) {
        string A, B;
        fin >> A >> B;
        int a, b;
        stringstream ssA(A);
        ssA >> a;
        stringstream ssB(B);
        ssB >> b;
        int res = 0;
        for (int i = a; i < b; ++i) {
            stringstream ssX;
            ssX << i;
            string X = ssX.str();
            string Y = X;
            set<string> used;
            for (int j = 1; j < X.size(); ++j) {
                reverse(Y.begin(), Y.end());
                reverse(Y.begin() + 1, Y.end());
                if (X < Y && Y <= B && used.find(Y) == used.end()) {
                    res++;
                    used.insert(Y);
                }
            }
        }
        fout << "Case #" << ni << ": " << res << endl;
    }
    fin.close();
    fout.close();

    return 0;
}