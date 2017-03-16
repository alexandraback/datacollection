#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cassert>
#include <set>
#include <map>
#include <queue>
#include <iostream>
#include <fstream>
using namespace std;
#define pb push_back 
#define REP(i,n) for(int i=0;i<(n);i++ )
typedef long long LL;
typedef pair<int, int> pii;

LL L, X; string s;

inline void mul(char& x, char& y, char a, char b) {
	int c = 0;
	c += x == '-';
	c += a == '-';
	if (y == '1') {
		y = b;
	}
	else if (y == 'i') {
		if (b == '1') y = 'i';
		if (b == 'i') y = '1', c++;
		if (b == 'j') y = 'k';
		if (b == 'k') y = 'j', c++;
	}
	else if (y == 'j') {
		if (b == '1') y = 'j';
		if (b == 'i') y = 'k', c++;
		if (b == 'j') y = '1', c++;
		if (b == 'k') y = 'i';
	}
	else if (y == 'k') {
		if (b == '1') y = 'k';
		if (b == 'i') y = 'j';
		if (b == 'j') y = 'i', c++;
		if (b == 'k') y = '1', c++;
	}
	x = (c & 1) ? '-' : '+';
}

bool dosmall() {
	char x = '+', y = '1';
	LL c1 = L * X + 1, c2 = -1;
	REP(i, X)
		REP(j, L) {
			mul(x, y, '+', s[j]);
			// cout<<'='<<i<<' '<<j<<' '<<x<<' '<<y<<endl;
			if (x == '+' && y == 'i') {
				c1 = min(c1, i * L + j);
			}
			if (x == '+' && y == 'k') {
				c2 = max(c2, i * L + j);
			}
		}

	// cout<<x<<' '<<y<<' '<<c1<<' '<<c2<<endl;
	if (x != '-' || y != '1') return 0;
	if (c1 >= c2) return 0;
	return 1;

}


bool dobig() {
	char x = '+', y = '1';
	bool c1 = false, c2 = false;
	REP(i, X % 4)
		REP(j, L) {
			mul(x, y, '+', s[j]);
		}
	if (x != '-' || y != '1') return 0;
	x = '+', y = '1';
	REP(i, 16)
		REP(j, L) {
			mul(x, y, '+', s[j]);
			if (x == '+' && y == 'i') {
				c1 = true;
			}
			if (x == '+' && y == 'k') {
				c2 = true; //TODO
			}
		}
	if (!c1 || !c2) return 0;
	return 1;

}

int main(){
    int caseNumber;
    //scanf("%d", &caseNumber);
    cin>>caseNumber;
    REP(caseN, caseNumber) {
    	cin>>L>>X>>s;
    	int res;
    	if (X < 20) {
	    	res = dosmall();
	    } else {
	    	res = dobig();
	    }
    	printf("Case #%d: %s\n", caseN + 1, res ? "YES" : "NO");
    }
    return 0;
}