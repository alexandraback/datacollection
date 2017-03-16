#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;

int main(){
	int time=0, t, n, star[1005][2], vis[1005][2], i, now, ans, f;
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		for(i=0; i<n; i++){
			scanf("%d%d", &star[i][0], &star[i][1]);
			vis[i][0]=vis[i][1]=0;
		}
		for(now=ans=0; ;){
			f=0;
			for(i=0; i<n&&!f; i++)
				if(!vis[i][1]&&star[i][1]<=now){
					//printf("now = %d, complete %d,2\n", now, i);
					f=1;
					vis[i][1]=1;
					now++;
					ans++;
					if(!vis[i][0]){
						vis[i][0]=1;
						now++;
					}
				}
			for(i=0; i<n&&!f; i++)
				if(!vis[i][0]&&star[i][0]<=now){
					//printf("now = %d, complete %d,1\n", now, i);
					f=1;
					vis[i][0]=1;
					now++;
					ans++;
				}
			if(!f) break;
		}
		if(now==2*n)
			printf("Case #%d: %d\n", ++time, ans);
		else
			printf("Case #%d: Too Bad\n", ++time);
	}
	return 0;
}
