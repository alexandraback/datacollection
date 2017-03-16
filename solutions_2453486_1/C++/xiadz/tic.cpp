#include <iostream>
#include <string>
using namespace std;

string lines[4];

bool t(char c, int a, int b)
{
    return lines[a][b] == c || lines[a][b] == 'T';
}

bool tdiag(char c)
{
    return t(c, 0, 0) && t(c, 1, 1) && t(c, 2, 2) && t(c, 3, 3);
}

bool tdiag2(char c)
{
    return t(c, 0, 3) && t(c, 1, 2) && t(c, 2, 1) && t(c, 3, 0);
}

bool thor(char c, int row)
{
    return t(c, row, 0) && t(c, row, 1) && t(c, row, 2) && t(c, row, 3);
}

bool tver(char c, int col)
{
    return t(c, 0, col) && t(c, 1, col) && t(c, 2, col) && t(c, 3, col);
}

bool test(char c)
{
    bool won = false;
    won |= tdiag(c);
    won |= tdiag2(c);
    for(int i=0; i<4; ++i){
        won |= thor(c, i);
        won |= tver(c, i);
    }
    return won;
}

bool complete()
{
    for(int i=0; i<4; ++i){
        for(int j=0; j<4; ++j){
            if(lines[i][j] == '.'){
                return false;
            }
        }
    }
    return true;
}


int main()
{
    int N;
    cin >> N;
    string _ignore;
    getline(cin, _ignore);
    for(int i=0; i<N; ++i){
        getline(cin, lines[0]);
        getline(cin, lines[1]);
        getline(cin, lines[2]);
        getline(cin, lines[3]);
        getline(cin, _ignore);
        cout << "Case #" << (i+1) << ": ";
        if(test('X')){
            cout << "X won" << endl;
        }else if(test('O')){
            cout << "O won" << endl;
        }else if(complete()){
            cout << "Draw" << endl;
        }else{
            cout << "Game has not completed" << endl;
        }
    }
}
