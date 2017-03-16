#include <cstdio>
#include <set>
#include <cstdlib>
#include <ctime>
using namespace std;

unsigned int cur;
int dv[11];
int N, J;
set<unsigned int> used;

bool check () {
	for (int base = 2;base <= 10;++base) {
		long long sum = 0, mul = 1;
		long long cur2 = cur;
		while (cur2) {
			if (cur2 & 1) sum += mul;
			cur2>>=1;
			mul *= base;
		}
		bool ok = 0;
		for (int j=2;(long long)j*j <= sum;++j) {
			if (sum %j == 0) {
				ok = 1;
				dv[base] = j;
				break;
			}
		}
		if (!ok) return false;
	}
	used.insert(cur);
	for (unsigned int i = (1<<(N-1));i>=1;i>>=1) {
		if (cur & i) printf("1");
		else printf("0");
	}
	printf(" ");
	for (int base=2;base<10;++base) printf("%d ",dv[base]);
	printf("%d\n",dv[10]);
	return true;
}

int main () {
	srand(time(0));
	scanf("%d %d",&N,&J);
	printf("Case #%d:\n",1);
	while (1) {
		cur = (rand()%(1<<N) | 1 | (1<<(N-1)));
		if (used.find(cur) != used.end()) continue;
		if (check() && --J == 0) break;
	}
	return 0;
}
