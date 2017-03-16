#include "sstream"
#include "iostream"
#include "cstdio"
#include "cstring"
#include "cmath"
#include "algorithm"
#include "vector"
#include "map"
#include "set"
#include "queue"
#include "deque"
#include "list"
#include "string"
#include "cassert"

using namespace std;

void check(string line, int &x, int &o, int &draw)
{
    int num_x = count(line.begin(), line.end(), 'X');
    int num_o = count(line.begin(), line.end(), 'O');
    int num_t = count(line.begin(), line.end(), 'T');
    int num_d = count(line.begin(), line.end(), '.');
    if (num_x == 4 || num_x == 3 && num_t == 1) {
        x = 1;
    }
    if (num_o == 4 || num_o == 3 && num_t == 1) {
        o = 1;
    }
    draw += num_d;
}

int main()
{
    freopen("in.txt", "r", stdin);
    int T, t = 1;
    for (cin>>T; T--; ) {
        cout<<"Case #"<<t++<<": ";
        string board[4];
        for (int i = 0; i < 4; i++) {
            cin>>board[i];
        }
        int x = 0, o = 0, draw = 0;
        string line;
        //rows
        for (int i = 0; i < 4; i++) {
            line = board[i];
            check(line, x, o, draw);
        }
        //columns
        for (int i = 0; i < 4; i++) {
            line = "";
            for (int r = 0; r < 4; r++) {
                line += string(1, board[r][i]);
            }
            check(line, x, o, draw);
        }
        //
        line = "";
        for (int i = 0; i < 4; i++) {
            line += string(1, board[i][i]);
        }
        check(line, x, o, draw);
        line = "";
        for (int i = 0; i < 4; i++) {
            line += string(1, board[i][3-i]);
        }
        check(line, x, o, draw);

        if (x && !o) {
            cout<<"X won"<<endl;
        } else if (!x && o) {
            cout<<"O won"<<endl;
        } else if (draw == 0) {
            cout<<"Draw"<<endl;
        } else {
            cout<<"Game has not completed"<<endl;
        }
    }
    return 0;
}

