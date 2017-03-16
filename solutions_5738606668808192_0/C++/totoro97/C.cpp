#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int pri[30] = { 0,
2, 3, 5, 7, 11, 13, 17, 19, 23, 29,
31, 37, 41, 43, 47, 53, 59, 61, 67, 71,
73, 79, 83, 89, 97 };

int n,ans[12];

bool re_judge(int t,int base,int p) {
	int res = 0; int u = 1;
	for (; t; t >>= 1) {
		res += u * (t & 1); res %= p;
		u *= base; u %= p;
	}
	return (res == 0);
}

bool rejudge(int t,int base) {
	for (int i = 1; i <= 25; i++)
		if (re_judge(t,base,pri[i])) { ans[base] = pri[i]; return true; }
	return false;
}

bool judge(int t) {
	for (int i = 2; i <= 10; i++) 
		if (!rejudge(t,i)) return false;
	return true;
}

void pr(int t) {
	if (!t) return;
	pr(t >> 1); printf("%d",t & 1);	
}

void print(int t) {
	pr(t); putchar(' ');
	for (int i = 2; i < 10; i++) printf("%d ",ans[i]);
	printf("%d\n",ans[10]);
}

int main() {
	freopen("C.in","r",stdin);
	freopen("C.out","w",stdout);
	int al = 0;
	printf("Case #%d:\n",1);	
	for (int t = (1 << 15) + 1; t < (1 << 16); t += 2) {
		if (judge(t)) al++, print(t);
		if (al == 50) break;
	}
	return 0;
}
