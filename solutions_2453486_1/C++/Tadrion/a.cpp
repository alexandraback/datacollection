//Tadrion
#include <cstdio>
#include <vector>
#include <iostream>
#include <deque>
#include <map>
#include <set>
#include <string>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <queue>
#include <stack>
#include <algorithm>
#include <utility>
using namespace std;
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define CLEAR(x) (memset(x,0,sizeof(x)))
#define SZ(x) ((int)(x).size())
#define ALL(x) (x).begin(),(x).end()
#define VAR(v, n) __typeof(n) v = (n)
#define FOR(x, b, e) for(int x = b; x <= (e); ++x)
#define FORD(x, b, e) for(int x = b; x >= (e); --x)
#define REP(x, n) for(int x = 0; x < (n); ++x)
#define FOREACH(i, c) for(VAR(i,(c).begin()); i != (c).end(); ++i)
#define DBG(v) cout<<#v<<" = "<<v<<endl;
#define IN(x,y) ((y).find(x)!=(y).end())
#define ST first
#define ND second
#define PB push_back
#define PF push_front
#define MP make_pair
typedef long long int LL;
typedef pair<int,int> PII;
typedef vector<int> VI;


bool check_diag1(vector<string> v, char c) {

    if(c == v[0][0] && c == v[1][1] && c == v[2][2]&& c == v[3][3]) return true;

    return false;
}

bool check_diag2(vector<string> v, char c) {
    if(c == v[3][0] && c == v[2][1] && c == v[1][2] && c == v[0][3]) return true;
    return false;
}

bool check_ver(vector<string> v, char c) {
    FOR(j,0,3) {
        if(c == v[0][j] && c == v[1][j] && c == v[2][j] && c== v[3][j]) return true;
    }
    return false;
}

bool check_hor(vector<string> v, char c) {
    FOR(i,0,3) {
        if(c == v[i][0] && c == v[i][1] && c == v[i][2] && c == v[i][3]) return true;
    }

    return false;
}

bool check(vector<string> v, char c) {
    vector<string> v1;

    REP(i,SZ(v)) v1.PB(v[i]);

    REP(i,SZ(v))
        REP(j,SZ(v[i])) if(v1[i][j] == 'T') v1[i][j] = c;


    //REP(i,SZ(v)) cout << v1[i] << "\n";
    //cout << "\n";

    if(check_hor(v1,c) || check_ver(v1,c) || check_diag1(v1,c) || check_diag2(v1,c)) return true;
    return false;

}

bool isdot(vector<string> v) {
    REP(i,SZ(v))
        REP(j,SZ(v[i])) if(v[i][j] == '.') return true;

    return false;
}

int judge(vector<string> v) {
    if(check(v,'X')) return 0;
    if(check(v,'O')) return 1;
    if(isdot(v)) return 3;
    return 2;
}


int T;
int main() {
  vector<string> v;
  scanf("%d",&T);
  FOR(tttt,1,T) {
    v.clear();
    string s;
    for(int i = 0; i < 4; i++) {cin >> s; v.PB(s);}
    int res = judge(v);
    printf("Case #%d: ",tttt);
    if(res == 0) {
        printf("X won\n");
    }
    else if(res == 1) {
        printf("O won\n");
    }
    else if(res == 2) {
        printf("Draw\n");
    }
    else if(res == 3) {
        printf("Game has not completed\n");
    }
  }

  return 0;
}
