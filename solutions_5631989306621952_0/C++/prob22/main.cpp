#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <math.h>
#include <vector>
using namespace std;

int main() {
    ifstream fin("A-small.in");
    ofstream fout("A-small.txt");
    int T;
    fin >> T;
    for (int i = 1; i <= T; i++) {
        string word;
        fin >> word;
        string final = "";
        final += word[0];
        for(int i = 1; i < word.length(); i++) {
            if(word[i]-'A'>=final[0]-'A')
                final = word[i] + final;
            else
                final += word[i];
        }
        fout << "Case #" << i << ": " << final << endl;
    }
    return 0;
}
