#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
	//freopen("A-large.in","r",stdin);
	//freopen("out.txt","w",stdout);
	int t,k,i,n,ans,count;
	char s[1010];
	scanf("%d",&t);
	for(k=1;k<=t;k++){
		ans=count=0;
		scanf("%d%s",&n,s);
		for(i=0;i<=n;i++){
			if(count>=i) count+=s[i]-'0';
			else{
				ans+=i-count;
				count=i+s[i]-'0';
			}
		}
		printf("Case #%d: %d\n",k,ans);
	}
 return 0;
}

