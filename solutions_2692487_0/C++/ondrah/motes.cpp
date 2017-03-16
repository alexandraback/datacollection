#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <utility>
#include <vector>

#define FOR(I,A,B)	for(int I = (A); I < (B); ++I)
#define REP(I,N)	FOR(I,0,N)
#define ALL(A)		(A).begin(), (A).end()

using namespace std;
int M[1111];
int main()
{
	int CASE,T;
	scanf("%d", &T);

	REP(CASE, T) {
		int A, n;
		scanf("%d %d", &A, &n);
		REP(i, n) scanf("%d", M+i);
		sort(M, M+n);
		int s = 0;
		while(s < n && M[s] < A) { A += M[s++]; }
		int ans = 999999999;
		if(A == 1) {
			ans = n;
		}
		else if(s < n) {
			for(int cnt = 0; cnt <= n-s; cnt++) {
				int add = 0;
				int p = s;
				int AA = A;
				while(p < n-cnt && M[p] >= AA) {
					AA += AA-1;
					add++;
					while(p < n-cnt && M[p] < AA) {
						AA += M[p++];
					}
				}
				int x = add+cnt;
				ans = min(ans, x);
			}
		} else ans = 0;
		printf("Case #%d: %d\n", CASE+1, ans);
	}
	return 0;
}
