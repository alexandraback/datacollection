#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main () {
    ifstream in ("1.in");
    ofstream out ("1.out");
    int testcases;
    in >> testcases;
    for (int t = 1; t <= testcases; ++t) {
        out << "Case #" << t <<": ";
        int n;
        in >> n;

        if (n == 0) {
            out << "INSOMNIA";
            out <<endl;
            continue;
        }

        vector<bool> e (10, false);
        int all = 0;

        int m = 0;
        while (all < 10) {
            m += n;
            int d = m;
            while (d > 0) {
                int dd = d % 10;
                if (!e[dd]) {
                    e[dd] = true;
                    all++;
                    // cout<<dd<<endl;
                }
                d = d / 10;
            }
        }
        out << m;
        out <<endl;
    }
}

