#include<stdio.h>
#include<algorithm>

using namespace std;

int T,x,r,c,win;

int main(){
	int i,j;
	freopen("D-small.in","r",stdin);
    freopen("D-small.out","w",stdout);
//	freopen("D-large.in","r",stdin);
//    freopen("D-large.out","w",stdout);
	scanf("%d",&T);
	for(int t = 1; t <= T;t++){
		scanf("%d%d%d",&x,&r,&c);
		win = 0;
		int minrc = min(r,c);
		if((r * c) % x == 0 && (x + 1)/2 <= minrc){
			if(x <= 3){
				win = 1;
			}else if(x == 4){
				if(minrc != 2)win = 1;
			}
		}
		printf("Case #%d: %s\n",t,win==0?"RICHARD":"GABRIEL");
	}
}
