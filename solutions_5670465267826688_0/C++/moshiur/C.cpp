#include <stdio.h>
#include <string.h>
#include <iostream>
#include <set>
#include <cassert>

using namespace std;

typedef long long LL;
LL len, rep;
char str[10005];

int f(char ch) {
	if (ch == 'i') return 2;
	if (ch == 'j') return 3;
	return 4;
}

int combine(int x, int y) {
	if (x == 1) return y;
	if (y == 1) return x;
	if (x == -1) return -y;
	if (y == -1) return -x;

	int xSign = x<0?-1:1;
	int ySign = y<0?-1:1;
	x=abs(x);y=abs(y);
	if (x == y) return -1 * xSign * ySign;

	#define HMM(A,B,sign,C) if (x == f(A) && y == f(B)) return ((sign)*(xSign*ySign)*f(C));
	HMM('i','j',1,'k')
	HMM('j','i',-1,'k')
	HMM('j','k',1,'i')
	HMM('k','j',-1,'i')
	HMM('k','i',1,'j')
	HMM('i','k',-1,'j')
	
	fprintf(stderr, "x = %d, y = %d\n", x , y);
	assert(false);
	return 0;
}

bool isMinusOne() {
	int val = f(str[0]);
	for (int i = 1; str[i]; ++i) val = combine(val, f(str[i]));
	if (val == 1) return false;
	if (val == -1) return rep%2 == 1;
	return (rep%2 == 0 && ((rep/2)%2 == 1));
}

bool solve() {
	if (!isMinusOne()) return false;		

	set<int> seen;	

	int cur = 1;
	bool found_i = false, found_k = false;
	
	for (int i = 0; i < rep; ++i) {
		for (int j = 0; j < len; ++j) {	
			cur = combine(cur, f(str[j]));
			if (cur == f('i')) found_i = true;
			if (found_i && cur == f('k')) found_k = true;
			if (found_i && found_k) return true;
		}
		if (seen.count(cur)) break;
		seen.insert(cur);
	}
	return false;
}

int main() {
	int T; scanf("%d", &T);		
	for(int t=1;t<=T;++t){
		cin>>len>>rep;	
		scanf("%s",str);
		
		printf("Case #%d: %s\n", t, solve() ? "YES" : "NO");
	}
	return 0;
}
