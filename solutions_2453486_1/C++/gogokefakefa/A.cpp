#include <iostream>

using namespace std;

char a[8][8];

void scan(){
    for ( int i = 0; i < 4; ++i )
        cin >> a[i];
}

int ok ( char t1, char t2, char t3, char t4, char ch ){
    if ( t1 != ch && t1 != 'T' )
        return 0;
    if ( t2 != ch && t2 != 'T' )
        return 0;
    if ( t3 != ch && t3 != 'T' )
        return 0;
    if ( t4 != ch && t4 != 'T' )
        return 0;
    return 1;
}
int wins ( char ch ){
    if ( ok ( a[0][0], a[1][1], a[2][2], a[3][3], ch ) )
        return 1;
    if ( ok ( a[0][3], a[1][2], a[2][1], a[3][0], ch ) )
        return 1;

    for ( int i = 0; i < 4; ++i ){
        if ( ok ( a[i][0], a[i][1], a[i][2], a[i][3], ch ) )
            return 1;
        if ( ok ( a[0][i], a[1][i], a[2][i], a[3][i], ch ) )
            return 1;
    }

    return 0;
}

string solve(){
    if ( wins ( 'X' ) )
        return "X won";
    if ( wins ( 'O' ) )
        return "O won";

    for ( int i = 0; i < 4; ++i )
        for ( int j = 0; j < 4; ++j )
            if ( a[i][j] == '.' )
                return "Game has not completed";

    return "Draw";

}
int main(){
    int T;

    cin >> T;

    for ( int i = 1; i <= T; ++i ){
        scan();
        cout << "Case #" << i << ": " << solve () << endl;
    }
}
