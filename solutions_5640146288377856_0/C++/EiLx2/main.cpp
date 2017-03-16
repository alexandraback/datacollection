#include <iostream>
#include <fstream>
using namespace std;

int T,R,C,W;


int main(){
    int T;
    ifstream fin("input.in");
    ofstream fout("output.txt");
    fin >> T;

    int i,k;
    for (k=1; k<=T; k++){
        fin >> R >> C >> W;
        fout << "Case #" << k <<": ";
        if (C%W!=0) fout << R*(C/W)+W << "\n";
        else fout << R*(C/W)+W-1 << "\n";
    }
    return 0;
}
