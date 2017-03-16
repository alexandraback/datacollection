#include<cstdio>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;

int T, TC;
bool moum[128];

int main()
{
	freopen("a.txt", "r", stdin);
	freopen("b.txt", "w", stdout);

	moum['a'] = moum['e'] = moum['i'] = moum['o'] = moum['u'] = 1;

	for (scanf("%d", &T); T--;) {
		int ans = 0, N, len;
		char buf[1024] = "";
		scanf("%s%d", buf, &N);
		len = strlen(buf);
		for (int i = 0; i < len; i++) {	// starting from i, length of j, iterated by k.

			for (int j = 1 ; j <= len; j++) {
				if ( i + j - 1 >= len ) break;
				int cnt = 0;
				for (int k = i; k < i + j; k++) {
					// begin
					if (moum[buf[k]]) {
						if (cnt >= N) {
							//++ans;
							goto hell;
						}
						cnt = 0;
					}

					else {
						++cnt;
					}
					// end
				}
				hell:;
				if (cnt >= N) ++ans;
			}



		}
		printf("Case #%d: %d\n", ++TC, ans);
	}
	return 0;
}