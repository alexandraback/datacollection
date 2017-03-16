#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
char s1[110],s2[110],sss[110];
int k,l,s,cnt,mx,m;

 void DFS(int x)
 {
 	int i,j,c=0;
 	if(x>=s){
 		m++;
 		for(i=1;i<=s-l+1;i++){
 			for(j=1;j<=l;j++){
 				if(sss[i+j-1]!=s2[j]) break;
 			}
 			if(j>l){
 				c++;
 			} 
 		}
 		cnt+=c;
 		mx=max(mx,c);
 		//printf(" %s %d\n",sss+1,c);
 		return;
 	}
 	for(i=1;i<=k;i++){
 		sss[x+1]=s1[i];
 		DFS(x+1);
 	}
 }

 void run()
 {
 	cnt=0;
 	mx=0;m=0;
 	scanf("%d%d%d%s%s",&k,&l,&s,s1+1,s2+1);
 	DFS(0);
 	printf("%.6lf\n",(double)mx-(double)cnt/m);
 }

int main()
{
	freopen("B-small-attempt0.in","r",stdin);
	freopen("out.txt","w",stdout);
	int t,i;
	scanf("%d",&t);
	for(i=1;i<=t;i++){
		printf("Case #%d: ",i);
		run();
	}
 return 0;
}

