#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ifstream in;
    in.open("dataset.in");
    ofstream out;
    out.open("dataset.out");

    int T;
    in >> T;

    for (int i = 0; i < T; ++i) {
        int K, C, S;
        in >> K >> C >> S;
        out << "Case #" << (i + 1) << ": ";
        for (int j = 1; j < K; ++j)
            out << j << " ";
        out << K << "\n";
    }
    
    in.close();
    out.close();
    return 0;
}
