#include <cstdio>
#include <algorithm>
#include <cstring>
#include <utility>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <iostream>
#include <set>
#include <cmath>
#include <cassert>
#include <ctime>
#include <string>
#define fr(a,b,c) for(int a = b; a < c; a++)
#define rp(a,b) fr(a,0,b)
#define inf 0x3f3f3f3f
#define maxn 1111111
typedef long long ll;

using namespace std;

char dic[15][621196][50];
int size[15];
char str[50];
int n;

int dp[100][100];

int lol = 0;
int solve(int ind, int last, string s = "") {
	if (~dp[ind][last+5]) return dp[ind][last+5];
	if (ind == n) return dp[ind][last+5] = 0;
	int ret = inf;
//	cout << s << ind << " " << last << endl;
	for (int i = ind; i < n; i++) {
		int sz = i-ind+1;
		if (sz > 10) break;
		for (int j = 0; j < size[sz]; j++) {
			int tempLast = last;
			int changes = 0;
			for (int p = ind, q = 0; p <= i; p++, q++) {
				if (str[p] != dic[sz][j][q]) {
					if (p-tempLast < 5) goto aff;
					changes++;
					tempLast = p;
				}
			}
			ret = min(ret, changes+solve(i+1,tempLast,s+" "));
			aff:;
		}
	}
	return dp[ind][last+5] = ret;
}

int main() {
	FILE * pFile;
	pFile = fopen("garbled_email_dictionary.txt", "r");
	memset(size,0,sizeof size);
	while (fscanf(pFile, "%s", str) == 1) {
		int strSize = strlen(str);
		for (int i = 0; i <= strSize; i++) dic[strSize][size[strSize]][i] = str[i];
		size[strSize]++;
	}
	int T, cas = 1; scanf("%d", &T);
	while (T--) {
		scanf("%s", str); n = strlen(str);
		memset(dp,-1,sizeof dp);
		printf("Case #%d: %d\n", cas++, solve(0,-5));
		//test(0,-5);
	}
	return 0;
}