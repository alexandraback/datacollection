#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

bool Check(char ch){
	return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
}

char st[10005]; int N;

int main()
{
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
	int T;
	scanf("%d", &T);
	for (int i = 0; i < T; i ++){
		scanf("%s", st);
		scanf("%d", &N);
		int len = strlen(st), ret = 0;
		for (int i = 0; i < len; i ++){
			for (int j = i + N - 1; j < len; j ++){
				int s = 0;
				for (int k = i; k <= j; k ++)
					if (Check(st[k])) s = 0;
						else {
							s ++;
							if (s >= N) break;
						}
				if (s >= N) ret ++;
			}
		}
		printf("Case #%d: %d\n", i + 1, ret);
	}
	return 0;
}
