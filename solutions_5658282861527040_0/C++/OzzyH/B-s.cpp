#include <iostream>
#include <fstream>
#include <iomanip>
#include <map>
#include <vector>
#include <string>
#include <stdlib.h>
using namespace std;

int run_once(ifstream &fin) {
    int A, B, K;
    fin >> A >> B >> K;
    int cnt = 0;
    for (int i=0; i<A; i++)
        for (int j=0; j<B; j++)
            for (int k=0; k<K; k++)
                if ((i&j)==k) cnt++;
    return cnt;
}

int main() {
    ifstream fin("B-small-attempt0.in");
    ofstream fout("B-small.out");
    int N;
    fin >> N;
    for (int i=0; i<N; i++) {
        fout << "Case #" << i+1 << ": ";
        fout<< run_once(fin);
        fout << endl;
    }
    return 0;
}
