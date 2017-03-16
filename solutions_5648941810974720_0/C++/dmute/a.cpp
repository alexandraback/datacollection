#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <string>
#include <iomanip>
#include <sstream>
using namespace std;

char str[2050];
int cnt[30], n, ans[30];
int cc(char x) {
	return cnt[x-'A'];
}
void solve(int t) {
	scanf("%s", str);
	n = strlen(str);
	memset(cnt, 0, sizeof cnt);
	for (int i = 0; i < n; i ++) {
		cnt[str[i] - 'A'] ++;
	}
	memset(ans, 0, sizeof ans);
	ans[0]=cc('Z');
	ans[2]=cc('W');
	ans[8]=cc('G');
	ans[4]=cc('U');
	ans[6]=cc('X');
	ans[3]=cc('T')-ans[2]-ans[8];
	ans[5]=cc('F')-ans[4];
	ans[7]=cc('V')-ans[5];
	ans[1]=cc('O')-ans[0]-ans[2]-ans[4];
	ans[9]=cc('I')-ans[5]-ans[6]-ans[8];
	printf("Case #%d: ", t);
	for (int i = 0; i < 10; i ++) 
		for (int j = 0; j < ans[i]; j ++) 
			printf("%d", i);
	printf("\n");
}

int main() {
	int tst;	
	scanf("%d", &tst);
	for (int i = 1; i <= tst; i ++) {
		solve(i);
	}
	return 0;
}