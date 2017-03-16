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
int main(int argc, char const *argv[])
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int T = 0;
	int cas = 0;
	scanf("%d", &T);
	while(T--) {
		cas++;
		printf("Case #%d: ", cas);
		scanf("%s", str);
		int len = strlen(str);
		string ans = "";
		char now;
		for(int i = 0; i < len; i++) {
			if(i == 0) {
				ans += str[i];
				now = str[i];
				continue;
			}
			if(str[i] >= now) {
				now = str[i];
				string tmp = "";
				tmp += now;
				ans = tmp + ans;
			} else {
				ans += str[i];
			}
		}
		printf("%s\n", ans.c_str());
	}
	return 0;
}