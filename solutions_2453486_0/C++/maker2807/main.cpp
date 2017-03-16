#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool check (vector <string>& field, char symbol) {
    //rows:
    for (int i=0; i<4; i++) {
        bool ok = true;
        for (int j=0; j<4; j++) {
            if (field[i][j]!=symbol && field[i][j]!='T') {
                ok=false;
                break;
            }
        }
        if (ok) return true;
    }

    //cols
    for (int j=0; j<4; j++) {
        bool ok = true;
        for (int i=0; i<4; i++) {
            if (field[i][j]!=symbol && field[i][j]!='T') {
                ok=false;
                break;
            }
        }
        if (ok) return true;
    }

    //diag
    bool ok = true;
    for (int i=0; i<4; i++) {
        if (field[i][i]!=symbol && field[i][i]!='T') {
            ok=false;
            break;
        }
    }
    if (ok) return true;
    ok = true;
    for (int i=0; i<4; i++) {
        if (field[i][3-i]!=symbol && field[i][3-i]!='T') {
            ok=false;
            break;
        }
    }
    if (ok) return true;
    return false;
}

int main()
{
    int T;
    cin >> T;
    vector <string> field(4,"");

    for (int c=0; c<T; c++) {
        for (int i=0; i<4; i++) cin >> field[i];
        cout << "Case #"<< c+1<<": ";
        if (check(field,'X')) cout << "X won" << endl;
        else if (check(field,'O')) cout << "O won" << endl;
        else {
            bool end = true;
            for (int i=0; i<4; i++) {
                for (int j=0; j<4; j++) {
                    if (field[i][j]=='.') end=false;
                }
            }
            if (end) cout << "Draw" << endl;
            else cout << "Game has not completed" << endl;
        }

    }

    return 0;
}

