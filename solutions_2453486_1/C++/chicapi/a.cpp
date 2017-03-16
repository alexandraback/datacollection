#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>

using namespace std;

#define ST first
#define ND second
#define MP make_pair
#define PB push_back

typedef long long LL;
typedef long double LD;
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef double D;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<string> vs;
typedef vector<vi> vvi;

typedef vector<int> VI;
typedef pair<int,int> PII;
#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(VAR(i,a);i<=(b);++i)
#define FORD(i,a,b) for(VAR(i,a);i>=(b);--i)
#define FORE(a,b) for(VAR(a,(b).begin());a!=(b).end();++a)
#define VAR(a,b) __typeof(b) a=(b)
#define SIZE(a) ((int)((a).size()))
#define ALL(x) (x).begin(),(x).end()
#define CLR(x,a) memset(x,a,sizeof(x))
#define ZERO(x) memset(x,0,sizeof(x))
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define ABS(a,b) ((a)>(b)?(a-b):(b-a))

#define fabsl __builtin_fabsl
#define atan2l __builtin_atan2l
#define cosl __builtin_cosl
#define sinl __builtin_sinl
#define sqrtl __builtin_sqrtl

template<class T>
void splitstr(const string &s, vector<T> &out)
{
    istringstream in(s);
    out.clear();
    copy(istream_iterator<T>(in), istream_iterator<T>(), back_inserter(out));
}



int main ()
{

    int T;
    char line[300];
    fgets(line, 256, stdin);
    sscanf(line, "%d", &T);
    for (int t = 0; t < T; t++) {
        int n;
        n = 4;
        string sol = "";
        char board[10][10];
        bool empty = false;
        for (int i = 0; i < n; i++) {
            fgets(line, 256, stdin);
            sscanf(line, "%s", board[i]);
//            printf("%s\n", board[i]);
            if (strchr(board[i], '.') != NULL) {
                empty = true;
            }
        }
        fgets(line, 256, stdin);

        // X
        int cx, co, ct;
        // row
        for (int i = 0; i < n; i++) {
            cx = 0;
            co = 0;
            ct = 0;
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'X')
                    cx++;
                else if (board[i][j] == 'O')
                    co++;
                else if (board[i][j] == 'T')
                    ct++;
            }
            if (cx == 4 || (cx == 3 && ct)) {
                sol = "X won";
//                printf("row x\n");
                goto end;
            }
            else if (co == 4 || (co == 3 && ct)) {
                sol = "O won";
                goto end;
            }
        }
        // col
        for (int i = 0; i < n; i++) {
            cx = 0;
            co = 0;
            ct = 0;
            for (int j = 0; j < n; j++) {
                if (board[j][i] == 'X')
                    cx++;
                else if (board[j][i] == 'O')
                    co++;
                else if (board[j][i] == 'T')
                    ct++;
            }
            if (cx == 4 || (cx == 3 && ct)) {
                sol = "X won";
                goto end;
            }
            else if (co == 4 || (co == 3 && ct)) {
                sol = "O won";
                goto end;
            }
        }

        // diag 1
        cx = 0;
        co = 0;
        ct = 0;
        for (int i = 0; i < n; i++) {
            if (board[i][i] == 'X')
                cx++;
            else if (board[i][i] == 'O')
                co++;
            else if (board[i][i] == 'T')
                ct++;
        }
        if (cx == 4 || (cx == 3 && ct)) {
            sol = "X won";
            goto end;
        }
        else if (co == 4 || (co == 3 && ct)) {
            sol = "O won";
            goto end;
        }
        // diag 2
        cx = 0;
        co = 0;
        ct = 0;
        for (int i = 0; i < n; i++) {
            if (board[n-i-1][i] == 'X')
                cx++;
            else if (board[n-i-1][i] == 'O')
                co++;
            else if (board[n-i-1][i] == 'T')
                ct++;
        }
        if (cx == 4 || (cx == 3 && ct)) {
            sol = "X won";
            goto end;
        }
        else if (co == 4 || (co == 3 && ct)) {
            sol = "O won";
            goto end;
        }

        // draw
        if (empty)
            sol = "Game has not completed";
        else
            sol = "Draw";

end:
        cout << "Case #" << t+1 << ": " << sol << endl;
    }
    return 0;
}




