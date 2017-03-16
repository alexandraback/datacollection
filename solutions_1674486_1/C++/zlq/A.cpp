#include <cstdio>
#include <cmath>
#include <string>
#include <cstring>
#include <cstdlib>
#include <utility>
#include <sstream>
#include <set>
#include <map>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1005;

bool w[N][N];
int n, m, T, Case = 0, dis[N], q[N];

bool check(int s) {
	int head, tail, u;	
	head = tail = 0;
	q[0] = s;
	memset(dis, -1, sizeof(dis));
	dis[s] = 0;
	while(head <= tail) {
		u = q[head++];
		for(int i = 1; i <= n; i++) {
			if(w[u][i]) {
				if(dis[i] == -1) {
					dis[i] = dis[u] + 1;
					q[++tail] = i;
				}
				else if(i != s) 
					return  true;
			}
		}
	}
	return  false;
}

int main(){
	int x;
	freopen("data.in", "r", stdin);
	freopen("data.out", "w", stdout);
	scanf("%d", &T);
	while(T--) {
		scanf("%d", &n);
		memset(w, false, sizeof(w));
		for(int i = 1; i <= n; i++) {
			scanf("%d", &m);
			for(int j = 1; j <= m; j++) {
				scanf("%d", &x);
				w[i][x] = true;
			}
		}
		bool flag = false;
		for(int i = 1; i <= n; i++)
			if(check(i)) {
				flag = true;
				break;
			}
		if(flag)  printf("Case #%d: Yes\n", ++Case);
		else  printf("Case #%d: No\n", ++Case);
	}
	return  0;
}










