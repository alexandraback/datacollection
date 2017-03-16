#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
int n,m;
int mat[55],vis[55];
int count1,ans,flag;
void dfs(int ind) {
	if(ind==n) {
		count1++;
		return;
	}
	int mask = mat[ind];
	int i=0;
	while(mask) {
		if(mask%2==1) {
			if(vis[i]==1) {
				ans=-1;
				return;
			}
			vis[i]=1;
			dfs(i);
			if(ans==-1) {
				return;
			}
			vis[i]=0;
		}
		mask=mask/2;
		i++;
	}
}
void func(int ind) {
	if(ind==n) {
		ans=0;
		count1=0;
		for(int i=0;i<=n;i++) {
			vis[i]=0;
		}
		vis[1]=1;
		dfs(1);
		if(ans!=-1) {
			if(count1==m) {
				flag=1;
				return;
			}
		}
		return;
	}
	queue<int> q,q2;
	int mask;
	q.push(0);
	for(int i=ind+1;i<=n;i++) {
		while(!q.empty()){
			q2.push(q.front());
			q.pop();
		}
		while(!q2.empty()) {
			mask = q2.front();
			q2.pop();
			q.push(mask);
			q.push(mask|(1<<i));
		}
	}
	while(!q.empty()) {
		mask = q.front();
		q.pop();
		//cout<<"ind : "<<ind<<"mask: "<<mask<<"\n";
		mat[ind]=mask;
		func(ind+1);
		if(flag==1) {
			return;
		}
	}
}
int main() {
	int t,mask,temp;
	scanf("%d",&t);
	for(int i=1;i<=t;i++) {
		scanf("%d",&n);
		scanf("%d",&m);
		for(int j=0;j<=n;j++) {
			mat[j]=0;
		}
		flag=0;
		func(1);
		printf("Case #%d: ",i);
		if(flag==1) {
			printf("POSSIBLE\n");
			for(int j=1;j<n;j++) {
				mask=mat[j];
				mask=mask/2;
				for(int k=1;k<=n;k++) {
					temp=mask%2;
					printf("%d",temp);
					mask=mask/2;
				}
				printf("\n");
			}
			for(int j=1;j<=n;j++) {
				printf("0");
			}
			printf("\n");
			continue;
		}
		printf("IMPOSSIBLE\n");
	}
	return 0;
}