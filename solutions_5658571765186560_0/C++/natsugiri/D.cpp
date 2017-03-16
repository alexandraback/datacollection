#ifndef LOCAL
#define NDEBUG
#endif

#include<cassert>
#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;

typedef long long LL;
typedef vector<int> VI;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define EACH(i,c) for(__typeof((c).begin()) i=(c).begin(),i##_end=(c).end();i!=i##_end;++i)
#define eprintf(s...) fprintf(stderr, s)

int X, R, C;
int main() {
    int T;
    scanf("%d", &T);

    for (int tc=1; tc<=T; tc++) {
	scanf("%d%d%d", &X, &R, &C);
	printf("Case #%d: ", tc);
	if (R>C) swap(R, C);
	
	bool yes;
	if (X > 6) yes = false;
	else if (X == 1) yes = true;
	else if (R * C % X) yes = false;
	else if (R < (X+1)/2) yes = false; // L
	else if (C < X) yes = false; // I
	else if (X == 4) {
	    assert(R>1); assert(C>1);
	    if (R == 2) yes = false;
	    else yes = true;
	} else if (X == 5) {
	    assert(R>2); assert(C>2);
	    if (R == 3 && C == 5) yes = false;
	    else yes = true;
	} else if (X == 6) {
	    assert(R>2); assert(C>2);
	    if (R == 3) yes = false;
	    else yes = true;
	} else {
	    yes = true;
	}
	
	puts(yes? "GABRIEL": "RICHARD");
    }
    assert(false);
    return 0;
}


#ifdef IGNORE
X = 4;
..##...
...##..

X = 5;
.#...
.##..
..##.

.oo#==....
..o##==...
..oo##=...


X = 6;
..##.
.##..
..##.

X > 6;    
###
#.#
##.

#endif
