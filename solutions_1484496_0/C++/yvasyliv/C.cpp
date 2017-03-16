#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <ctime>
#include <cmath>
#include <stdio.h>
#include <set>
#include <map>
#include <stack>
#include <fstream>
#include <list>

#define SZ(a) (int(a.size()))
#define MEM(a, val) memset(a, val, sizeof(a))

typedef unsigned long long ULL;
typedef long long LL;
typedef long double dbl;

using namespace std;

int n;
int f[509];
bool col[100001 * 21];
int fr[100001 * 21];
int S;
vector<int> ans;
bool vuvid(int p) {
	
	while (p > 0) {
		ans.push_back(fr[p]);
		p -= fr[p];
	}
	printf("%d", ans[0]);
	for (int i = 1; i < ans.size(); ++i) {
		printf(" %d", ans[i]);
	}
	printf("\n");
	return false;
}

bool find_ans() {
	for (int i = 0; i < n; ++i) {
		for (int j = S; j >= 1; --j) {
			if (j - f[i] >= 0 && col[j - f[i]] == true) {
				if (col[j] == true) {
					ans.clear();
					vuvid(j);
					ans.clear();
					//printf("%d ", f[i]);
					ans.push_back(f[i]);
					vuvid(j - f[i]);
					return true;
				}
				else {
					col[j] = true;
					fr[j] = f[i];
				}
			}
		}
	}
	return false;
}

int main()
{
	//freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
	int T;
	scanf("%d", &T);
	for (int I = 1; I <= T; ++I) {
		
		scanf("%d", &n);
		S = 0;
		for (int i = 0; i < n; ++i) {
			scanf("%d", &f[i]);
			S += f[i];
		}
		MEM(col, false);
		col[0] = true;
		printf("Case #%d:\n", I);
		if (find_ans()) {

		} else {
			printf("Impossible\n");
		}
	}
	return 0;
}