#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>

using namespace std;
#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define FORD(i,a,b) for(int i=(a);i>=(b);--i)
#define REP(i,a) for(int i=0; i<a;++i)
inline bool EQ(double a, double b) {return fabs(a-b) < 1e-9;}

const int INF = 1<<29;
typedef long long ll;

int T;
char S[200];
           //abcdefghijklmnopqrstuvwxyz
char tr[] = "yhesocvxduiglbkrztnwjpfmaq";

int main() {
	scanf("%d\n", &T);
	REP(t,T) {
		gets(S);
		int L = strlen(S);
		REP(i,L+1) {
			if (S[i] != ' ' && S[i] != 0) {
				S[i] = tr[S[i]-'a'];
			}
		}
		printf("Case #%d: %s\n", t+1, S);
	}
	return 0;
}
