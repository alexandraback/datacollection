#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>
#include <string.h>

using namespace std;

const double pi = acos(-1.0);
const double eps = 1E-7;
const int inf = int(1e9)+7;

typedef long long int64;
typedef unsigned long long uint64;
#define two(X) (1<<(X))
#define twoL(X) (((int64)(1))<<(X))
#define contain(S,X) (((S)&two(X))!=0)
#define containL(S,X) (((S)&twoL(X))!=0)
#define sqr(x) ((x)*(x))
typedef pair<int,int> ipair;
#define SIZE(A) ((int)A.size())
#define MP(A,B) make_pair(A,B)
#define PB(X) push_back(X)
#define ME(a) memset((a), 0, sizeof((a)))
#define MM(a, b) memcpy((a), (b), sizeof((a)))
#define FOR(i,n) for (int (i) = 0; (i) < (n); ++(i))
#define REP(i,a,b) for (int (i) = (a); (i) < (b); ++(i))

string a = "azejp mysljylc kd kxveddknmc re jsicpdrysi rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd de kr kd eoya kw aej tysr re ujdr lkgc jv";
string b = "yqour language is impossible to understand there are twenty six factorial possibilities so it is okay if you want to just give up";
char f[300], f2[300];

int main() {
	int tot = 0;
	FOR(i, a.size()) {
		if (!f[a[i]] && a[i] >= 'a' && a[i] <= 'z') {
			f[a[i]] = true;
			f2[b[i]] = true;
			tot++;
		}
	}
	cout<<tot<<endl;
	for (int i = 'a'; i <= 'z'; i++) if (!f[i])
	for (int j = 'a'; j <= 'z'; j++) if (!f2[j]) {
		a.push_back(i);
		b.push_back(j);
		cout<<(char)i<<" "<<(char)j<<endl;
	}
	
	ME(f);
	tot = 0;
	FOR(i, a.size()) {
		if (!f[a[i]] && a[i] >= 'a' && a[i] <= 'z') {
			f[a[i]] = true;
			f2[b[i]] = true;
			tot++;
		}
	}
	cout<<tot<<endl;
//	while (1>0) {}
freopen("a.in", "r", stdin);
freopen("a.out", "w", stdout);
	int caseNum;
	cin>>caseNum;
	char buf[120];
	gets(buf);
	REP(c,1,caseNum+1) {
		gets(buf);
	//	puts(buf);
		string s(buf);

		FOR(i, s.size()) {
			FOR(j, a.size()) if (s[i] == a[j]) {
				s[i] = b[j]; 
				break;
			}
		}
		cout<<"Case #"<<c<<": "<<s<<endl;
	}
//	while (1>0) {}
}
