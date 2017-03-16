#include <iostream>
#include <stdio.h>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <string.h>
#include <cmath>
#include <memory.h>
#include <algorithm>
using namespace std;
typedef long long ll;
int n;
char s[1002];
int main()
{
	freopen("src.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int t;
	scanf("%d", &t);
	for (int T = 1; T <= t; ++T){
		printf("Case #%d: ", T);
		scanf("%d%s", &n, s);
		int res = 0, up = s[0] - '0';
		for (int i = 1; i <= n; ++i)
			if(s[i]!='0'){
				res += max(0, i - up);
				up = max(up, i);
				up += s[i] - '0';
			}
		printf("%d\n", res);
	}
	return 0;
}