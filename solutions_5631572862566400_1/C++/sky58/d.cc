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
int gr[1919];
vector<int> rgr[1919];
bool used[1919];
int dfs(int v,int u){
	//cout<<v<<' '<<u<<endl;
	int ret=0;
	rep(i,rgr[v].size()){
		int w=rgr[v][i];
		if(w!=u) ret=max(ret,1+dfs(w,v));
	}
	return ret;
}
int main()
{
	int t,n;
	cin>>t;
	rep(i,t){
		cin>>n;
		rep(j,n){
			cin>>gr[j];gr[j]--;
		}
		rep(j,1910) rgr[j].clear();
		rep(j,n) rgr[gr[j]].pb(j);
		int mcir=0,sum=0;
		rep(j,n){
			memset(used,false,sizeof(used));
			int now=j;
			for(int k=0;;k++){
				if(used[now]){
					if(now==j) mcir=max(mcir,k);
					break;
				}
				used[now]=true;now=gr[now];
			}
		}
		vector<int> bf;
		rep(j,n){
			if(gr[j]>j && gr[gr[j]]==j) bf.pb(j);
		}
		rep(j,bf.size()){
			//cout<<bf[j]<<' '<<gr[bf[j]]<<endl;
			sum+=2+dfs(bf[j],gr[bf[j]])+dfs(gr[bf[j]],bf[j]);
		}
		printf("Case #%d: %d\n",i+1,max(mcir,sum));
	}
}
