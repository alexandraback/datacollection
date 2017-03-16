#include <assert.h>
#include <ctype.h>
#include <float.h>
#include <cmath>
#include <stdio.h>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <algorithm>
#include <numeric>
#include <functional>
#include <utility>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <sstream>
#include <iostream>
#include <memory.h>

using namespace std;

#define PI 3.14159265359
#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,k,n) for (int i=(k); i<=(int)(n); ++i)
#define OPENFILE
#define FILENAME "A-small-attempt0"

typedef long long ll;

string s;
int n;

int main() {
#ifdef OPENFILE
	char INPUTF[30] = FILENAME;
	char INPUTF2[30] = FILENAME;
	freopen(strcat(INPUTF, ".in"), "r", stdin); //redirects standard input
	freopen(strcat(INPUTF2, ".out"), "w", stdout); //redirects standard output
#endif
	int T;
	cin >> T;
	REP(t,T)
	{
		cin >> s >> n;
		int num = 0;
		int total = s.length();
		int pre = -1;
		ll res = 0;
		REP(i,total)
		{
			if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o'
					|| s[i] == 'u') {
				num = 0;
			} else {
				num++;
				if (num >= n) {
					res += (total -1- i + 1) * (i - n + 1 - pre + 1-1);
					pre = i - n + 1;
				}
			}

		}

		printf("Case #%d: %lld\n", t + 1, res);
		cerr << t + 1 << endl;
		fflush(stdout);
	}
}
