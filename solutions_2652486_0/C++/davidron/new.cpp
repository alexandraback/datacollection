#include<iostream>
#include<string>
#include<algorithm>
#include<bitset>
#include<cassert>
#include<cstring>
#include<cmath>
#include<cstdio>
#include<queue>
#include<stack>
#include<vector>
#include<ctime>
#include<map>
#include<set> 
#include<cctype>
#include<cstdlib>
using namespace std;
const int INF = 0x3f3f3f3f;
const double eps = 1e-7;
const int maxn = 10000000;
const int maxe = 2*maxn*maxn;
typedef unsigned long long ULL;
///////////////////////////////////////////////////////////////////////////////////
int R,N,M,K,best,num[30],res[30],bres[30];
int sub[78048],pn;
void dfs(int p,int ans){
	if(p == N){
		if(best < ans){
			best = ans;
			for(int j = 0; j < N; ++j) 
				bres[j] = res[j];
		}
		return;
	}
	for(int i = 2; i <= M; ++i){
		int ans2 = ans;
		res[p] = i;
		for(int k = 0; k < K; ++k){
			if(i == num[k] || num[k] == 1) ++ans2;
		}
		int ed = pn;
		sub[pn++] = i;
		for(int j = 0; j < ed; ++j){
			for(int k = 0; k < K; ++k){
				if(sub[j]*sub[j] == num[k] || num[k] == 1){
					++ans2;
				}
				if(sub[j] * i == num[k]||num[k] == 1){
					++ans2;
				}
			}
			sub[pn++] = sub[j] * sub[j];
			sub[pn++] = sub[j] * i;
		}
		dfs(p+1,ans2);
		pn = ed;
	}
}
int main(){
	//freopen("C-small-1-attempt1.in","r",stdin);
	//freopen("out.txt","w",stdout);
	int T;scanf("%d",&T);
	for(int ci = 1; ci <= T; ++ci){
		printf("Case #%d:\n",ci);
		scanf("%d%d%d%d",&R,&N,&M,&K);
		for(int i = 0; i < R; ++i){
			for(int j = 0; j < K; ++j){
				scanf("%d",num+j);
			}
			best = 0;pn = 0;
			dfs(0,0);
			for(int j = 0; j < N; ++j){
				printf("%d",bres[j]);
			}
			puts("");
		}
	}
	return 0;
}