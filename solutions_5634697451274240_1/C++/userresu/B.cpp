#include <cstdio>
#include <cstring>
using namespace std;

int T;
char s[101];
int main() {
	scanf("%d",&T);
	for (int z=1;z<=T;++z) {
		scanf("%s",s);
		int n = strlen(s);
		int last = -1, cnt = 0;
		for (int i=0;i<n;++i) if (s[i] != last) ++cnt, last=s[i];
		if (s[n-1] == '+') --cnt;
		printf("Case #%d: %d\n",z, cnt);
	}
	return 0;
}
