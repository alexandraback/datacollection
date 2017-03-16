#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(void) {
    char dict[26];
    dict[0] = 'y';
    dict[1] = 'h';
    dict[2] = 'e';
    dict[3] = 's';
    dict[4] = 'o';
    dict[5] = 'c';
    dict[6] = 'v';
    dict[7] = 'x';
    dict[8] = 'd';
    dict[9] = 'u';
    dict[10] = 'i';
    dict[11] = 'g';
    dict[12] = 'l';
    dict[13] = 'b';
    dict[14] = 'k';
    dict[15] = 'r';
    dict[16] = 'z';
    dict[17] = 't';
    dict[18] = 'n';
    dict[19] = 'w';
    dict[20] = 'j';
    dict[21] = 'p';
    dict[22] = 'f';
    dict[23] = 'm';
    dict[24] = 'a';
    dict[25] = 'q';

    ifstream fin;
    fin.open("A-small-attempt1.in");
    ofstream fout;
    fout.open("A-small-attempt1.out");

    int ncase;
    string in;
    fin >> ncase;
    getline(fin, in);
    for (int ni = 1; ni <= ncase; ++ni) {
        getline(fin, in);
        string out = "";
        for (int i = 0; i < in.size(); ++i)
            if (in[i] == ' ')
                out += ' ';
            else
                out += dict[in[i] - 'a'];
        fout << "Case #" << ni << ": " << out << endl;
    }
    fin.close();
    fout.close();

    return 0;
}
