#include <stdio.h>
#include <iostream>
#include <memory.h>
#include <algorithm>
#include <string>
#include <string.h>
#include <vector>
#include <map>
#include <set>
using namespace std;

char s[1000000 + 5];
bool isA(char x){
	if(x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u') return true;
	else return false;
}
typedef __int64 LL;
int cnt[1000000 + 5];
int main(){
	int T,cas = 0;
	freopen("A-large.in","r",stdin);
	freopen("A-large.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		scanf("%s",&s);
		int n;
		scanf("%d",&n);
		int L = strlen(s);
		cnt[0] = 0;
		LL ans = 0;
		int cur = 0;
		for(int i = 1;i <= L;i++) {
			if(isA(s[i-1])){
				cnt[i] = cnt[i-1];
			}else cnt[i] = cnt[i-1] + 1;
			if(i >= n && cnt[i] - cnt[i-n] == n) {
				cur = i - n + 1;
			}
			ans += cur;
		}
		printf("Case #%d: %I64d\n",++cas,ans);
	}
}