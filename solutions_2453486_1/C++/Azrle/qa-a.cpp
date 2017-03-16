#include<fstream>
#include<string>
#include<iomanip>
using namespace std;

ifstream fin("A-large.in");
ofstream fout("A-large.out");

int main() {
    int T,c;
    fin>>T;

    string tmp;
    for (c=1; c<=T; ++c) {
        char m[4][4];
        int i,j, x, t, o;

        bool draw = true;

        char won = 'N';

        for (i=0; i<4; ++i) {
            tmp = "";
            do {
                fin>>tmp;
            } while (tmp == "");
            for (j=0;j<4;++j) {
                m[i][j] = tmp[j];
                if (m[i][j] == '.')
                    draw = false;
            }
        }

        // scan rows
        for (i=0; i<4; ++i) {
            x = t = o = 0;
            for (j=0; j<4; ++j) {
                if (m[i][j] == 'X') ++x;
                if (m[i][j] == 'O') ++o;
                if (m[i][j] == 'T') ++t;
            }
            if (x+t == 4 || o+t == 4) {
                // won
                won = x>o?'X':'O';
                break;
            }
        }

        // scan columns
        for (j=0; j<4; ++j) {
            x = t = o = 0;
            if (won != 'N') break;
            for (i=0; i<4; ++i) {
                if (m[i][j] == 'X') ++x;
                if (m[i][j] == 'O') ++o;
                if (m[i][j] == 'T') ++t;
            }
            if (x+t == 4 || o+t == 4) {
                // won
                won = x>o?'X':'O';
                break;
            }
        }

        // scan diag
        x = t = o = 0;
        for (i=0; i<4; ++i) {
            if (won != 'N') break;
            if (m[i][i] == 'X') ++x;
            if (m[i][i] == 'O') ++o;
            if (m[i][i] == 'T') ++t;
            if (x+t == 4 || o+t == 4) {
                // won
                won = x>o?'X':'O';
                break;
            }
        }

        // scan diag (reverse)
        x = t = o = 0;
        for (i=0; i<4; ++i) {
            if (won != 'N') break;
            if (m[i][3-i] == 'X') ++x;
            if (m[i][3-i] == 'O') ++o;
            if (m[i][3-i] == 'T') ++t;
            if (x+t == 4 || o+t == 4) {
                // won
                won = x>o?'X':'O';
                break;
            }
        }

        // output
        fout<<"Case #"<<c<<": ";

        if (won == 'N') {
            if (!draw)
                fout<<"Game has not completed";
            else
                fout<<"Draw";
        } else {
            fout<<won<<" won";
        }
        
        fout<<endl;
    }
    return 0;
}
