#include <iostream>
#include <fstream>
#include <string>

using namespace std;

#define FOR(i, a, b) for(int i = a; i < b; i++)

int main()
{
    ifstream fin("D-small-attempt2.in");
    ofstream fout("output.txt");
    int T;
    fin >> T;
    FOR(i, 0, T) {
        int X, R, C;
        fin >> X >> R >> C;
        bool richard = false;
        if (((X > R) && (X > C)) || (X - R > R) || (X - C > C)) {richard = true;};
        if ((R*C)%X != 0) {richard = true;};
        string outp = (richard) ? "RICHARD" : "GABRIEL";
        fout << "Case #" << i + 1 << ": " << outp << endl;
    }
    return 0;
}
