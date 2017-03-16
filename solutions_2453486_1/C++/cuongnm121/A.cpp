#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<utility>
#include<set>
#include<queue>
#include<stack>
#include<vector>
#include<string>
#include<map>

#define pb push_back
#define mp make_pair
#define fs first
#define sc second

#define openfile {freopen("test.txt","r",stdin);}
#define closefile {freopen("res.txt","w",stdout);}

using namespace std;

typedef long long ll;
typedef pair<int,int> pint;

template <class T> inline T abs(T x) { if (x < 0) return -x; return x; }

const int n = 4;

int nTest;
char b[n][n];
bool Xwin , Owin;

bool isWinner(char c) {

    bool row;

    for(int i=0; i<n; i++) {
        row = true;

        for(int j=0; j<n; j++) {
            if (b[i][j] != c && b[i][j] != 'T') {
                row = false;
            }
        }

        if (row) return true;
    }

    bool column;
    for(int j=0; j<n; j++) {
        column = true;

        for(int i=0; i<n; i++) {
            if (b[i][j] != c && b[i][j] != 'T') {
                column = false;
            }
        }

        if (column) return true;
    }

    bool dia = true;
    for(int i=0; i<n; i++) {
        if (b[i][i] != c && b[i][i] != 'T') {
                dia = false;
            }
    }

    if (dia) return true;

    dia = true;
    for(int i=0; i<n; i++) {
        if (b[i][3-i] != c && b[i][3-i] != 'T') {
            dia = false;
        }
    }

    if (dia) return true;

    return false;
}

int main() {

    openfile
    closefile

    bool emptyChar = false;

    cin >> nTest;
    for(int test=0; test<nTest; test++) {

        emptyChar = false;

        for(int i=0; i<n; i++)
          for(int j=0; j<n; j++) {
            cin >> b[i][j];
            if (b[i][j] == '.') emptyChar = true;
          }

        Xwin = isWinner('X');
        Owin = isWinner('O');

        cout << "Case #" << test+1 << ": ";

        if (Xwin && !Owin) {
            cout <<  "X won";
        }

        if (!Xwin && Owin) {
            cout << "O won";
        }

        if (!Xwin && !Owin) {
            if (!emptyChar) {
                cout << "Draw";
            } else {
                cout << "Game has not completed";
            }
        }
        if (test < nTest-1) cout << endl;
    }

	return 0;
}
