/*
***************************************************************************************************************

							Author : Yash Sadhwani

**************************************************************************************************************
*/
#include<stdio.h>
#include<iostream>
#include<vector>
#include<string.h>
#include<algorithm>
#include<deque>
#include<map>
#include<set>
#include<stack>
#include<stdlib.h>
#include<math.h>
#include<queue>
#include<functional>
using namespace std;
#define ll long long
#define si(x) scanf("%d",&x)
#define sl(x) scanf("%lld",&x)
#define sc(x) scanf("%c",&x)
#define vl vector<ll>
#define vi vector<int>
#define vvl vector< vl >
#define vvi vector< vi >
#define pb push_back
#define mod 1000000007
#define mem(x,y) memset(x,y,sizeof(x))
#define f(i,a,b) for(int i=(a);i<(b);i++)
#define max_int_value 2147483647
#define max_long_value 9223372036854775807


//qsort(ww,cc,sizeof(tp),compare);
/*int compare(const void *a,const void *b){
	ll y=((((tp*)a)->w)-(((tp*)b)->w));
	if(y>0)return 1;
	else if(y==0)return 0;
	else return -1;
}*/

#define maxn 1000050

int reverse(int x){
	int ret=0;
	int mul=1;
	while(x>0){
		int foo=x%10;
		x/=10;
		ret*=10;
		ret+=foo;
	}
	return ret;
}

int dp[maxn];

int path[maxn];

bool visited[maxn];

void printpath(int x){
	while(x>0){
		cout<<x<<endl;
		x=path[x];
	}
}

void bfs(void){
	queue<int> Q;
	Q.push(1);
	dp[1]=1;
	visited[1]=true;
	while(!Q.empty()){
		int u=Q.front();
		Q.pop();
		int v=reverse(u);
		//cout<<u<<" "<<v<<endl;
		
		if(v<maxn and !visited[v] ){
			visited[v]=true;
			dp[v]=dp[u]+1;
			Q.push(v);
			path[v]=u;
		}
		v=u+1;
		if(v>=maxn)continue;
		if(!visited[v]){
			visited[v]=true;
			dp[v]=dp[u]+1;
			path[v]=u;
			Q.push(v);
		}
	}
}

int N;

inline void ReadInput(void){
	si(N);
}

inline void solve(int turn){
	printpath(N);
	
	cout<<"Case #"<<turn<<": "<<dp[N]<<endl;
}

inline void Refresh(void){
	fill(visited,visited+maxn,false);
}

int main()
{
	Refresh();
	bfs();
	int t; si(t);
	for(int i=1;i<=t;i++){
		ReadInput();
		solve(i);
	}
	return 0;
}
