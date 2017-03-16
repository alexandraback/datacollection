#include<vector>
#include<cmath>
#include<map>
#include<cstdlib>
#include<iostream>
#include<sstream>
#include<fstream>
#include<string>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<set>
#include<stack>
#include<bitset>
#include<functional>
#include<ctime>
#include<queue>
#include<deque>
#include<complex>
using namespace std;
#define pb push_back
#define pf push_front
typedef long long lint;
typedef complex<double> P;
#define mp make_pair
#define fi first
#define se second
typedef pair<int,int> pint;
#define All(s) s.begin(),s.end()
#define rAll(s) s.rbegin(),s.rend()
#define REP(i,a,b) for(int i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)
int bff[1919];
int pos[1919];
bool used[1919];
int out=0,N;
bool cal(int n){
	//rep(i,n) cout<<pos[i]<<' ';cout<<endl;
	rep(i,n){
		if(pos[(i+1)%n]!=bff[pos[i]] && pos[(i+n-1)%n]!=bff[pos[i]]) return false;
	}
	return true;
}
void dfs(int n){
	if(n>out){
		if(cal(n)) out=max(out,n);
	}
	rep(i,N){
		if(!used[i]){
			used[i]=true;pos[n]=i;dfs(n+1);used[i]=false;
		}
	}
}
int main()
{
	int t,n;
	cin>>t;
	rep(i,t){
		cin>>n;N=n;
		rep(j,n){
			cin>>bff[j];bff[j]--;
		}
		memset(used,false,sizeof(used));
		out=0;dfs(0);
		printf("Case #%d: %d\n",i+1,out);
	}
}
