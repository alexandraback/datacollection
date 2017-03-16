#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef pair<int, int> PI;
typedef long long LL;
#define FOR(x, b, e) for(int x = b; x <= (e); ++x)
#define FORD(x, b, e) for(int x = b; x >= (e); --x)
#define REP(x, n) for(int x = 0; x < (n); ++x)
#define VAR(v, n) __typeof(n) v = (n)
#define FOREACH(i, c) for(VAR(i, (c).begin()); i != (c).end(); ++i)
#define ALL(c) (c).begin(), (c).end()
#define SIZE(x) ((int)(x).size())
#define PB push_back
#define MP make_pair
#define ST first
#define ND second
const int INF = 1000000001;
const double EPS = 10e-9;

int main()
{
    int t, p, b, tx, ty;
    string text;
    VVI board(4, VI(4));
    cin >> t;
    cin.ignore();
    FOR(cs, 1, t)
    {
        b = p = 0;
        tx = ty = -1;
        REP(x, 4)
        {
            getline(cin, text);
            REP(y, 4) if(text[y] == 'X') board[x][y] = 1;
            else if(text[y] == 'O') board[x][y] = 2;
            else if(text[y] == 'T')
            {
                board[x][y] = 3;
                tx = x;
                ty = y;
            }
            else
            {
                board[x][y] = 0;
                b++;
            }
        }
        /*REP(x, 4)
        {
            REP(y, 4) cout << board[x][y] << " ";
            cout << endl;
        }
        cout << endl;*/
        if(tx != -1) board[tx][ty] = 1;
        REP(x, 4) if(board[x][0] != 0 && board[x][0] == board[x][1] && board[x][0] == board[x][2] && board[x][0] == board[x][3]) p = board[x][0];
        REP(x, 4) if(board[0][x] != 0 && board[0][x] == board[1][x] && board[0][x] == board[2][x] && board[0][x] == board[3][x]) p = board[0][x];
        if(board[0][0] != 0 && board[0][0] == board[1][1] && board[0][0] == board[2][2] && board[0][0] == board[3][3]) p = board[0][0];
        if(board[0][3] != 0 && board[0][3] == board[1][2] && board[0][3] == board[2][1] && board[0][3] == board[3][0]) p = board[0][3];
        if(p == 0 && tx != -1)
        {
            board[tx][ty] = 2;
            REP(x, 4) if(board[x][0] != 0 && board[x][0] == board[x][1] && board[x][0] == board[x][2] && board[x][0] == board[x][3]) p = board[x][0];
            REP(x, 4) if(board[0][x] != 0 && board[0][x] == board[1][x] && board[0][x] == board[2][x] && board[0][x] == board[3][x]) p = board[0][x];
            if(board[0][0] != 0 && board[0][0] == board[1][1] && board[0][0] == board[2][2] && board[0][0] == board[3][3]) p = board[0][0];
            if(board[0][3] != 0 && board[0][3] == board[1][2] && board[0][3] == board[2][1] && board[0][3] == board[3][0]) p = board[0][3];
        }
        if(p == 0 && b != 0) p = 3;
        getline(cin, text);
        cout << "Case #" << cs << ": ";
        switch(p)
        {
            case 0:
                cout << "Draw\n";
                break;
            case 1:
                cout << "X won\n";
                break;
            case 2:
                cout << "O won\n";
                break;
            case 3:
                cout << "Game has not completed\n";
                break;
        };
    }
    return 0;
}
