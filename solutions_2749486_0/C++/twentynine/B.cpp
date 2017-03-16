#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main(){
//freopen("B-small-attempt0.in","r",stdin);
//freopen("B-small-attempt0.out","w",stdout);
int x,y,tc,ii,j,i,k;
scanf("%d",&tc);
for(ii=1;ii<=tc;ii++){
	scanf("%d %d",&x,&y);
	printf("Case #%d: ",ii); 
	if(x>0){
		for(i=1;i<=x;i++)printf("WE");
	}
	if(x<0){
		for(i=1;i<=-x;i++)printf("EW");
	}
	if(y>0){
		for(i=1;i<=y;i++)printf("SN");
	}
	if(y<0){
		for(i=1;i<=-y;i++)printf("NS");
	}
	printf("\n");
}
	//system("pause");
	
	
	return 0;
}
	
