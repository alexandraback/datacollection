#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef short int si;

int main(){
	freopen("ans.txt","w",stdout);
	freopen("A-large.in","r",stdin);
	
	int t,n,cas=0;
	char s[1005];
	
	scanf("%d",&t);
	
	while(t--){
		scanf("%d",&n);
		
		scanf("%s",&s);
		
		int now=0,ans=0;
		now=s[0]-'0';
		for(int i=1;s[i];++i){
			if(now>=i){
				now+=s[i]-'0';
			}
			else {
				ans+=i-now;
				now+=i-now;
				now+=s[i]-'0';
			}
		}
		printf("Case #%d: %d\n",++cas,ans);
	}
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
