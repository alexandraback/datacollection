#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
char s[1010];
int n, len;
char xd[] = "aeiou";
int test(int l, int r){
	int now = 0, ret = 0;
	for(int i = l; i <= r; ++i){
		if(strchr(xd, s[i])==NULL){
			now++;
		}
		else now = 0;
		ret = max(now, ret);
	}
	return ret;
}
int main(){
	int T;
	scanf("%d", &T);
	for(int kase = 1; kase <= T; ++kase){
		scanf("%s%d", s, &n);
		len = strlen(s);
		int ans = 0;
		for(int i = 0; i < len; ++i)
			for(int j = i; j < len; ++j)
				if(test(i,j)>=n)
					ans++;
		printf("Case #%d: %d\n", kase, ans);
	}
	return 0;
}
