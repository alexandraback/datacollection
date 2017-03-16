#include<cstdio>
using namespace std;
int main(){
	char s[1000];
	int T;
	scanf("%d",&T);
	for(int cs=1;cs<=T;cs++){
		int ans=0,j;
		scanf("%s",s);
		for(j=1;s[j];j++){
			if(s[j]!=s[j-1]) ans++;
		}
		if(s[j-1]=='-') ans++;
		printf("Case #%d: %d\n",cs,ans);
	}
	return 0;
}