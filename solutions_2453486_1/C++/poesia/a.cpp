#include <iostream>

using namespace std;

int main() {

    int t;
    cin >> t;
    int tc = 1;

    char m[4][4];

    while(t--) {
       
        bool e = true;
        bool d1 = true, d2 = true;

        for(int i = 0; i < 4; i++)
            for(int j = 0; j < 4; j++) {
                cin >> m[i][j];
             
                if(m[i][j] == '.')
                    e = false;
            }

        bool x = false, o = false;

        for(int i = 0; i < 4; i++) {

            if(m[i][i] == 'O' || m[i][i] == '.')
                d1 = false;
            if(m[i][3-i] == 'O' || m[i][3-i] == '.')
                d2 = false;

            bool r = true, c = true;

            for(int j = 0; j < 4; j++) {
                if(m[i][j] == 'O' || m[i][j] == '.')
                    r = false;
                if(m[j][i] == 'O' || m[j][i] == '.')
                    c = false;
            }

            x = x || r || c;
        }

        x = x || d1 || d2;
        d1 = true;
        d2 = true;

        for(int i = 0; i < 4; i++) {
 
            if(m[i][i] == 'X' || m[i][i] == '.')
                d1 = false;
            if(m[i][3-i] == 'X' || m[i][3-i] == '.')
                d2 = false;

            bool r = true, c = true;

            for(int j = 0; j < 4; j++) {
                if(m[i][j] == 'X' || m[i][j] == '.')
                    r = false;
                if(m[j][i] == 'X' || m[j][i] == '.')
                    c = false;
            }

            o = o || r || c;
        }

        o = o || d1 || d2;

        cout << "Case #" << tc++ << ": ";

        if(x)
            cout << "X won\n";
        else if(o)
            cout << "O won\n";
        else if(e)
            cout << "Draw\n";
        else
            cout << "Game has not completed\n";
    }

    return 0;
}
