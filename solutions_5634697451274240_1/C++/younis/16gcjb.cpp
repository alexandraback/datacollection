#include<cstdio>
#include<cstring>
int main(){
	freopen("B-large.bin","r",stdin);
	freopen("output.txt","w",stdout);
	int t;scanf("%d",&t);
	char s[110];
	int l,i,j,ans;
	for(int cas=1;cas<=t;cas++){
		scanf("%s",s);
		l=strlen(s);
		ans=0;
		for(i=0;i<l;i++)
		if(s[i]=='-'){
			j=i;
			while(j<l&&s[j]=='-')j++;
			if(i)ans+=2;
			else ans++;
			i=j;	
		}
		printf("Case #%d: %d\n",cas,ans);
	}
	return 0;
}
