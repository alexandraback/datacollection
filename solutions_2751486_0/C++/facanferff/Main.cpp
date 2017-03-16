#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
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
#include <ctime>
#include <cstring>
#include <string>
// Uncomment for libgmp
/*#include "gmpxx.h"
#define big mpz_class*/

using namespace std;

bool isvowel(char c) {
	return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

int cnt(string s, int n) {
	int m = 0;
	int maxi = 0;
	char l = 'a';
	for (int i = 0; i < s.size(); i++) {
		if (!isvowel(s[i])) {
			m++;
		}
		else {
			if (m > maxi) maxi = m;
			m = 0;
		}
	}
	if (m > maxi) maxi = m;
	return maxi;
}

 
int main()
{
    int t;
    cin >> t;
    getchar();
    for (int c = 1; c <= t; c++) {
    	fprintf(stderr, "Case #%d of %d...\n", c, t);
    	string s;
    	int n;
    	cin >> s >> n;
    	map< pair<int, int>, bool > used;
    	//printf("%s %d\n", s.c_str(), s.size());
    	int tot = 0;
    	for (int i = 0; i < s.size(); i++) {
    		for (int j = n; j < s.size() - i + 1; j++) {
    			string s0 = s.substr(i, j);
    			//printf("%s\n", s0.c_str());
    			//printf("%s %d %d %d\n", s0.c_str(), cnt(s0, n), i, j);
    			if (cnt(s0, n) >= n/* && !used[make_pair(i, i + j)]*/) {
    				used[make_pair(i, i + j)] = true;
    				tot++;
    			}
    		}
    	}
    	printf("Case #%d: %d\n", c, tot);
    }
    return 0;
}
