#include <fstream>
#include <iostream>

using namespace std;

int main(){
    ifstream fin("in4");
    ofstream fout("out4");
    int T, K, C, S;
    fin >> T;
    for (int i = 1; i <= T; i++){
        fin >> K >> C >> S;
        fout << "Case #" << i << ":";
        for (int j = 1; j <= S; j++)
            fout << " " << j;
        fout << endl;
    }

    fin.close();
    fout.close();
    return 0;
}
