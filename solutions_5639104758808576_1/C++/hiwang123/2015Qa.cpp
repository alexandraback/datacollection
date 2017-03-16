#include<stdio.h>
#include<stdlib.h>
#include<vector>
#include<algorithm>
using std::vector;
using std::pair;
using std::make_pair;
using std::sort;
char s[1005];
int main(void){
	int t,hh;
	scanf("%d",&t);
	for(hh=1;hh<=t;hh++){
		int sm,i;
		scanf("%d",&sm);
		scanf("%s",s);
		int tot=0,ans=0;
		tot=int(s[0]-'0');
		for(i=1;i<=sm;i++){
			int d=int(s[i]-'0');
			if(!d) continue;
			if(tot<i){
				int w=i-tot;
				ans+=w;
				tot+=w;
			}
			tot+=d;
		}
		printf("Case #%d: %d\n",hh,ans);
	}
	return 0;
}

