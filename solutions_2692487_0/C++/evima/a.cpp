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

int A,N,m[111];
int dp[101][1000001];

int f(int cur,int size){
	if(size>1000000)size=1000000;
	int& res=dp[cur][size];
	if(res!=-1)return res;
	
	if(cur==N)return res=0;
	res=INF;
	if(size > m[cur])res=min(res,f(cur+1,size + m[cur]));
	res=min(res,1+f(cur+1,size));
	res=min(res,1+f(cur,size+size-1));
	return res;
}

int main(){
	int T;
	cin>>T;
	time_t start=clock(),pre=start;
	rep(tc,T){
		cout<<"Case #"<<tc+1<<": ";
		//
		
		cin>>A>>N;
		rep(i,N)cin>>m[i];
		sort(m,m+N);
		
		if(A==1){
			cout<<N<<endl;
			continue;
		}
		
		memset(dp,-1,sizeof(dp));
		cout<<f(0,A)<<endl;
		
		//
		time_t now=clock();
		cerr<<tc+1<<"/"<<T<<": "<<(double)(now-pre)/CLOCKS_PER_SEC<<endl;
		if(tc==T-1){
			cerr<<"Total: "<<(double)(now-start)/CLOCKS_PER_SEC<<endl;
			cerr<<"  Ave: "<<(double)(now-start)/CLOCKS_PER_SEC/T<<endl;
		}
		pre=now;
	}
}
