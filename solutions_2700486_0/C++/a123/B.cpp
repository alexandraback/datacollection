#include<cstdio>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<map>
#include<sstream>
using namespace std;
double ans;
void dfs(int stage,int remain,int y,int L,int R,double prob){
	if(L+R==remain){
		if(R>y)
			ans+=prob;
		return;
	}
	if(L==stage)
		dfs(stage,remain,y,L,R+1,prob);
	else if(R==stage)
		dfs(stage,remain,y,L+1,R,prob);
	else{
		dfs(stage,remain,y,L+1,R,prob*0.5);
		dfs(stage,remain,y,L,R+1,prob*0.5);
	}
}
int main(){
	int C;
	scanf("%d",&C);
	for(int Case=1; Case<=C; Case++){
		int stage=0;
		int remain,x,y;
		scanf("%d%d%d",&remain,&x,&y);
		int now=1;
		while(remain>now){
			remain-=now;
			stage+=2;
			now+=4;
		}
		if(x<0)
			x=-x;
		printf("Case #%d: ",Case);
		if(stage>x+y)
			printf("%lf\n",1.0);
		else if(stage<x+y)
			printf("%lf\n",0.0);
		else{
			if(x==0){
				if(remain == now)
					printf("%lf\n",1.0);
				else printf("%lf\n",0.0);
			}else{
				ans=0.0;
				dfs(stage,remain,y,0,0,1.0);
				printf("%lf\n",ans);
			}
		}
	}
}

