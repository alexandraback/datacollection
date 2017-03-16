#include <iostream>
#include <cstdio>
#include <cmath>
#include <set>
#include <vector>
#include <map>
#include <cstring>
#include <sstream>
#include <algorithm>
#include <string>
#include <queue>
#include <fstream>
#define FOR(i,a,b) for(int i = (a); i <= (b); i++)
#define FR(i,a) for(int i = 0; i < (a); i++)
#define DR(i,a) for(int i = (a)-1; i >=0; i--)
#define DOWN(i,a,b) for(int i = (a); i >= (b); i--)
#define FORD(i,a,b) for(int i = (a), _b = (b); i >= _b; i--)
#define REPD(i,n) for(int i = (n) - 1; i >= 0; i--)
#define sqr(x) ((x)*(x))
#define oo 1000000009
using namespace std;
string res;
int X,Y;

void go_to_X() {
    if (X == 0) return;
    if (X > 0) {
        FOR(i,1,X) {
            res.push_back('W');
            res.push_back('E');
        }
    } else FOR(i,1,abs(X)) {
        res.push_back('E');
        res.push_back('W');
    }
}
void go_to_Y() {
    if (Y == 0) return;
    if (Y > 0) {
        FOR(i,1,Y) {
            res.push_back('S');
            res.push_back('N');
        }
    } else FOR(i,1,abs(Y)) {
        res.push_back('N');
        res.push_back('S');
    }
}
int main() {
    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);
    int ntest;
    cin >> ntest;
    FOR(test,1,ntest) {
        cout << "Case #" << test << ": ";
        cin >> X >> Y;
        res = "";
        go_to_X();
        go_to_Y();
        cout << res << endl;
    }
    return 0;
}
