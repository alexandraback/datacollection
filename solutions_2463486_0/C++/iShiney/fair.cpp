#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <numeric>

using namespace std;

char mynum[100];
bool isgood[1010];
int T;

bool is_pali(long long i) {
	sprintf(mynum, "%lld", i);
	int len = strlen(mynum);
	for(int i=0; i<len/2; i++) {
		if (mynum[i] != mynum[len-1-i])
			return false;
	}
	return true;
}

int main() {
	freopen("fair.in", "r", stdin);
	for(long long i=1; i<=31; i++) {
		if (is_pali(i) && is_pali(i*i)) {	
			isgood[i*i] = 1;
		}
	}
	scanf("%d", &T);
	for(int asdf=1; asdf<=T; asdf++) {	
		int a, b; scanf("%d%d", &a, &b);
		printf("Case #%d: %d\n", asdf, accumulate(isgood+a, isgood+b+1, int(0)));
		}


	return 0;
}
