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
const int N(100010);
int q, A, B, ca;
double ans;
double p[N];
int main()
{
    freopen("A.in", "r", stdin);
	freopen("A.out", "w", stdout);
	for (scanf("%d", &q); q; --q) {
	    scanf("%d%d", &A, &B);
		p[0] = 1;
		FOR(i, 1, A + 1) {
		   scanf("%lf", &p[i]);
		   p[i] *= p[i - 1];
		}
		ans = B + 2;
		FOR(i, 0, A + 1) 
		   ans = min(ans, A - i + B - i  + 1 + (1 - p[i]) * (B + 1));
		printf("Case #%d: %.6lf\n", ++ca, ans);
	}
	return 0;
}
