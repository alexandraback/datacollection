#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Board {
    public: char b[4][4];

    enum TestRet { O, X, Neither };

    TestRet test(int i1, int j1, int i2, int j2, int i3, int j3, int i4, int j4) {
        int nX = 0, nO = 0, nT = 0;
        #define DO(i1,j1) switch(b[i1][j1]) { case 'X': nX++; break; case 'O': nO++; break; case 'T': nT++; break; }
        DO(i1,j1)
        DO(i2,j2)
        DO(i3,j3)
        DO(i4,j4)
        if(nX == 4 || (nX == 3 && nT == 1)) return X;
        if(nO == 4 || (nO == 3 && nT == 1)) return O;
        return Neither;
    }

    string state() {
        for(int row = 0; row < 4; row++) {
            TestRet t = test(row, 0, row, 1, row, 2, row, 3);
            if(t == O) return "O won";
            if(t == X) return "X won";
        }
        for(int col = 0; col < 4; col++) {
            TestRet t = test(0, col, 1, col, 2, col, 3, col);
            if(t == O) return "O won";
            if(t == X) return "X won";
        }
        TestRet t = test(0, 0, 1, 1, 2, 2, 3, 3);
        if(t == O) return "O won";
        if(t == X) return "X won";
        t = test(0, 3, 1, 2, 2, 1, 3, 0);
        if(t == O) return "O won";
        if(t == X) return "X won";

        for(int row = 0; row < 4; row++) for(int col = 0; col < 4; col++)
            if(b[row][col] == '.') return "Game has not completed";

        return "Draw";
    }
};

int main() {
    string fn = "in.txt";
    ifstream in(fn.c_str());
    ofstream out("out.txt");

    int n;

    in >> n;

    for(int i = 0; i < n; i++) {
        Board b;
        for(int j = 0; j < 4; j++) for(int k = 0; k < 4; k++)
            in >> b.b[j][k];

        //char c;
        //in >> c;

        out << "Case #" << (i+1) << ": " << b.state() << endl;
    }

    return 0;
}
