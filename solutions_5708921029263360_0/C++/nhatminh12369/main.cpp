#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <math.h>
#include <stdlib.h>

using namespace std;

bool checkValid(int JP[10][10], int JS[10][10], int PS[10][10], int J, int P, int S, int K) {
    for (int i=0;i<10;i++) {
        for (int j=0;j<10;j++) {
            if (JP[i][j] > K || JS[i][j] > K || PS[i][j] > K) {
                return false;
            }
        }
    }
    return true;
}

void reset(int JP[10][10], int JS[10][10], int PS[10][10]) {
    for (int i=0;i<10;i++) {
        for (int j=0;j<10;j++) {
            JP[i][j] = 0;
            JS[i][j] = 0;
            PS[i][j] = 0;
        }
    }
}

int main() {
    ifstream fin ("/Users/LeonardNguyen/Documents/projects/ios/usaco/C-small-attempt0.in");
    ofstream fout ("/Users/LeonardNguyen/Documents/projects/ios/usaco/C-small.out");
    
    int T;
    fin >> T;
    
    for (int iCase = 0;iCase<T;iCase++) {
        int J, P, S, K;
        fin >> J >> P >> S >> K;
        int JP[10][10];
        int JS[10][10];
        int PS[10][10];
        
        reset(JP, JS, PS);
        
        string solutions = "";
        int countSolutions = 0;
        for (int i=0;i<J;i++) {
            for (int j=0;j<P;j++) {
                for (int k=0;k<S;k++) {
                    JP[i][j]++;
                    JS[i][k]++;
                    PS[j][k]++;
                    bool valid = checkValid(JP, JS, PS, J, P, S, K);
                    if (valid) {
                        countSolutions++;
                        solutions += (char)('0' + i + 1);// + " " + (char)('0' + j + 1) + " " + (char)('0' + k + 1);
                        solutions += " ";
                        solutions += (char)('0' + j + 1);
                        solutions += " ";
                        solutions += (char)('0' + k + 1);
                        solutions += '\n';
                        continue;
                    } else {
                        JP[i][j]--;
                        JS[i][k]--;
                        PS[j][k]--;
                    }
                }
            }
        }
        fout<<"Case #"<<(iCase + 1)<<": " << countSolutions<<endl;
        fout<<solutions;
    }
    
    fin.close();
    fout.close();
    return 0;
}

