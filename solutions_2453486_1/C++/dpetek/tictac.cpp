#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;

int checkBoard(vector<string> b) {

    for (int i=0;i<4;++i) {
        char rowChar = 'x', colChar = 'x', d1Char = 'x', d2Char = 'x';
        bool rowOk = true, colOk = true, d1Ok = true, d2Ok = true;
        for (int j=0;j<4;++j) {
            if (b[i][j] == '.') { rowOk = false;}
            if (b[j][i] == '.') { colOk = false;}
            if (b[j][j] == '.') { d1Ok = false;}
            if (b[j][3-j] == '.') { d2Ok = false; }

            if (rowChar == 'x' && b[i][j] != '.' && b[i][j] != 'T') rowChar = b[i][j];
            if (colChar == 'x' && b[j][i] != '.' && b[j][i] != 'T') colChar = b[j][i];
            if (d1Char == 'x' && b[j][j] != '.' && b[j][j] != 'T') d1Char = b[j][j];
            if (d2Char == 'x' && b[j][3-j] != '.' && b[j][3-j] != 'T') d2Char = b[j][3-j];

            if (b[i][j] != 'T' && b[i][j] != rowChar ) rowOk = false;
            if (b[j][i] != 'T' && b[j][i] != colChar ) colOk = false;
            if (b[j][j] != 'T' && b[j][j] != d1Char ) d1Ok = false;
            if (b[j][3-j] != 'T' && b[j][3-j] != d2Char ) d2Ok = false;
        }
        if ( rowOk && rowChar != 'T' && rowChar != 'x' )   return rowChar;
        if ( colOk && colChar != 'T' && colChar != 'x') return colChar;
        if ( d1Ok  && d1Char != 'T' && d1Char != 'x' ) return d1Char;
        if ( d2Ok && d2Char != 'T' && d2Char != 'x') return d2Char;
    }
    int dotCnt = 0;
    for (int i=0;i<4;++i)
        for (int j=0;j<4;++j)
            dotCnt += b[i][j] == '.';

    if (dotCnt > 0 ) return 'F';

    return 'D';
}

int main(void)
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t;
    char line[5];
    vector<string> board;
    scanf ("%d", &t);

    for (int _test=1;_test<=t;++_test) {
        board.clear();
        for (int i=0;i<4;++i) {
            scanf("%s", line);
            board.push_back((string)line);
        }
        int check = checkBoard(board);
        switch(check){
            case (int)'X':
                printf ("Case #%d: X won\n", _test);break;
            case (int)'O':
                printf ("Case #%d: O won\n", _test);break;
            case (int)'D':
                printf ("Case #%d: Draw\n", _test);break;
            case (int)'F':
                printf ("Case #%d: Game has not completed\n", _test), _test; break;
        }
    }


    return 0;
}
