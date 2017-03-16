#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main () {
    ifstream in ("4.in");
    ofstream out ("4.out");
    int testcases;
    in >> testcases;
    for (int t = 1; t <= testcases; ++t) {
        out << "Case #" << t <<": ";
        int k,c,s;
        in >> k >> c >> s;
        if (c*s < k) {
            out << "IMPOSSIBLE";
        } else {
            for (int i = 0; i < (k-1)/c + 1; i++) {
                long long int q = 0;
                for (int j = i*c ; j < (i+1)*c && j < k; ++j) {
                    q *= k;
                    q += j;
                }
                out << q+1 << " ";
            }
        }
        out <<endl;
    }
}

