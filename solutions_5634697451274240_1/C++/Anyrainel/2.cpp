#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
int main()
{
	int T, len, ans;
	char s[103];
	scanf("%d", &T);
	for(int kase = 1; kase <= T; kase++){
		scanf("%s", s);
		len = strlen(s);
		ans = 0;
		for(int i = 1; i < len; i++)
			if(s[i] != s[i-1])
				ans++;
		if(s[len-1]=='-')
			ans++;
		printf("Case #%d: %d\n", kase, ans);
	}
	return 0;
}