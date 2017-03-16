#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<map>
#include<set>
#include<vector>
#include<math.h>

char a[110];
int main(){
	int T,n,ans,s,t=0;
	freopen("B-small-attempt0.in","r",stdin);
	freopen("pBout.txt","w",stdout);
	scanf("%d",&T);
	while(T--){
		t++;
		scanf("%s",a);
		printf("Case #%d: ",t);	
		s=strlen(a);
		ans=0;
		for(int k=1;k<s;k++){
			 if(a[k]!=a[k-1]) ans++;
		}
		if(a[s-1]=='-') ans++;
		printf("%d\n",ans);
	}
}
