


#include <iostream>
#include <iomanip>
#include <fstream>

#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>

#include <sstream>
#include <string>

#include <bitset>
#include <deque>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <vector>

#include <algorithm>

#include <utility>

using namespace std;



const int inf = 2000000000;
const long long linf = 9000000000000000000LL;
const double finf = 1.0e18;
const double eps = 1.0e-8;


char S[] = "yhesocvxduiglbkrztnwjpfmaq";

char s[105];

int T, la, lb, lc, ld, l;

int main() {
	scanf("%d", &T);
	fgets(s, 105, stdin);
	for (int tt=1; tt<=T; tt++) {
		fgets(s, 105, stdin);
		l = strlen(s);
		for (int i=0; i<l; i++)
			if (('a'<=s[i]) && (s[i]<='z')) 
				s[i] = S[ s[i]-'a' ];
		printf("Case #%d: %s", tt, s);
	}
	return 0;
}


