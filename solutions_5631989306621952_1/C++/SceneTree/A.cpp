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

typedef long long int64;
typedef unsigned long long uint64;
#define two(X) (1<<(X))
#define twoL(X) (((int64)(1))<<(X))
#define contain(S,X) (((S)&two(X))!=0)
#define containL(S,X) (((S)&twoL(X))!=0)
#define sqr(x) ((x)*(x))
#define Abs(x) ((x) < 0 ? (-(x)) : (x))
typedef pair<int,int> ipair;
#define SIZE(A) ((int)A.size())
#define MP(A,B) make_pair(A,B)
#define PB(X) push_back(X)
#define ME(a) memset((a), 0, sizeof((a)))
#define MM(a, b) memcpy((a), (b), sizeof((a)))
#define FOR(i,n) for (int (i) = 0; (i) < (n); ++(i))
#define REP(i,a,b) for (int (i) = (a); (i) < (b); ++(i))

string s;
int Tests;

	string f(string x) {
		if (x.size() == 0) return "";
		char ch = 'A';
		int j = 0;
		for (int i = 0; i < x.size(); ++i)
			if (x[i] > ch) {
				ch = x[i];
				j = i;
			}
		string y = x.substr(0, j);
		string ans1 = "";
		string ans2 = "";
		for (int i = j; i < x.size(); ++i)
			if (x[i] == ch) ans1 += x[i]; else ans2 += x[i];
		return ans1 + f(y) + ans2;
	}

int main() {
	freopen("A-large.in", "r", stdin);
	freopen("A-large.out", "w", stdout);
	scanf("%d", &Tests); 
	for (int tts = 0; Tests--; ) {
		cin >> s;
		printf("Case #%d: ", ++tts);
		cout << f(s) << endl;
	}
	return 0;
}