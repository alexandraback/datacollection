#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <numeric>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <cassert>
#include <cstdarg>
#include <sys/time.h>
#include <fstream>
//#include "cout.h"

using namespace std;

#define SZ(x) ((int)x.size())
#define MSET(x,a) memset(x, a, (int)sizeof(x))
#define PB push_back
#define VI vector < int >
#define PII pair < int, int >
#define LL long long
#define FOR(i,a,b) for (int i = (a); i < (b); i++)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(), (v).end()
#define FIT(it,v) for (__typeof((v).begin()) it = (v).begin(); it != (v).end(); it++)
#define OUT(A) cout << #A << " = "<< (A) << endl

#define present(c, e) ((c).find((e)) != (c).end())
#define cpresent(c, e) (find(all(c), (e)) != (c).end())

int case_number;
#define printg case_number++, printf("Case #%d: ",case_number), printf
#define gout case_number++, printf("Case #%d: ",case_number), cout

string b[4];

char chk(char c1, char c2, char c3, char c4){
    string s = "";
    s.PB(c1);
    s.PB(c2);
    s.PB(c3);
    s.PB(c4);
    sort(ALL(s));
    if(s[0] == 'a') return 'a';
    if(s[0] == 'b'){
        char c = s[1];
        if(s[2] == c && s[3] == c) return c;
        else return 'a';
    }
    else{
        char c = s[0];
        if(s[1] == c && s[2] == c && s[3] == c) return c;
        else return 'a';
    }
}

void init() {
}

void input() {
    REP(i, 4){
        string s;
        cin >> s;
        REP(j, 4){
            if(s[j] == '.') s[j] = 'a';
            if(s[j] == 'T') s[j] = 'b';
            if(s[j] == 'O') s[j] = 'c';
            if(s[j] == 'X') s[j] = 'd';
        }
        b[i] = s;
    }
}

void solve() {
    char res = 'a';
    char c;
    REP(i, 4){
        c = chk(b[i][0], b[i][1], b[i][2], b[i][3]);
        if(c != 'a') res = c;
    }
    REP(i, 4){
        c = chk(b[0][i], b[1][i], b[2][i], b[3][i]);
        if(c != 'a') res = c;
    }
    c = chk(b[0][0], b[1][1], b[2][2], b[3][3]);
    if(c != 'a') res = c;
    c = chk(b[0][3], b[1][2], b[2][1], b[3][0]);
    if(c != 'a') res = c;
    
    if(res != 'a'){
        if(res == 'c') res = 'O';
        else res = 'X';
        gout << res << " won" << endl;
        return;
    }
    
    bool nc = false;
    REP(i, 4) REP(j, 4) if(b[i][j] == 'a') nc = true;
    if(nc){
        gout << "Game has not completed" << endl;
        return;
    }
    
    gout << "Draw" << endl;
    
}

int main() {
	init();
	int number_of_test_cases;
	scanf("%d",&number_of_test_cases);
	REP(i,number_of_test_cases){
		input();
		solve();
	}
	return 0;
}
