#define FOR(i,n) for (int i=0; i<n; i++)
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string>

using namespace std;
long long rev(long long n) {
	char str[20];
	sprintf(str, "%lld", n);
	reverse(str, str + strlen(str));
	
	long long ret;
	sscanf(str, "%lld", &ret);
	return ret;
}

int main(void) {
	freopen("c:\\input.txt", "r", stdin);
	freopen("c:\\output.txt", "w", stdout);

	int n; scanf("%d", &n);
	FOR(i, n) {
		long long now; scanf("%lld", &now);
		long long cnt = 0;
		char str[20];
		while (now > 20) {
			sprintf(str, "%lld", now);
			int len = strlen(str);
			int cutcnt = (len + 1) / 2;

			if (str[0] == '1') {
				long long divider = 1;
				FOR(j, cutcnt) divider *= 10;
				long long reminder = now % divider;

				if (reminder == 0) {
					now -= 1;
					cnt += 1;
				}
				else if (reminder == 1) {
					if (rev(now) < now) {
						now = rev(now);
						cnt++;
					}
					else {
						now -= 2;
						cnt += 2;
					}
				}
				else {
					now -= reminder - 1;
					cnt += reminder - 1;
				}
			}
			else {
				
				long long divider = 1;
				FOR(j, cutcnt) divider *= 10;

				long long reminder = now % divider;
				if (reminder == 0) {
					now -= 1;
					cnt += 1;
				}
				else {
					now -= reminder - 1;
					cnt += reminder - 1;
					now = rev(now); cnt++;
				}

			}
		}
		printf("Case #%d: %d\n", i + 1, cnt+now);
	}

	
	return 0;
}
