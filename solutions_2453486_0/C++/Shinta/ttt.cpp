#include<cassert>
#include<queue>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<iostream>
#include<string>
#include<cstring>
#include<map>
#include<numeric>
#include<sstream>
#include<cmath>
using namespace std;
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define pb push_back
#define f(i,x,y) for(int i = x; i<y; i++)
#define FOR(it,A) for(typeof A.begin() it = A.begin(); it!= A.end(); it++)
#define quad(x) (x) * (x)
#define mp make_pair
#define clr(x, y) memset(x, y, sizeof x)
#define fst first
#define snd second
typedef pair<int, int> pii;
typedef long long ll;
typedef long long ld;
char s[4][5];
bool queda(){
    f(i, 0, 4) f(j, 0, 4) if(s[i][j] == '.') return true;
    return false;
}
bool row(int r, char c){
    f(i, 0, 4) if(s[r][i] != c) return false;
    return true;
}
bool col(int r, char c){
    f(i, 0, 4) if(s[i][r] != c) return false;
    return true;
}
bool cruz(int yy, int dy, char c){
    f(i, 0, 4) if(s[i][yy + dy * i] != c) return false;
    return true;
}

bool gana(char c){
    int xx = -1, yy;
    f(i, 0, 4) f(j, 0, 4) if(s[i][j] == 'T') xx = i, yy = j;
    if(xx != -1) s[xx][yy] = c;
    f(i, 0, 4) if(row(i, c)) return true;
    f(i, 0, 4) if(col(i, c)) return true;
    if(cruz(0, 1, c) || cruz(3, -1, c)) return true;
    if(xx != -1) s[xx][yy] = 'T';
    return false;
}
int main(){
    int t; cin >> t;
    f(tt, 1, t + 1) {
        f(i, 0, 4) cin >> s[i];
        printf("Case #%d: ", tt);
        if(gana('O')) printf("O won\n");
        else if(gana('X')) printf("X won\n");
        else if(queda()) printf("Game has not completed\n");
        else printf("Draw\n");
    }
}
