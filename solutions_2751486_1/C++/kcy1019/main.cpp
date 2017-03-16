#include<cstdio>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;

int T, TC;
bool moum[128];
char buf[1000024];
int main()
{
	freopen("a.txt", "r", stdin);
	freopen("b.txt", "w", stdout);

	moum['a'] = moum['e'] = moum['i'] = moum['o'] = moum['u'] = 1;

	for (scanf("%d", &T); T--;) {
		long long ans = 0, N, len;
		scanf("%s%lld", buf, &N);
		len = strlen(buf);
		/*
			Another Fine Solution By kcy1019 (WeissBlume)
		*/
		vector <int> sol;
		sol.push_back(-1);
		int cnt = 0, ptr = 0;
		for (int i = 0; i < len; i++) {
			if (cnt >= N) {
				sol.push_back(ptr);
				++ptr;
			}
			if (moum[buf[i]]) {
				cnt = 0;
				ptr = i + 1;
			}
			else {
				++cnt;
			}
		}
		if (cnt >= N) {
			sol.push_back(ptr);
		}
		for (int i = 1; i < sol.size(); i++) {
			ans += (long long)(sol[i] - sol[i-1]) * (long long)(len - (sol[i] + N) + 1);
		}
		printf("Case #%d: %lld\n", ++TC, ans);
	}
	return 0;
}