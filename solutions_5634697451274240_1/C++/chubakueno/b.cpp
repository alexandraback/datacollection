#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
char str[1000];
int main(){
	int t;
	scanf("%d",&t);
	for(int z=1;z<=t;++z){
		memset(str,0,sizeof str);
		scanf("%s",str);
		printf("Case #%d: ",z);
		int n=strlen(str);
		str[n]='+';
		int ans=0;
		for(int i=1;i<=n;++i)
			if(str[i-1]!=str[i]) ++ans;
		printf("%d\n",ans);
	}
}