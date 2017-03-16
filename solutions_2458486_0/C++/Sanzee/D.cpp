// Author : Muhammad Rifayat Samee
// Problem : D
// Algorithm:
#pragma warning (disable : 4786)
#pragma comment(linker, "/STACK:16777216")

#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<cctype>
#include<cstring>
#include<algorithm>
#include<string>
#include<set>
#include<vector>
#include<map>
#include<queue>
#include<stack>
#define MAX(a,b) (a>b)?a:b
#define MIN(a,b) (a<b)?a:b
#define INF 987654321
#define pi (2*acos(0.0))
#define eps 1e-7

#ifdef ONLINE_JUDGE
#define i64 long long
#else
#define i64 __int64
#endif

using namespace std;
struct Node{
	int wh;
	int tot;
	int k[45];
}N[25];

struct state{
	int mask;
	int key[45];
};
int n,k;
int K[205];
int kid[205];
int id[205],tt;
int memo[1<<20];
int done[1<<20],cc=1;
int prev[1<<20];
int dp(int mask){
	
	if((mask == ((1<<n)-1))){
		return 1;
	}
	if(done[mask] == cc)
		return memo[mask];
	int i,j,res = 0;
	int kk[25];
	memset(kk,0,sizeof(kk));
	if(mask == 0){
		for(i=1;i<=200;i++){
			if(K[i]!=0 && id[i]>=0){
				kk[id[i]] = kk[id[i]] + K[i];
			}
		}
	}
	else{
		for(i=1;i<=200;i++){
			if(K[i]!=0 && id[i]>=0){
				kk[id[i]] = kk[id[i]] + K[i];
			}
		}
		for(i=0;i<n;i++){
			if(mask & (1<<i)){
				for(j=0;j<N[i].tot;j++){
					if(id[N[i].k[j]]>=0)
						kk[id[N[i].k[j]]] = kk[id[N[i].k[j]]]++;
				}
				kk[N[i].wh]--;
			}
		}
	}
	int r,c=0;
	for(i=0;i<n;i++){
		if((mask & (1<<i)) == 0 && kk[N[i].wh]>0){
			r = dp(mask | (1<<i));
			res = res | r;
			if(r == 1 && c==0){
				prev[mask|(1<<i)] = i;
				c++;
				break;
			}
			res = res | r;
		}
	}
	done[mask] = cc;
	memo[mask] = res;
	return res;
}
void printit(){
	stack<int>S;
	int mask = ((1<<n) - 1);
	while(mask!=0){
		S.push(prev[mask]);
		mask &= ~(1 << prev[mask]);
	}
	int u;
	while(!S.empty()){
		printf(" %d",S.top()+1);
		S.pop();
	}
	printf("\n");
}
int main(){

	//freopen("D.in","r",stdin);
	//freopen("D.out","w",stdout);
	int cases,i,j,num,tot,ct=1;
	scanf("%d",&cases);
	while(cases--){
		scanf("%d %d",&k,&n);
		memset(K,0,sizeof(K));
		for(i=0;i<k;i++){
			scanf("%d",&num);
			K[num]++;
		}
		memset(kid,0,sizeof(kid));
		memset(id,-1,sizeof(id));
		for(i=0;i<n;i++){
			scanf("%d %d",&num,&tot);
			kid[num] = 1;
			N[i].wh = num;
			N[i].tot = tot;
			for(j=0;j<tot;j++){
				scanf("%d",&N[i].k[j]);
			}
		}
		tt = 0;
		for(i=1;i<=200;i++){
			if(kid[i] !=0){
				id[i] = tt;
				tt++;
			}
		}
		for(i=0;i<n;i++){
			N[i].wh = id[N[i].wh];
		}
		int res = dp(0);
		//printf("%d\n",dp(0));
		cc++;
		printf("Case #%d:",ct++);
		if(res==0)
			printf(" IMPOSSIBLE\n");
		else{
			printit();
		}
	}

	return 0;
}
