#include <iostream>
#include <fstream>
#include <vector>
#include <stack>
#include <queue>
#include <unordered_map>
#include <string>
#include <cmath>
#include <cstdlib>

using namespace std;

int main() {
    ifstream filein;
    ofstream fileout;
    //filein.open("A.in",ios::in);
    filein.open("B-small-attempt0.in",ios::in);
    //filein.open("B-large.in",ios::in);
    fileout.open("output",ios::out);
    int T;
    filein >> T;
    for (int i = 0;i < T;i++) {
        fileout << "Case #" << i+1 << ": ";
        int A,B,K;
        int n1,n2,n3;
        long long count = 0;
        filein >> A >> B >> K;
        for (n1 = 0;n1 < A;n1++) {
            for (n2 = 0;n2 < B;n2++) {
                n3 = n1&n2;
                if (K > n3) count++;
            }
        }
        fileout << count << endl;
    }
    fileout.close();
}