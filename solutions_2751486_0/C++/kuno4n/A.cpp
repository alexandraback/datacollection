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

string s;
int n;
bool si[1000005];
int tab[1000005];

void init() {
}

void input() {
	cin >> s >> n;
	
}

void solve() {
	REP(i, SZ(s)) {
		if(s[i] != 'a' && s[i] != 'i' && s[i] != 'u' && s[i] != 'e' && s[i] != 'o')
			si[i] = true;
		else si[i] = false;
	}
	REP(i, 1000005) tab[i] = -1;
	
	int cns = 0;
	for(int i = SZ(s)-1; i >= 0; i--){
		if(si[i]) cns++;
		else cns = 0;
		if(cns >= n) tab[i] = i;
		else if(i < SZ(s)-1) tab[i] = tab[i+1];
	}
	LL res = 0;
	REP(i, SZ(s)) if(tab[i] >= 0) res += SZ(s) - tab[i] - n + 1;
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
