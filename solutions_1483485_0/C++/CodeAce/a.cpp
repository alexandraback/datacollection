#include <iostream>
#include <string>
#include <fstream>

using namespace std;

char map[26] = { 'y', 'h', 'e', 's', 'o', 'c', 'v', 'x',
                        'd', 'u', 'i', 'g', 'l', 'b', 'k', 'r', 'z', 't', 'n', 'w', 'j', 'p',
                        'f', 'm', 'a', 'q' };
int t;

int main() {

    ifstream fin("a0.in");
    ofstream fout("a.out");

    string s;

    fin >> t;

    char ch;
    getline(fin, s);

    for (int tc=0; tc<t; tc++) {
        getline(fin, s);

        string t = "";
        for (int i=0; i<s.length(); i++) {
            ch = s.c_str()[i];
            if (ch != ' ')
                t += map[(int)(ch - 'a')];
            else
                t += ' ';
        }

        fout << "Case #" << tc+1 << ": " << t << endl;
    }

    fin.close();
    fout.close();

    return 0;
}
