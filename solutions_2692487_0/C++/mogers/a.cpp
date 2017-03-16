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
int v[110], N, A;

void solve() {
	int i, res = 0;
	cin >> A >> N;
	for (i = 0; i < N; i++)
		cin >> v[i];
	sort(v, v+N);
	for (i = 0; A > v[i] && i < N; i++) {
		A += v[i];
	}
	res = N-i;
	if (A > 1) {
		int s = 0;
		for ( ; i < N ; i++) {
			while (A <= v[i]) {
				s++;
				A += (A-1);
			}
			A += v[i];
			res = min(res , s + N-i-1);
		}
	}
	cout << res << endl;
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
