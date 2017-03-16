#include<stdio.h>
#include<stdlib.h>
#include<vector>
#include<algorithm>
using std::vector;
using std::pair;
using std::make_pair;
using std::sort;
char ss[10005];
int s[10005];
int curr[10005];
int acurr[5];
int curr2[10005];
int map[4][4]={
	{1,2,3,4},
	{2,-1,4,-3},
	{3,-4,-1,2},
	{4,3,-2,-1},
};
int abs(int a){
	return a<0?-a:a;
}
int mul(int a,int b){
	if(a*b<0) return -map[abs(a)-1][abs(b)-1];
	else return map[abs(a)-1][abs(b)-1];
}
int main(void){
	int t,hh;
	scanf("%d",&t);
	for(hh=1;hh<=t;hh++){
		int l;
		long long int x;
		scanf("%d%lld",&l,&x);
		scanf("%s",ss);
		int i,j;
		for(i=0;i<l;i++){
			if(ss[i]=='i') s[i]=2;
			if(ss[i]=='j') s[i]=3;
			if(ss[i]=='k') s[i]=4;
		}
		curr[0]=s[0];
		for(i=1;i<l;i++)
		  curr[i]=mul(curr[i-1],s[i]);
		acurr[1]=curr[l-1];
		for(i=2;i<=4;i++)
		  acurr[i]=mul(acurr[i-1],curr[l-1]);
		
		curr2[l-1]=s[l-1];
		for(i=l-2;i>=0;i--)
		  curr2[i]=mul(s[i],curr2[i+1]);
		  
		int pi=-1,pk=-1;
		for(j=0;j<4&&j<x&&pi==-1;j++)
		  for(i=0;i<l;i++){
			  int d;
			  if(j==0) d=curr[i];
			  else d=mul(acurr[j],curr[i]);
			  if(d==2){
			  	pi=j*l+i+1;
			  	break;
			  }
		  }
		for(j=0;j<4&&j<x&&pk==-1;j++)
		  for(i=l-1;i>=0;i--){
			  int d;
			  if(j==0) d=curr2[i];
			  else d=mul(curr2[i],acurr[j]);
			  if(d==4){
			  	pk=j*l+(l-1-i)+1;
			  	break;
			  }
		  }
		
	//	printf("%d %d\n",pi,pk);
		
		int rr=(x-1)%4+1;
		if(pi!=-1&&pk!=-1&&acurr[rr]==-1&&pi+pk<x*l) printf("Case #%d: YES\n",hh);
		else printf("Case #%d: NO\n",hh);
	}
	return 0;
}

