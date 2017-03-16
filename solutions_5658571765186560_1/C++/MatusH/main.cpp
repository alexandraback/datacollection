#include <iostream>
#include <fstream>
#include <stdlib.h>

using namespace std;

int main()
{
    ifstream in ("D-large.in");
    ofstream out ("output.out");
    string winner;
    int T, X, R, C;

    if(in.is_open()){
        in >> T;
        for (int i = 1; i <= T; i++){
            in >> X >> R >> C;
            winner = "GABRIEL";
            if (X >= 7)
                winner = "RICHARD";
            if ((R*C) % X)
                winner = "RICHARD";
            if (((X+1)/2 > R) || ((X+1)/2 > C))
                winner = "RICHARD";
            if ((X == 4) && ((R == 2) || (C == 2)))
                winner = "RICHARD";
            if ((X == 5) && (((R == 3) && (C == 5)) || ((R == 5) && (C == 3))))
                winner = "RICHARD";
            if ((X == 6) && ((R == 3) || (C == 3)))
                winner = "RICHARD";

            out << "Case #" << i << ": " << winner << endl;
        }
        in.close();
    }
    out.close();
    return 0;
}
