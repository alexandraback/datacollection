#include <stdio.h>
#include <algorithm>
using namespace std;

main(){
	int cases;
	scanf("%d ",&cases);
	for(int casenum=1;casenum<=cases;casenum++){
		printf("Case #%d: ",casenum);
		int n,s,p;
		scanf("%d%d%d",&n,&s,&p);
		int toukaku=0,wanchan=0;
		int happy=0;
		for(int i=0;i<n;i++){
			int t;
			scanf("%d",&t);
			if(t>28 || t<2){
				if(t>28)happy++;
				if(t==1)if(p==0)happy++;
			}else if(t>=p+p-1+p-1)toukaku++;
			else if((p>=2 && t>=p+p-2+p-2) || (p==1 && t>=1) || p==0)wanchan++;
		}
		printf("%d\n",happy+toukaku+min(wanchan,s));
	}
}