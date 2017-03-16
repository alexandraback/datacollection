#include<stdio.h>
#include<algorithm>
using namespace std;
int main(){
	int ca;
	scanf("%d",&ca);
	for(int cas=1;cas<=ca;cas++){
		int X,R,C;
//	for(int R=1;R<=4;R++)
//	for(int C=R;C<=4;C++)
//	for(int X=1;X<=4;X++){
		scanf("%d%d%d",&X,&R,&C);
		if(C<R)swap(C,R);
		printf("Case #%d: ",cas);
		if(R*C%X!=0){
			printf("RICHARD\n");
		}
		else if(X>=min(C,R)*2+1){
			printf("RICHARD\n");
		}
		else if(X<=2||X<=min(R,C)){
			printf("GABRIEL\n");
		}
		else if(X==3&&C==3&&R==2)printf("GABRIEL\n");
		else if(X==4&&C==4&&R==3)printf("GABRIEL\n");
		else if(X==4&&C==2&&R==2)printf("RICHARD\n");
		else if(X==4&&C==4&&R==2)printf("RICHARD\n");
		else printf("%d %d %d\n",X,C,R);
	}
}
