#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

#define getmid(l,r) ((l) + ((r) - (l)) / 2)
#define MEM(a,b) memset(a,b,sizeof(a))
#define MP(a,b) make_pair(a,b)
#define PB push_back
#define X first
#define Y second

const double eps = 1e-8;
const double pi = acos(-1.0);
const int MAXN = 1500;
const int INF = 0x3f3f3f3f;

int T,N;
int F[MAXN];
int ans;
int dis[MAXN],tmax[MAXN];

int Solve(int st){
	memset(dis,0,sizeof(dis));
	int p = st;
	dis[st] = 1;
	while(1){
		if(dis[F[p]] != 0){
			if(dis[p] == dis[F[p]] + 1){
				tmax[F[p]] = max(tmax[F[p]],dis[F[p]] - 1);
				//printf("%d -> %d %d %d\n",p,F[p],dis[p],dis[F[p]]);
			}
			return dis[p] - dis[F[p]] + 1;
		}
		dis[F[p]] = dis[p] + 1;
		p = F[p];
	}
	return 0;
}

int main(){
	freopen("C-large.in","r",stdin);
	freopen("Clarge.txt","w",stdout);
	scanf("%d",&T);
	for(int tt = 1; tt <= T; ++tt){
		memset(tmax,0,sizeof(tmax));
		scanf("%d",&N);
		for(int i = 1; i <= N; ++i){
			scanf("%d",&F[i]);
		}
		ans = 0;
		for(int i = 1; i <= N; ++i){
			ans = max(ans,Solve(i));
		}
		//for(int i = 1; i <= N; ++i){
		//	printf("tmax[%d] : %d\n",i,tmax[i]);
		//}
		int res = 0;
		for(int i = 1; i <= N; ++i){
			for(int j = i + 1; j <= N; ++j){
				if(F[i] == j && F[j] == i){
					//printf("aa %d %d\n",i,j);
					res += tmax[i] + tmax[j] + 2;
				}
			}
		}
		printf("Case #%d: ",tt);
		printf("%d\n",max(res,ans));
	}
    return 0;
}