#include <bits/stdc++.h>
using namespace std;
int t,cnt=0;
char str[105];
int main(){
	scanf("%d\n",&t);
	for(int c=1;c<=t;c++){
		printf("Case #%d: ",c);
		int cnt=0;
		scanf("%s\n",str);
		int l=strlen(str);
		for(int x=1;x<l;x++) cnt+=(str[x]!=str[x-1]);
		cnt+=(str[l-1]=='-');
		printf("%d\n",cnt);
	}
	return 0;
}
