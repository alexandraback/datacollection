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
const int N(10000010);
int ca, l, r, ans, t;
bool bo[N];
int main()
{
    freopen("in.txt", "r", stdin);
	freopen("C.out", "w", stdout);
	for (scanf("%d", &ca); ca; --ca) {
	    scanf("%d%d", &l, &r);
		int x = 1;
		for (; x * 10<= r; x *= 10);
		ans = 0;
		FOR(i, l, r + 1) {
		   for (int k = i; !bo[k]; k = (k % 10 * x + k / 10)) {
               if (i > k && k >= l && k <= r) ++ans;
			   bo[k] = true;
		   }
		   for (int k = i; bo[k]; k = (k % 10 * x + k / 10)) bo[k] = false;
		}
		printf("Case #%d: %d\n", ++t, ans);
	}
	return 0;
}
