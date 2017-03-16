#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<string>
#include<stack>
#include<cstdio>
#include<cmath>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> P;
typedef pair<int,P> P1;

#define fr first
#define sc second
#define mp make_pair
#define pb push_back
#define rep(i,x) for(int i=0;i<x;i++)
#define rep1(i,x) for(int i=1;i<=x;i++)
#define rrep(i,x) for(int i=x-1;i>=0;i--)
#define rrep1(i,x) for(int i=x;i>0;i--)
#define sor(v) sort(v.begin(),v.end())
#define rev(s) reverse(s.begin(),s.end())
#define lb(vec,a) lower_bound(vec.begin(),vec.end(),a)
#define ub(vec,a) upper_bound(vec.begin(),vec.end(),a)
#define uniq(vec) vec.erase(unique(vec.begin(),vec.end()),vec.end())
#define mp1(a,b,c) P1(a,P(b,c))

const int INF=1000000000;
const int dir_4[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
const int dir_8[8][2]={{1,0},{1,1},{0,1},{-1,1},{-1,0},{-1,-1},{0,-1},{1,-1}};

int f(int x){
	int a[7] = {};
	rep(i,7){
		a[i] = x%10;
		x /= 10;
	}
	int ret = 0;
	int t = 1;
	rrep(i,7){
		ret += a[i]*t;
		t *= 10;
	}
	while(ret%10 == 0)ret /= 10;
	return ret;
}

int main(){
	static int d[1000010];
	static bool used[1000010];
	rep(i,1000010){
		d[i] = i+10;
		used[i] = false;
	}
	
	queue<int> que;
	d[1] = 1; used[1] = true;
	que.push(1);
	while(!que.empty()){
		int p = que.front(); que.pop();
		if(p > 1000000)continue;
		if(!used[p+1]){
			d[p+1] = d[p] + 1;
			used[p+1] = true;
			que.push(p+1);
		}
		int nex = f(p);
		if(!used[nex]){
			d[nex] = d[p] + 1;
			used[nex] = true;
			que.push(nex);
		}
	}
	
	int t;
	scanf("%d",&t);
	rep1(ppp,t){
		int n;
		scanf("%d",&n);
		printf("Case #%d: %d\n",ppp,d[n]);
	}
}
