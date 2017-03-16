#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <string>
#include <sstream>
#include <queue>
#include <list>
#include <stack>
using namespace std;
#define PB			push_back
#define ALL(v)			(v).begin() , (v).end()
#define SZ(v)			( (int) v.size() )
#define Set(v,x)		memset(  v , x , sizeof(v))
#define two(n)			( 1 << (n) )
#define contain(S,i)		( (S) & two(i) ) 
#define SQR(v)			( (v) * (v) )
#define ABS(x)			( ( (x) >= 0 ) ? (x) : -(x) )
#define foreach(v,it)		for( typeof((v).begin()) it = (v).begin() ; it != (v).end() ; it++ )
const int MAX = 1 << 20;
#define off 250000
int y[MAX], N, cx, cy;
long double res;

void go(int i, int xx, long double p) {
	if ( y[xx] == -1 || (y[xx-1] > y[xx] && y[xx] < y[xx+1])) {
	//	printf("%d) place at %d, %d   p = %.2Lf    %d  %d  %d\n", i, xx-off, y[xx]+1, p, y[xx-1], y[xx], y[xx+1]);
		if (xx == cx && cy == y[xx]+1) {
			res += p;
			return;
		}
		if (i < N) {
			y[xx] += 2;
			go(i+1, off, p);
			y[xx] -= 2;
		}
	} else {
	//	printf("%d) decide  xx: %d :    %d    %d    %d   p %.2Lf\n", i, xx-off, y[xx-1], y[xx], y[xx+1], p);
		if (y[xx-1] < y[xx] && y[xx] > y[xx+1]) {
			go(i, xx+1, p/2);
			go(i, xx-1, p/2);
		} else if (y[xx-1] > y[xx+1]) {
			go(i, xx+1, p);
		} else {
			go(i, xx-1, p);
		}
	}
}
void solve() {
	res = 0.0;
	cin >> N >> cx >> cy;	
	if (cx == 0 && cy == 0)
		res = 1.0;
	else {
		cx += off;
		for (int i = 0; i < 100; i+= 2) {
			y[off-i] = y[off+i] = -1; 
			y[off-i+1] = y[off+i-1] = 0; 
		}
		y[off] = 1;
//		puts("");
		go(2, off, 1.0);
	}
	printf("%.8Lf\n", res);
}

int main() {
	int C , nc;
	
	scanf("%d\n", &C);
	for ( nc = 1 ; nc <= C ; nc++) {
		cout << "Case #" << nc << ": ";
		solve();
	}	
	return 0;
}
