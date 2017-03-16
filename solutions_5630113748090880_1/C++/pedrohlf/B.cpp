#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <map>
#include <queue>
#include <stdlib.h>
#include <set>
#include <algorithm>
#include <math.h>
#include <stdio.h>
#include <unistd.h>
#include <stack>
#include <sstream>
#include <list>
#include <bitset>
#define ff first
#define ss second

using namespace std;

typedef long long ll;

int vis[2505];


int main() {
	int t,n,tc=1,x,i;
	set<int> ans;

	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		memset(vis,0,sizeof(vis));
		for(i = 1; i < 2*n; i++){
			for(int j = 0; j < n; j++){
				scanf("%d", &x);
				vis[x]++;
			}
		}
		ans.clear();
		for(i = 1; i <= 2500; i++){
			if(vis[i]&1) ans.insert(i);
		}
		printf("Case #%d:", tc++);
		for(int a : ans)
			printf(" %d", a);
		printf(" \n");
	}

	return 0;
}
