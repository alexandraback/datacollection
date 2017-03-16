#include <algorithm>
#include <cassert>
#include <cctype>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
using namespace std;
typedef long long LL;
typedef long double LD;
typedef pair<int,int> PII;
typedef vector<int> VI;
#define REP(I,N) for(int I=0;I<(N);++I)
#define FOR(I,A,B) for(int I=(A);I<=(B);++I)
#define FORD(I,A,B) for(int I=(A);I>=(B);--I)
#define FOREACH(I,C) for(__typeof((C.begin())) I=(C).begin();I!=(C).end();++I)
#define st first
#define nd second
#define mp make_pair
#define pb push_back

string s1 = "ejp mysljylc kd kxveddknmc re jsicpdrysi rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd de kr kd eoya kw aej tysr re ujdr lkgc jv";
string s2 = "our language is impossible to understand there are twenty six factorial possibilities so it is okay if you want to just give up";
char mapping[300];

void find_mapping() {
  REP(i,s1.length()) mapping[s1[i]] = s2[i];  
  mapping['z'] = 'q';
  mapping['q'] = 'z';
}

void solve() {
  char buff[300];
  gets(buff);
  int len = strlen(buff);
  REP(i,len) if ('a' <= buff[i] && buff[i] <= 'z') buff[i] = mapping[buff[i]];
  puts(buff);  		
}

int main() {
  find_mapping();
	int tests;
	scanf("%d\n",&tests);
	FOR(test,1,tests) {
		printf("Case #%d: ", test);
		solve();
	}
	return 0;
}

















