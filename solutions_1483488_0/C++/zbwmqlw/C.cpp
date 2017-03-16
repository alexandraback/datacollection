#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

char s[100];
int T, A, B;
pair<int, int> answer[20000000];
int n;

void work()
{
	int A, B;
	scanf("%d%d", &A, &B);
	int ret = 0;
	for (int i = 1; i <= n; ++i) ret += (answer[i].first >= A && answer[i].second >= A && answer[i].first <= B && answer[i].second <= B);
	static int ttt = 0;
	printf("Case #%d: %d\n", ++ttt, ret / 2);
}

int main()
{
	for (int i = 1; i <= 2000000; ++i) {
		sprintf(s, "%d", i);
		int l = strlen(s);
		int anslist[10];
		anslist[0] = 0;
		for (int iter = 0; iter < l; ++iter) {
			char t = s[0];
			memmove(s, s + 1, (l - 1) * sizeof(char));
			s[l - 1] = t;
			int target = 0;
			for (int j = 0; j < l; ++j)
				target = target * 10 + s[j] - 48;
			if (s[0] != '0' && target != i) anslist[++anslist[0]] = target;
		}
		sort(anslist + 1, anslist + anslist[0] + 1);
		anslist[0] = unique(anslist + 1, anslist + anslist[0] + 1) - (anslist + 1);
		for (int j = 1; j <= anslist[0]; ++j)
			answer[++n] = make_pair(i, anslist[j]);
	}
	scanf("%d\n", &T);
	while (T--) work();
}
	
	