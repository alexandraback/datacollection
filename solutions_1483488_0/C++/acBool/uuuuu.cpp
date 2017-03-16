#include <iostream>
#include <string.h>
#include <cstdio>
#include <string>
using namespace std;
int main(){
	//freopen("1.in","r",stdin);
	//freopen("2.txt","w",stdout);
	int T;
	scanf("%d",&T);
	int a,b,kk=0;
	int flag[1005];
	while(T--){
	  scanf("%d%d",&a,&b);
	  memset(flag,0,sizeof(flag));
	  int total=0;
	  for(int i=a;i<=b;++i){
		int ge=0,shi=0,bai=0;
	    ge=i%10;
		shi=i/10%10;
		bai=i/100;  
		if(i>=100){
		   int x=ge*100+bai*10+shi;
		   if(i<x&&x<=b)total++;
		   int y=shi*100+ge*10+bai;
		   if(i<y&&y<=b)total++;
		}
		else if(i>=10&&i<100){
		  int x=ge*10+shi;
		  if(i<x&&x<=b)total++;
		}
	  }
	  printf("Case #%d: %d\n",++kk,total);
	}
	return 0;
}