#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>

using namespace std;

typedef long long LL;

const int maxn = 2333;

char s[maxn];

int main(){
	int T;
	scanf("%d", &T);
	for (int TI = 1; TI <= T; ++TI){
		int n;
		scanf("%d", &n);
		scanf("%s", s);
		int tot = 0, ans = 0;
		for (int i = 0 ; i <= n; ++i){
			if (tot < i){
				ans += i - tot;
				tot = i;
			}
			tot += (int)(s[i] - '0');
		}
		printf("Case #%d: %d\n", TI, ans);
	}
	return 0;
}
