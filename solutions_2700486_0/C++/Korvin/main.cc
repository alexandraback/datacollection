#include <vector> // headers {{{
#include <list>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <functional>
#include <numeric>
#include <cstdlib>
#include <cmath>
#include <cstdio>
#include <fstream>
#include <ctime>

#define DEBUG(x) cout << #x << ": " << x << "\n"
using namespace std; // }}}

typedef vector<vector<int> > POS;
const int D = 50;

int get(const POS& P, int X, int Y)
{
    X+= D;
    if (X < 0 || X >= 2 * D || Y < 0 || Y >= 2 * D)
        return 0;
    return P[Y][X];
}

pair<int, int> add(POS& P, bool left)
{
    int Y = D, X = D;
    while (Y && !P[Y][X]) {
        Y-= 2;
    }
    if (!P[Y][X]) {
        P[Y][X] = 1;
        return make_pair(Y, X);
    }
    int lY = Y + 1, rY = Y + 1, lX = X - 1, rX = X + 1;
    bool hasleft = P[lY][lX];
    bool hasright = P[rY][rX];
    if (!hasleft && (left || hasright)) {
        do {
            Y = lY, X = lX;
            lY--, lX--;
        } while (Y && !P[lY][lX]);
        P[Y][X] = 1;
        return make_pair(Y, X);
    }
    if (!hasright && (!left || hasleft)) {
        do {
            Y = rY, X = rX;
            rY--, rX++;
        } while (Y && !P[rY][rX]);
        P[Y][X] = 1;
        return make_pair(Y, X);
    }
    Y+= 2;
    P[Y][X] = 1;
    return make_pair(Y, X);
}

int doit(int N, int X, int Y, int cur, POS& P)
{
    if (cur == N)
        return get(P, X, Y);
    pair<int, int> p = add(P, 0);
    int res = doit(N, X, Y, cur + 1, P);
    P[p.first][p.second] = 0;
    p = add(P, 1);
    res+= doit(N, X, Y, cur + 1, P);
    P[p.first][p.second] = 0;
    return res;
}

double result(int N, int X, int Y)
{
    POS P(2 * D, vector<int>(2 * D));
    int out = doit(N, X, Y, 0, P);
    return out * 1. / (1 << N);
}

int main()
{
    time_t start, end;
    time(&start);
    
    ifstream cin("test.in");
    ofstream cout("test.out");
    cout.precision(6);
    cout.setf(ios::fixed,ios::floatfield);

    int T;
    cin >> T;
    for (int i = 1; i <= T; ++i) {
        int N, X, Y;
        cin >> N >> X >> Y;
        cout << "Case #" << i << ": " << result(N, X, Y) << endl;
        time(&end);
        ::cout << i << " " << difftime(end, start) << endl;
    }

    return 0;
}
