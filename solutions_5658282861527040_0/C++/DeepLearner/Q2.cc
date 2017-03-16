
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdio>

using namespace std;


int main(int argc, char *argv[]) {
    if (argc != 2) {
        cerr << "Need input file!" << endl;
        return 1;
    }
    ifstream input(argv[1]); // bind and open the input file
    // check whether open sucessfully
    if (!input) {
        cerr << "unable to open the input file!" << endl;
        return 1;
    }
    
    int T; // number of cases
    input >> T;
    input.ignore(256, '\n'); // ignore the rest of the line
    
    // consider each case
    for (int i = 1; i <= T; i++) {
        string line;
        getline(input, line);
        stringstream ss(line);
        long long A, B, K;
        ss >> A >> B >> K;
        long long a = max(A, B);
        long long b = min(A, B);
        long long k = min(K, b);
        long long num = a*b - (a-k)*(b-k);
        for (long long ai = k; ai < a; ai++) {
            for (long long bj = k; bj < b; bj++) {
                if ((ai&bj) < k) num++;
            }
        }
        printf("Case #%ld: %ld\n", i, num);
    }
    
    input.close(); // close file before return
    
    return 0;
}