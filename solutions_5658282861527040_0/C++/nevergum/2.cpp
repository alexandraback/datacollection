
#include <iostream>
#include <fstream>
#include <vector>
#include <deque>
#include <set>
#include <map>
#include <cmath>
#include <stdint.h>

using namespace std;


int main()
{
    ifstream infile("file.in");
    ofstream outfile("file.out");
    
    int T;
    infile >> T;
    for (int t = 1; t <= T; ++t) {
        uint64_t A, B, K;
        infile >> A >> B >> K;
        
        uint64_t ans = 0;
        
        if (A < K or B < K) {
            ans = A * B;
        }
        else {
            ans = A * K + B * K - K * K;        
            for (uint64_t i = K; i < A; ++i) {
                for (uint64_t j = K; j < B; ++j) {
                    if ((i & j) < K)
                       ans++;
                }
            }
        }
        
        outfile << "Case #" << t << ": " << ans << endl;
    }
}
