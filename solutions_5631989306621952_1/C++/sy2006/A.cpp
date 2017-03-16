#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <iostream>
#define mp make_pair
#define pb push_back
#define fir first
#define sec second
using namespace std;
typedef long long ll;

template <typename T> inline void R(T &x) {
	char ch = getchar(); x = 0;
	for (; ch<'0' || ch>'9'; ch = getchar());
	for (; ch<='9' && ch>='0'; ch=getchar()) x = x*10 + ch-'0';
}
const int N = 1005;
char S[N];
string r1, r2;
int n;
void run() {
	scanf("%s", S);
	r1 = r2 = "";
	n = strlen(S);
	char *np, *p = S + n;
	while (p > S) {
		np = S;
		for (char *x=S; x<p; ++x)
			if (*x >= *np)
				np = x;
		for (--p; p > np; --p)
			r2 += *p;
		r1 += *np;
	}
	reverse(r2.begin(), r2.end());
	cout << r1 + r2 << endl;
}
int main() {
	int T; scanf("%d", &T);
	for (int i=1; i<=T; ++i) {
		printf("Case #%d: ", i);
		run();
	}
	return 0;
}