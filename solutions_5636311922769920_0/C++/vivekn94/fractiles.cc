#include <iostream>
#include <fstream>
#include <math.h>
int main() {
    std::ifstream infile;
    std::ofstream outfile;
    infile.open("in4s.txt");
    outfile.open("out4s.txt");
    int T, K, C, S, start;
    infile >> T;
    for(int i = 0; i < T; i++) {
        infile >> K >> C >> S;
        if(S < K &&  C == 1) {
            outfile << "Case #" << i+1 << ": IMPOSSIBLE\n";
        }
        else if(S < K && C > 1) {
            outfile << "Case #" << i+1 << ": IMPOSSIBLE\n";
        }
        else if (K == C && K == 1) {
            outfile << "Case #" << i+1 << ": 1\n";
        }
        else {
            outfile << "Case #" << i+1 << ":";
            for(int j = 1; j < S+1; j++) {
                outfile << " " << j;
            }
            outfile << "\n";
        }
    }
    return 0;
}
