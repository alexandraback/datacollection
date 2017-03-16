# include <iostream>
# include <string>
# include <cstdio>
# define rep(x, n) for (int x = 0; x < n; ++x )
using namespace std;

int t;

string s[5], ans;

int main()
{
    freopen("in.in","r",stdin);
    freopen("out.txt","w",stdout);
    cin >> t;
    int tt = 0;
    while ( t-- )
    {
        rep(i, 4)
            cin >> s[i];
        int state = 0;
        rep(i, 4)
        {
            int cx = 0, co = 0;
            rep(j, 4)
                if ( s[i][j] == 'T' )
                    ++co, ++cx;
                else if ( s[i][j] == 'O' )
                    ++co;
                else if ( s[i][j] == 'X' )
                    ++cx;
            //cout << " cx = " << cx <<"  co = " <<co <<endl;
            if ( cx == 4 )
            {
                state = 1; //x win
                break;
            }
            if ( co == 4 )
            {
                state = 2; //o win
                break;
            }
            cx = co = 0;
            rep(j, 4)
                if ( s[j][i] == 'T' )
                    ++co, ++cx;
                else if ( s[j][i] == 'O' )
                    ++co;
                else if ( s[j][i] == 'X' )
                    ++cx;
            //cout << " r cx = " << cx <<"  co = " <<co <<endl;
            if ( cx == 4 )
            {
                state = 1; //x win
                break;
            }
            if ( co == 4 )
            {
                state = 2; //o win
                break;
            }
        }
        int co = 0, cx = 0;
        rep(j, 4)
            if ( s[j][j] == 'T' )
                ++co, ++cx;
            else if ( s[j][j] == 'O' )
                ++co;
            else if ( s[j][j] == 'X' )
                ++cx;
        if ( cx == 4 )
            state = 1; //x win
        else if ( co == 4 )
            state = 2; //o win

        cx = co = 0;

        rep(i, 4)
        {
            int j = 4-i-1;
            if ( s[i][j] == 'T' )
                ++co, ++cx;
            else if ( s[i][j] == 'O' )
                ++co;
            else if ( s[i][j] == 'X' )
                ++cx;
        }
        if ( cx == 4 )
            state = 1; //x win
        else if ( co == 4 )
            state = 2; //o win


        if ( state == 0 )
        {
            rep(i, 4)
                rep(j, 4)
                    if ( s[i][j] == '.' )
                        state = 3; //not comp.
        }
        switch(state)
        {
            case 0: ans = "Draw"; break;
            case 1: ans = "X won"; break;
            case 2: ans = "O won"; break;
            case 3: ans = "Game has not completed"; break;
        }
        cout << "Case #" << ++tt << ": " << ans << endl;
    }
    return  0;
}
