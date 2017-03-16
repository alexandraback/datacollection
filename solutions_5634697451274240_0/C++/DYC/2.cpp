#include <fstream>
#include <iostream>

using namespace std;

int main(){
    ifstream fin("in2");
    ofstream fout("out2");
    int T;
    fin >> T;
    for (int i = 0; i < T; i++){
        string s;
        fin >> s;
        int flip = 0;
        for (int j = 0; j < s.length() - 1; j++){
            if (s[j] != s[j + 1])
                flip++;
        }
        if (s[s.length() - 1] == '+')
            fout << "Case #" << (i + 1) << ": " << flip << endl;
        else
            fout << "Case #" << (i + 1) << ": " << flip + 1 << endl;
    }

    fin.close();
    fout.close();
    return 0;
}
