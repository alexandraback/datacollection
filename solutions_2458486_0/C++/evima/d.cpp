#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <valarray>
#include <vector>

#define EPS 1e-9
#define INF 1070000000LL
#define MOD 1000000007LL
#define fir first
#define foreach(it,X) for(__typeof((X).begin()) it=(X).begin();it!=(X).end();it++)
#define ite iterator
#define mp make_pair
#define rep(i,n) rep2(i,0,n)
#define rep2(i,m,n) for(int i=m;i<(n);i++)
#define pb push_back
#define sec second
#define sz(x) ((int)x.size())

using namespace std;

struct timer{
	time_t start;
	timer(){start=clock();}
	~timer(){cerr<<1.*(clock()-start)/CLOCKS_PER_SEC<<" secs"<<endl;}
};

typedef istringstream iss;
typedef long long ll;
typedef pair<int,int> pi;
typedef stringstream sst;
typedef vector<int> vi;

int n;
int init[211];
int type[22];
int chest[22][211];

int dp[1<<20];
int next[1<<20];

int f(int mask){
	int& res=dp[mask];
	if(res!=-1)return res;
	if(mask==0)return res=1;
	
	res=0;
	rep(i,n)if(mask>>i&1){
		int key=init[type[i]];
		rep(j,n)if(!(mask>>j&1)){
			if(type[j]==type[i])key--;
			key += chest[j][type[i]];
		}
		if(key>=1){
			//cout<<mask<<" "<<i<<" "<<key<<endl;
			int res2=f(mask^(1<<i));
			if(res2){
				//cout<<"OK"<<endl;
				next[mask]=i;
				return res=1;
			}
		}
	}
	return res;
}

int main(){
	int T;
	cin>>T;
	time_t start=clock(),pre=start;
	rep(tc,T){
		cout<<"Case #"<<tc+1<<": ";
		
		int K;
		cin>>K>>n;
		fill(init,init+211,0);
		memset(chest,0,sizeof(chest));
		rep(i,K){
			int x;
			cin>>x;
			init[x-1]++;
		}
		rep(i,n){
			int q;
			cin>>type[i]>>q;
			type[i]--;
			rep(j,q){
				int x;
				cin>>x;
				chest[i][x-1]++;
			}
		}
		
		int mask=(1<<n)-1;
		memset(dp,-1,sizeof(dp));
		memset(next,-1,sizeof(next));
		f(mask);
		if(!dp[mask]){
			cout<<"IMPOSSIBLE"<<endl;
		}else{
			while(mask){
				cout<<next[mask]+1<<" ";
				mask^=1<<next[mask];
			}
			cout<<endl;
		}
		
		time_t now=clock();
		cerr<<tc+1<<"/"<<T<<": "<<(double)(now-pre)/CLOCKS_PER_SEC<<endl;
		if(tc==T-1){
			cerr<<"Total: "<<(double)(now-start)/CLOCKS_PER_SEC<<endl;
			cerr<<"  Ave: "<<(double)(now-start)/CLOCKS_PER_SEC/T<<endl;
		}
		pre=now;
	}
}
