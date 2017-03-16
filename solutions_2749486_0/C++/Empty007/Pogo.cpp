#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>

using namespace std;

#define pb push_back
#define mp make_pair

#define ALL(x) (x).begin(),(x).end()
#define CLR(a,b) memset(a,b,sizeof(a))
#define REPN(x,a,b) for (int x=a; x<b;++x)
#define REP(x,b) REPN(x, 0, b)

#define dbg(x) cout << #x << " = " << x << endl;
#define dbg2(x, y) cout << #x << " = " << x << "  " << #y << " = " << y << endl;
#define dbg3(x, y, z) cout << #x << " = " << x << "  " << #y << " = " << y << "  " << #z << " = " << z << endl;
#define dbg4(x, y, z, w) cout << #x << " = " << x << "  " << #y << " = " << y << "  " << #z << " = " << z << "  " << #w << " = " << w <<  endl;

typedef long long ll;

int D[210][210][210];
string R[210][210][210];
vector <string> M;

// N W S E
int my[4] = {1, 0, -1, 0 };
int mx[4] = {0, -1, 0, 1 };
map <int, char> mapa;

void go(int y, int x, int p) {
    int &res = D[y][x][p];
    if (res != -1) return ;
    res = 1;
    REP(i, 4) {
        int ny = y, nx = x;
        ny += p*my[i];
        nx += p*mx[i];
//        if (ny == 4 && nx == 3) dbg(R[y][x][p-1]);
        if (ny < 210 && nx < 210 && ny > 0 && nx > 0 && p < 210 && D[ny][nx][p] == -1) {
            R[ny][nx][p] = R[y][x][p-1] + mapa[i];
            go(ny, nx, p+1);
        }
    }
}

int main() { 
	int T;

    mapa[0] = 'N';
    mapa[1] = 'W';
    mapa[2] = 'S';
    mapa[3] = 'E';

    CLR(D, -1);

    REP(i, 210) REP(j, 210) REP(k, 210) R[i][j][k] = "";
    go(102, 102, 1);

    cin >> T;
    REP(tc, T) {
        int X, Y;
        cin >> X >> Y;
		printf("Case #%d: ", tc+1);
        string res = "";
        REP(i, 210) if (R[Y+102][X+102][i] != "") res = R[Y+102][X+102][i];
        cout << res << "\n";
	}
	
	return 0;
}
