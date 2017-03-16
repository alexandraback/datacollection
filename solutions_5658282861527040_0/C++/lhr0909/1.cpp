#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main(void) {
    ifstream fin("B-small-attempt0.in");
    ofstream fout("B-small-attempt0.out");
    int testCase;
    long double fixedRate = 2;
    long double currentTime, minTime, farmTime;
    fin >> testCase;
    cout << testCase << endl;
    for (int testCaseI = 1; testCaseI <= testCase; testCaseI++) {
        long count = 0;
        int A, B, K;
        fin >> A >> B >> K;
        for (int i = 0; i < A; i++) {
            for (int j = 0; j < B; j++) {
                int C = i & j;
                if (C < K) {
                    count++;
                }
            }
        }
        cout << count <<endl;
        fout << "Case #" << testCaseI << ": " << count << endl;
    }
    fout.close();
    return 0;
}

