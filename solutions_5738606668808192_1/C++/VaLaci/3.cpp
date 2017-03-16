#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main () {
    ofstream out ("3.out");
    out << "Case #1: "<<endl;
    int c = 0;
    int n = 32;
    for (int i = 1; i <= n-3; i++) {
        for (int j = 1; j <= n-2 - i; j+=2) {
            c++;
            // out << c << ": ";
            for (int k = 0; k <= n-1; k++) {
                if (k == 0 || k == n-1)
                    out << 1;
                else if (k == i || k == i + j)
                    out << 1;
                else out << 0;
            }
            out << " 3 4 5 6 7 8 9 10 11" << endl;
        }
    }
    for (int i = 1; i <= n-5; i++) {
        for (int j = 1; j <= n-4 - i; j+=2) {
            c++;
            // out << c << ": ";
            for (int k = 0; k <= n-1; k++) {
                if (k == 0 || k==n-3 || k == n-2 || k == n-1)
                    out << 1;
                else if (k == i || k == i + j)
                    out << 1;
                else out << 0;
            }
            out << " 3 4 5 6 7 8 9 10 11" << endl;
        }
    }
    for (int i = 1; i <= n-7; i++) {
        for (int j = 1; j <= n-6 - i; j+=2) {
            c++;
            // out << c << ": ";
            for (int k = 0; k <= n-1; k++) {
                if (k == 0 || k==n-5 || k==n-4 || k==n-3 || k == n-2 || k == n-1)
                    out << 1;
                else if (k == i || k == i + j)
                    out << 1;
                else out << 0;
            }
            out << " 3 4 5 6 7 8 9 10 11" << endl;
        }
    }
}

