#include <iostream>
#include <algorithm>
using namespace std;
#define N 101
int main(){
	//freopen("A-small-practice.in","r",stdin);
	//freopen("A-small-practice.out","w",stdout);
	int x,y,i,j,t,xx;
	scanf("%d",&t);
	for(x=0;x<t;x++)
	{
		scanf("%d%d",&xx,&y);
		printf("Case #%d: ",x+1);
		while(xx){
			if(xx>0){printf("WE");xx--;}
			else{printf("EW");xx++;}
		}
		while(y){
			if(y>0){printf("SN");y--;}
			else{printf("NS");y++;}
		}
		printf("\n");

	}
	return 0;
}