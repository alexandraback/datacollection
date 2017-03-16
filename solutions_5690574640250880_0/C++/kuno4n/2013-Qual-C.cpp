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
#define OUT2(A, B) cout << "(" << #A << ", " << #B << ") = (" << (A) << ", "<< (B) << ")" << endl
template<class T> void chmin(T &t, T f) { if (t > f) t = f; } 
template<class T> void chmax(T &t, T f) { if (t < f) t = f; } 

#define present(c, e) ((c).find((e)) != (c).end())
#define cpresent(c, e) (find(all(c), (e)) != (c).end())

int case_number;
#define printg case_number++, printf("Case #%d: ",case_number), printf
#define gout case_number++, printf("Case #%d: ",case_number), cout

int x, y, m;

void init() {
}

void input() {
    cin >> x >> y >> m;
}

void solve() {
    
    gout << endl;
    
    char res[55][55];
    REP(i, 55) REP(j, 55) res[i][j] = '.';
    res[0][0] = 'c';
    
    if(m == x * y - 1){
        REP(i, x) {
            REP(j, y){
                if(i == 0 && j == 0){}
                else res[i][j] = '*';
            }
        }
    }
    else if(x == 1){
        for(int j = y-1; m > 0; m--, j--) res[0][j] = '*';
    }
    else if(y == 1){
        for(int i = x-1; m > 0; m--, i--) res[i][0] = '*';
    }
    else if(x == 2){
        if((m&1) || m == (y-1)*2){
            cout << "Impossible" << endl;
            return;
        }
        for(int j = y-1; m > 0; m-=2, j--){
            res[0][j] = '*';
            res[1][j] = '*';
        }
    }
    else if(y == 2){
        if((m&1) || m == (x-1)*2){
            cout << "Impossible" << endl;
            return;
        }
        for(int i = x-1; m > 0; m-=2, i--){
            res[i][0] = '*';
            res[i][1] = '*';
        }
    }
    else{
        int remain = x * y - m - 1;
        if(remain == 1 || remain == 2 || remain == 4 || remain == 6){
            cout << "Impossible" << endl;
            return;
        }
        REP(i, x) REP(j, y) res[i][j] = '*';
        res[0][0] = 'c';
        res[0][1] = res[1][0] = res[1][1] = '.';
        remain -= 3;
        if(remain > 0){
            res[0][2] = res[1][2] = '.';
            remain -= 2;
        }
        if(remain > 0){
            res[2][0] = res[2][1] = '.';
            remain -= 2;
        }
        for(int i = 3; i < x && remain > 0; i++, remain -= 2){
            if(remain == 1){
                res[2][2] = '.';
                break;
            }
            res[i][0] = res[i][1] = '.';
        }
        for(int j = 3; j < y && remain > 0; j++, remain -= 2){
            if(remain == 1){
                res[2][2] = '.';
                break;
            }
            res[0][j] = res[1][j] = '.';
        }
        for(int i = 2; i < x && remain > 0; i++){
            for(int j = 2; j < y && remain > 0; j++, remain--){
                res[i][j] = '.';
            }
        }
    }
    
    REP(i, x){
        REP(j, y) cout << res[i][j];
        cout << endl;
    }
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
