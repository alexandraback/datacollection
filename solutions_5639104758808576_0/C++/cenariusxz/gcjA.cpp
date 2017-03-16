#include<stdio.h>
#include<string.h>

int s[1005];

int main(){
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int t;
	scanf("%d",&t);
	for(int q=1;q<=t;q++){
		int n;
		scanf("%d",&n);
		char c=getchar();
		while(c>'9'||c<'0')c=getchar();
		int t=0,ans=0,i=0;
		while(c<='9'&&c>='0'){
			if(t<i){
				ans+=i-t;
				t=i;
			}
			t+=c-'0';
			c=getchar();
			i++;
		}
		printf("Case #%d: %d\n",q,ans);
	}
	return 0;
}
