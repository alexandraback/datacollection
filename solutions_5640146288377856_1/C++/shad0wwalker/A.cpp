#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

 void run()
 {
 	int r,c,w,tmp;
 	scanf("%d%d%d",&r,&c,&w);
 	printf("%d\n",c/w*r+w-((c%w)==0));
 }

int main()
{
	freopen("A-large.in","r",stdin);
	freopen("out.txt","w",stdout);
	int t,i;
	scanf("%d",&t);
	for(i=1;i<=t;i++){
		printf("Case #%d: ",i);
		run();
	}
 return 0;
}

