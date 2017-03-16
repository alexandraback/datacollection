#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <string>
#include <queue>

using namespace std;
#define rep(i,a,b) for (int i=(a);i<=(b);i++)
#define repd(i,a,b) for (int i=(a);i>=(b);i--)

const int maxn=1000020;
char s[maxn];
deque<char> ans;
int n;

int main() {
	freopen("a.out","w",stdout);
	int T;scanf("%d\n",&T);
	rep(t,1,T) {
		printf("Case #%d: ",t);
		n=strlen(gets(s+1));
		ans.clear();
		ans.push_back(s[1]);
		rep(i,2,n) {
			if (s[i]>=ans[0])
				ans.push_front(s[i]);
			else ans.push_back(s[i]);
		}
		rep(i,0,n-1)
			printf("%c",ans[i]);
		puts("");
	}
	return 0;
}
