/*
 * author ATailouloute
 */

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <cmath>
#include <stack>
#include <climits>

using namespace std;

#define F(i,L,R)   for(int i=L; i<R;  i++)
#define FE(i,L,R)  for(int i=L; i<=R; i++)
#define FF(i,L,R)  for(int i=L; i>R;  i--)
#define FFE(i,L,R) for(int i=L; i>=R; i--)
#define DBG(vari) cerr<<#vari<<" = "<<(vari)<<endl;

int main(){

	freopen("A-small-attempt0.in", "r", stdin);
	freopen("A-small-attempt0.out", "w", stdout);

	int T, Smax, ans, Len;
	string s;
	scanf("%d", &T);

	FE(i, 1, T){
		printf("Case #%d: ", i);
		scanf("%d", &Smax);
		cin >> s;
		Len = s.length();
		ans = 0;
		int inv = s[0] - '0';
		F(j, 1, Len){
			int cj = s[j] - '0';
			if(cj != 0 && inv < j){
				ans += (j - inv);
				inv += (j - inv);
			}
			inv += cj;
		}
		printf("%d\n", ans);
	}

	return 0;
}
