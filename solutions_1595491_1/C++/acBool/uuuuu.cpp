#include <iostream>
#include <cstdio>
#include <string.h>
using namespace std;
int num[3];
int main(){
	//freopen("1.in","r",stdin);
	//freopen("2.txt","w",stdout);
	int T,n,s,p,sum[105],numsprise,total,kk=0;
	scanf("%d",&T);
	while(T--){
	  memset(sum,0,sizeof(sum));
	  numsprise=0;
	  total=0;
	  scanf("%d%d%d",&n,&s,&p);
	  for(int i=0;i<n;++i){
		  scanf("%d",&sum[i]);
		  num[0]=p;num[1]=p-2;num[2]=p-2;
		  if(p>sum[i])continue;
		  if((num[0]+num[1]+num[2]==sum[i])||(num[0]+num[1]+1+num[2]==sum[i])){
			  if(numsprise<s){
			      numsprise++;
				  total++;
			  }
		  }
		  else if(num[0]+num[1]+num[2]+1<sum[i])
			  total++;
	  }
	  printf("Case #%d: %d\n",++kk,total);
	}
	return 0;
}