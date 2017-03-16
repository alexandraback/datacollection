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

const int mod = 1000000007;
int n;
string ss[110];


string int2str(LL a){
    stringstream ss;
    ss << a;
    string res;
    ss >> res;
    return res;
}


void init() {
}

void input() {
    cin >> n;
    REP(i, n){
        string s;
        cin >> s;
        ss[i] = "";
        ss[i] += s[0];
        for(int j = 1; j < SZ(s); j++) if(s[j-1] != s[j]) ss[i] += s[j];
        ss[i] += int2str(i);
    }
    sort(ss, ss+n);
}

void solve() {
    int res = 0;
    do{
        string s = "";
        REP(i, n) s += ss[i].substr(0, SZ(ss[i])-1);
        int m = SZ(s);
        int ptr = 0;
        bool chk[30]; MSET(chk, false);
        for(; ptr < m; ptr++){
            int c = s[ptr] - 'a';
            if(chk[c] && s[ptr-1] != s[ptr]) break;
            chk[c] = true;
        }
        if(ptr == m) res++;
    }while(next_permutation(ss, ss+n));
    gout << res%mod << endl;
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
