#pragma comment(linker, "/STACK:33554432")

#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <string>
#include <sstream>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <ctime>
#include <memory.h>

using namespace std;

#define REP(i,n) for(int i=0;i<n;++i)
#define ABS(n) ((n)<0 ? -(n) : (n))
#define SQR(a) (a)*(a)
#define MIN(a,b) (a<b?a:b)
#define MAX(a,b) (a>b?a:b)
#define MP make_pair
#define PB push_back
#define FILL(a) memset(a,0,sizeof(a));
#define COPY(a,b) memcpy(a,b,sizeof (b));
#define SI(a) (int)((a).size())
#define ALL(a) (a).begin(),(a).end()
#define y1 yyyyy1
#define prev prevvvvv
#define LL long long
const double PI = 2*acos(0.0);
const double EPS = 1e-8;
const int INF = (1<<30)-1;

vector<string> getBoard() {
    vector<string> res;
    REP(i,4) {
        string r;
        cin >> r;
        res.push_back(r);
    }
    return res;
}

bool won (vector<string> b, char p) {
    REP(i,b.size()) REP(j,b[i].size()) if (b[i][j] == 'T') b[i][j] = p;
    string row = "";
    REP(i,4) row += p;
    REP(i,4) {
        if (b[i] == row) 
            return true;
    }
    REP(j,4){
        string c = "";
        REP(i,4) c += b[i][j];
        if (c == row) return true;
    }
    string c = "";
    REP(i,4) c += b[i][i];
    if (c == row) return true;
    c = "";
    REP(i,4) c += b[i][3-i];
    if (c == row) return true;
    return false;
}

bool draw (vector<string> b) {
    REP(i,b.size()) REP(j,b[i].size()) if (b[i][j]=='.') return false;
    return true;
}

int main(){
	freopen ("input.txt", "r", stdin);
	freopen ("output.txt", "w", stdout);
    int tc;
    cin >> tc;
    REP(ic,tc){
        vector<string> s = getBoard();
        cout << "Case #" << ic+1 << ": ";
        if (won (s, 'X')) cout << "X won" << endl;
        else if (won (s, 'O')) cout << "O won" << endl;
        else if (draw (s)) cout << "Draw" << endl;
        else cout << "Game has not completed" << endl;
    }
	return 0;
};