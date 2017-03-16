#include<iostream>
#include<fstream>
#include<sstream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<vector>
#include<map>
#include<cstring>
using namespace std;

#define FOR(I,A,B) for (int I=int(A);I<int(B);++I)
#define MEM(A,B) memset(A,B,sizeof(A));
#define CPY(A,B) memcpy(A,B,sizeof(B));
typedef __int64 LL;

int ca, n, s, p, t, a, ans;
int main()
{
    freopen("in.txt", "r", stdin);
    freopen("B.out", "w", stdout);
	for (scanf("%d", &ca); ca; --ca) {
	    scanf("%d%d%d", &n, &s, &p);
	    ans = 0;
		FOR(i, 0, n) {
		   scanf("%d", &a);
		   if ((a + 2) / 3 >= p) ++ans;
		   else if (a >= 2 && a <= 28 && a % 3 != 1 && (a + 2) / 3 + 1 >= p && s) {
		        ++ans; --s;
		   }
		}
		printf("Case #%d: %d\n", ++t, ans);
	}
	return 0;
}
