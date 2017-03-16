#include <stdlib.h>
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <queue>
using namespace std;

const int INF=1e9;

int ans[1000010];

int inv(int x){
	int tmp[10];
	int m=0;
	int last=0;
	while(x){
		tmp[m++]=x%10;
		if(x%10){
			last=m;
		}
		x/=10;
	}
	int re=0;
	for(int i=0;i<m;i++){
		re+=tmp[i];
		re*=10;
	}
	re/=10;
	return re;
}

int main(){
	
	freopen("A-small-attempt0.in","r",stdin);
	
	freopen("A-small-attempt0.out","w",stdout);
	
	ans[1]=1;
	queue<int>que;	que.push(1);
	while(!que.empty()){
		int cur=que.front();	que.pop();
		int a=cur+1;
		if(a<=1000000&&!ans[a]){
			ans[a]=ans[cur]+1;
			que.push(a);
		}
		int b=inv(cur);
		if(b<=1000000&&!ans[b]){
			ans[b]=ans[cur]+1;
			que.push(b);
		}
	}
	
	int t;
	cin>>t;
	int cas=0;
	while(t--){
		cas++;
		int n;
		cin>>n;
		printf("Case #%d: %d\n",cas,ans[n]);
	}
	return 0;
}
