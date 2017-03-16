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

bool isPal(LL n){
    string s = "";
    while(n > 0){
        s.PB('0' + n%10);
        n /= 10;
    }
    string ss = s;
    reverse(ALL(ss));
    if(s == ss) return true;
    return false;
}

LL pal[100000];
LL cnt;
LL a, b;

void init() {
    cnt = 0;
    FOR(i, 1, 10000010) if(isPal(i)) pal[cnt++] = i;
}

void input() {
    cin >> a >> b;
}

void solve() {
    LL res = 0;
    REP(i, cnt){
        LL chk = pal[i]*pal[i];
        if(chk < a) continue;
        if(chk > b) break;
        if(isPal(chk)) res++;
    }
    gout << res << endl;
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
