#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <fstream>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <queue>
#include <string.h>
#define rep(x,n) for(int x=0;x<n;++x)
#define rep1(i,s) for(int i = 0; i < (int)s.size(); ++i)
#define mem(a, b) memset(a, b, sizeof(a))

#define mp(x,y) make_pair(x,y)
#define getBit(code, i) (code & (1 << i))
#define setBit(code, i) (code | (1 << i))
#define xetBit(code, i) (code & ~(1 << i))
#define PI acos(-1.0)
#define oo (int)10e7
#define rdfile(x) freopen(x, "r", stdin)
#define wtfile(x) freopen(x, "w", stdout)
#define ll long long

using namespace std;

int T;

char vowls[] = {'a', 'e', 'i', 'o', 'u'};
bool isVowel(char x) {
	rep(i, 5) {
		if(x == vowls[i])
			return true;
	}
	return false;
}


string str;
int N;


int main() {
	freopen("Text.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	cin >> T;
	rep(caseNum, T) {
		cin >> str >> N;
		int cnt = 0;
		long long res = 0;
		int last = 0;
		rep(i, str.size()) {
			if(isVowel(str[i])) {
				cnt = 0;
			} else { 
				++cnt;
				if(cnt >= N) {
					res += (str.size()-i)*(i-N+2-last);
					last = (i-N+2);
				}
			}
		}
		printf("Case #%d: %lld\n",caseNum+1, res);
	}
}