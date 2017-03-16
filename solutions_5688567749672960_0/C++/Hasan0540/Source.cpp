#include <iostream>
#include <stdio.h>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <string.h>
#include <cmath>
#include <memory.h>
#include <algorithm>
using namespace std;
typedef long long ll;
bool vis[2000001];
int cost[2000001];
int main()
{
	freopen("src.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int qq;
	scanf("%d",&qq);
	queue<int> q;
	q.push(1);
	vis[1]=true;
	cost[1] = 1;
	char str[100];
	int v;
	while(!q.empty()){
		int u=q.front();
		q.pop();
		if(u==2000000)
			continue;
		if(!vis[u+1]){
			vis[u+1]=true;
			cost[u + 1] = cost[u] + 1;
			q.push(u + 1);
		}
		sprintf(str,"%d",u);
		string s=str;
		reverse(s.begin(),s.end());
		sscanf(&s[0], "%d", &v);
		if(v<=2000000 && !vis[v]){
			vis[v]=true;
			cost[v] = cost[u] + 1;
			q.push(v);
		}
	}
	for (int T = 1; T <= qq; ++T){
		int n;
		scanf("%d", &n);
		printf("Case #%d: %d\n", T, cost[n]);
	}
	return 0;
}