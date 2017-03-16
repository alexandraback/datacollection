#include <stdio.h>

using namespace std;

int t;
int r,c,w;

int main(){
	scanf("%d",&t);
	for(int tt=1;tt<=t;++tt){
		printf("Case #%d:",tt);
		scanf("%d%d%d",&r,&c,&w);
		int res=c%w?c/w*r+w:c/w*r+w-1;
		printf(" %d\n",res);
	}
	return 0;
}
