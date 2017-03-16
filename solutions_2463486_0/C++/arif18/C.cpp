#include<stdio.h>
#include<algorithm>
using namespace std;

int is_pal(int num){

	if(num>=484) return 5;
	if(num>=121) return 4;
	if(num>=9) return 3;
	if(num>=4) return 2;
	if(num>=1) return 1;
	return 0;
}

int main(){
	int n,i,x,y;

//	freopen("C-small-attempt0.in","r",stdin);
//	freopen("C.txt","w",stdout);
	
	
	
	scanf("%d",&n);

	for(i=1;i<=n;i++){
		printf("Case #%d: ",i);

		scanf("%d%d",&x,&y);

		printf("%d\n",is_pal(y)-is_pal(x-1));

	}


return 0;
}
