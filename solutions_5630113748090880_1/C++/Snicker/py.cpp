#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <set>
#include <vector>
#include <string>
#include <map>

using namespace std;

char str[100010];
int num[251000];
vector<int>val;
int main(int argc, char const *argv[])
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int T = 0;
	int cas = 0;
	scanf("%d", &T);
	while(T--) {
		cas++;
		printf("Case #%d:", cas);
		int n;
		scanf("%d", &n);
		int cnt = 0;
		for(int i = 0; i < 2 * n - 1; i++) {
			for(int j = 0; j < n; j++) {
				scanf("%d", &num[cnt++]);	
			}
		}
		sort(num, num + cnt);
		int tmp = 0;
		num[cnt] = -1;
		for(int i = 0; i <= cnt; i++) {
			if(i != 0 && num[i] != num[i - 1]) {
				if(tmp & 1) {
					printf(" %d", num[i - 1]);
				}
				tmp = 0;
			}
			tmp++;
		}
		puts("");
	}
	return 0;
}