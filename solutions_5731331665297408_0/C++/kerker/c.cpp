#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

string zip[10],now;
vector <int> v[10];
int s[10][10];
int a[10],vis[10],N;
int ok, all_pos;

void dfs(int x,int lv){
	vis[x] = 1;
	if(all_pos==N)	return;
	//printf("x = %d, %d, lv = %d\n",x,all_pos,lv);
	/*if(s[x][a[all_pos]]==1){
		dfs(a[all_pos++],lv+1);
	}else{
		return ;
	}*/
	while(vis[a[all_pos]]==0){
		if(s[x][a[all_pos]]==1){
			dfs(a[all_pos++],lv+1);
		}else	return;
	}
}

int main()
{
    freopen("C-small-attempt1.in","r",stdin);
	//freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    
    int T;
	cin >> T;
	for(int t=0;t<T;t++){
		int M;
		cin >> N >> M;
		memset(s,0,sizeof(s));
		for(int i=1;i<=N;i++)
			cin >> zip[i];
		for(int i=0;i<=N;i++)
			v[i].clear();
		for(int i=0,x,y;i<M && cin >> x >> y;i++)
			v[x].push_back(y), v[y].push_back(x), s[x][y] = s[y][x] = 1;
		
		for(int i=0;i<N;i++)	a[i] = i+1;
		string ans = "";
		do{
			now = "";
			for(int i=0;i<N;i++)
				now += zip[a[i]];
			//if(ans!="" && now>=ans)	continue;
			memset(vis,0,sizeof(vis));
			ok = 1;
			all_pos = 1;
			dfs(a[0],1);
			for(int i=0;i<N;i++)
				if(vis[a[i]]==0)
					ok = 0;
			if(all_pos==N){
				if(ans=="")	ans = now;
				else if(now<ans){
					ans = now;
				}
			}
		}while(next_permutation(a,a+N));
		cout << "Case #" << t+1 << ": " << ans << endl;
	}
    
    return 0;
}