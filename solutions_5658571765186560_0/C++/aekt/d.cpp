#include <cstdio>

int t,T,x,r,c;
bool g;
int main(){
	scanf("%d",&T);
	for(t=1;t<=T;t++){
		scanf("%d%d%d",&x,&r,&c);
		if(r==1&&c==1)g=(x==1);
		if(r==1&&c==2)g=(x<=2);
		if(r==1&&c==3)g=(x==1);
		if(r==1&&c==4)g=(x<=2);
		if(r==2&&c==1)g=(x<=2);
		if(r==2&&c==2)g=(x<=2);
		if(r==2&&c==3)g=(x!=4);
		if(r==2&&c==4)g=(x<=2);
		if(r==3&&c==1)g=(x==1);
		if(r==3&&c==2)g=(x!=4);
		if(r==3&&c==3)g=(x%2);
		if(r==3&&c==4)g=1;
		if(r==4&&c==1)g=(x<=2);
		if(r==4&&c==2)g=(x<=2);
		if(r==4&&c==3)g=1;
		if(r==4&&c==4)g=(x!=3);
		printf("Case #%d: %s\n",t,g?"GABRIEL":"RICHARD");
	}
	return 0;
}
