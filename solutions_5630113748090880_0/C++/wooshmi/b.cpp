#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

const int kMaxN = 2505;

int freq[kMaxN];

int main() {
    ifstream in;
    in.open("dataset.in");
    ofstream out;
    out.open("dataset.out");

    int T;
    in >> T;

    for (int i = 0; i < T; ++i) {
        int n;
        in >> n;
        for (int j = 0; j < kMaxN; ++j)
            freq[j] = 0;
        for (int j = 0; j < 2 * n - 1; ++j) 
            for (int k = 0; k < n; ++k) {
                int x;
                in >> x;
                freq[x] += 1;
            }
        out << "Case #" << (i + 1) << ":";
        for (int j = 0; j < kMaxN; ++j)
            if (freq[j] % 2 == 1)
                out << " " << j;
        out << "\n";
    }
    
    in.close();
    out.close();
    return 0;
}
