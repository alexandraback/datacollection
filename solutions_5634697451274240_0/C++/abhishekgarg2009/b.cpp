#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
char str[105];
int main() {
	int t,ans;
	char last;
	scanf("%d",&t);
	for(int i=1;i<=t;i++) {
		scanf("%s",str);
		if(strlen(str)==1) {
			if(str[0]=='-') {
				ans=1;
			} else {
				ans = 0;
			}
		} else {
			ans=0;
			last = str[0];
			for(int j=1;j<strlen(str);j++) {
				if(str[j]!=last) {
					ans++;
					last=str[j];
				}
			}
			if(last=='-') {
				ans++;
			}
		}
		printf("Case #%d: %d\n",i,ans);
	}
	return 0;
}