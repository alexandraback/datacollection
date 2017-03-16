#include<cstdio>
#include<cstring>
using namespace std;
int T,TT,x,y,i;
int main(){
	freopen("bb.in","r",stdin);
	freopen("b.out","w",stdout);
	scanf("%d",&TT);
	for(T=1;T<=TT;T++){
		scanf("%d%d",&x,&y);
		printf("Case #%d: ",T);
		if(y>0){
			printf("N");
			for(i=1;i<y;i++)printf("SN");
		}
		if(y<0){
			printf("S");
			y=-y;
			for(i=1;i<y;i++)printf("NS");
		}
		if(x>0){
			for(i=1;i<=x;i++)printf("WE");
		}
		if(x<0){
			x=-x;
			for(i=1;i<=x;i++)printf("EW");
		}
		printf("\n");
	}
}