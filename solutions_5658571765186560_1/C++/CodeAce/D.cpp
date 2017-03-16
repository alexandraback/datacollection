#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <cstring>

using namespace std;

string solution(int x, int r, int c)
{
    int mx = max(r, c);
    int mn = min(r, c);

    if (x > mx || x > 2 * mn) {
        return "RICHARD";
    }

    if (x >= 7 || r * c % x != 0)
        return "RICHARD";

    if (x == 6 && mn == 3)
        return "RICHARD";

    if (x == 4 && mn == 2)
        return "RICHARD";

    return "GABRIEL";
}

int main()
{
    ifstream fin("D-large.in");
    ofstream fout("D-large.out");

    int TC;
    fin >> TC;

    for (int T=1; T<=TC; T++) {
        int X, R, C;
        fin >> X >> R >> C;
        fout << "Case #" << T << ": " << solution(X, R, C) << endl;
    }


    fin.close();
    fout.close();

    return 0;
}
