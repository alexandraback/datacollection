#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <iostream>
using namespace std;

int n,m,s[60][60],used[60];
//int zip[60];
int q[60];
string zip[60];
string ans;

bool dfs2(int a, int b){
	if(a==b) return true;
	
	bool z = false;
	for(int i=0;i<n && !z;i++){
		if(used[i] || !s[a][i]) continue;
		used[i] = 1;
		z = dfs2(i, b);
		used[i] = 0;
	}
	return z;
}

void dfs(int all, int deg, int now, string str, bool nn){
	q[deg] = now;
	string x;
	if(nn)
		x = str+zip[now];
	else x = str;
	
	//printf("%d %d %d %s\n", all, deg, now, x.c_str());
	if(all == n-1){
		if(x < ans || ans.size()==0)
			ans = x;
		return;
	}
	
	if(nn) used[now] = 1;
	int qq[60];
	for(int j=0;j<=deg;j++)
		qq[j]=q[j];
	if(deg>0)
		dfs(all, deg-1, q[deg-1], x, 0);
	for(int j=0;j<=deg;j++)
		q[j]=qq[j];
	
	for(int i=0;i<n;i++){
		if(s[now][i] && !used[i]){
			dfs(all+1, deg+1, i, x, 1);
		} 
	}
	if(nn) used[now] = 0;
}

int main(void){
    int t;
    scanf("%d",&t);
    for(int tt=1;tt<=t;tt++){
		scanf("%d%d",&n,&m);
		for(int i=0;i<n;i++){
			cin >> zip[i];
		}
//			scanf("%d", zip[i]);
		
		memset(s, 0, sizeof(s));
		memset(used, 0, sizeof(used));
		for(int i=0;i<m;i++){
			int a,b;
			scanf("%d%d", &a,&b);a--;b--;
			s[a][b]=s[b][a]=1;
		}
		
		ans = "";
		string x = "";
		for(int i=0;i<n;i++)
			dfs(0, 0, i, x, 1);
        
        printf("Case #%d: %s\n", tt, ans.c_str());
    }
    return 0;
}

