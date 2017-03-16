#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream fin("D-small-attempt0.in");
    ofstream fout("output.txt");
    int T;
    int k, c, s;
    fin >> T;
    for(int i = 0; i < T; i++) {
        fin >> k >> c >> s;
        fout << "Case #" << i+1 << ": ";
        for(int j = 1; j <= k; j++){
            fout << j << " ";
        }
        fout <<"\n";
    }
    return 0;
}
