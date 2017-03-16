#include <cstdio>
#include <cstring>
#include <algorithm>
#define intl long long
using namespace std;

int pri[30] = { 0,
2, 3, 5, 7, 11, 13, 17, 19, 23, 29,
31, 37, 41, 43, 47, 53, 59, 61, 67, 71,
73, 79, 83, 89, 97 };

int n,ans[12];

bool re_judge(intl t,int base,int p) {
	int res = 0; int u = 1;
	for (; t; t >>= 1) {
		res += u * (int) (t & 1LL); res %= p;
		u *= base; u %= p;
	}
	return (res == 0);
}

bool rejudge(intl t,int base) {
	for (int i = 1; i <= 25; i++)
		if (re_judge(t,base,pri[i])) { ans[base] = pri[i]; return true; }
	return false;
}

bool judge(intl t) {
	for (int i = 2; i <= 10; i++) 
		if (!rejudge(t,i)) return false;
	return true;
}

void pr(intl t) {
	if (!t) return;
	pr(t >> 1); printf("%lld",t & 1LL);	
}

void print(intl t) {
	pr(t); putchar(' ');
	for (int i = 2; i < 10; i++) printf("%d ",ans[i]);
	printf("%d\n",ans[10]);
}

int main() {
	freopen("C.in","r",stdin);
	freopen("C.out","w",stdout);
	int al = 0;
	printf("Case #%d:\n",1);	
	for (intl t = (1LL << 31) + 1LL; t < (1LL << 32); t += 2LL) {
		if (judge(t)) al++, print(t);
		if (al == 500) break;
	}
	return 0;
}

