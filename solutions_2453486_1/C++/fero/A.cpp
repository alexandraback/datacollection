#include <iostream>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <numeric>

#include <cstdio>
#include <cmath>
#include <cctype>
#include <cstring>

#include <string>
#include <vector>
#include <deque>
#include <list>
#include <set>
#include <map>
#include <queue>
#include <stack>

using namespace std;

#define FOREACH(iter, cont) for(__typeof((cont).begin()) iter = (cont).begin(); iter != (cont).end(); iter++)
#define REP(i, end) for(int i = 0; i < (end); i++)
#define CLEAR(arr) memset(arr, 0, sizeof(arr))
#define ALL(cont) (cont).begin(),(cont).end()

const int n = 4;
int b[n][n];

int main() {
    int cases;
    cin >> cases;
    for (int cs = 1; cs <= cases; cs++) {
        REP(i, n) REP(j, n) {
            char c;
            cin >> ws >> c;
            switch (c) {
                case 'X' : b[i][j] = 1; break;
                case 'O' : b[i][j] = 2; break;
                case 'T' : b[i][j] = 3; break;
                default : b[i][j] = 0; 
            }
        }

        int res = 0;
        int w;

        REP(i, n) {
            w = 3;
            REP(j, n)
                w &= b[i][j];
            if (w)
                res = w;
        }

        REP(i, n) {
            w = 3;
            REP(j, n)
                w &= b[j][i];
            if (w)
                res = w;
        }

        w = 3;
        REP(i, n)
            w &= b[i][i];
        if (w)
            res = w;

        w = 3;
        REP(i, n)
            w &= b[i][n-1-i];
        if (w)
            res = w;

	cout << "Case #" << cs << ": ";
        if (res == 1)
            cout <<  "X won";
        if (res == 2)
            cout << "O won";
        if (res == 0) {
            w = 0;
            REP(i, n) REP(j, n)
                w += (b[i][j] == 0);
            if (w)
                cout << "Game has not completed";
            else
                cout << "Draw";
        }
        cout << endl;
    }
}
