#include <iostream>
#include <fstream>
#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <iomanip>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

#define EPS 1e-9
#define INF MOD
#define MOD 1000000007LL
#define fir first
#define foreach(it,X) for(it=X.begin();it!=X.end();it++)
#define iss istringstream
#define ite iterator
#define ll long long
#define mp make_pair
#define rep(i,n) rep2(i,0,n)
#define rep2(i,m,n) for(int i=m;i<n;i++)
#define pi pair<int,int>
#define pb push_back
#define sec second
#define sh(i) (1LL<<i)
#define sst stringstream
#define sz size()
#define vi vector<int>
#define vc vector
#define vl vector<ll>
#define vs vector<string>

int N,a[1010],b[1010],dp[59049];
int p3[1010];
double p[100010];

int getKth(int n,int k){
	return n/p3[k]%3;
}

int f(int mask){
	int& res=dp[mask];
	if(res>-1)return res;
	if(mask==p3[N]-1)return 0;
	int star=0;
	rep(i,N)star+=getKth(mask,i);
	res=INF;
	rep(i,N){
		if(star>=b[i] && getKth(mask,i)!=2){
			int m2=mask;
			m2-=getKth(mask,i)*p3[i];
			m2+=2*p3[i];
			res=min(res,f(m2)+1);
		}
		else if(star>=a[i] && getKth(mask,i)==0){
			int m2=mask;
			m2+=1*p3[i];
			res=min(res,f(m2)+1);
		}
	}//cout<<mask<<" "<<res<<endl;
	return res;
}

int main(){
	int T;
	cin>>T;
	p3[0]=1;
	rep(i,10)p3[i+1]=p3[i]*3;
	
	rep(tc,T){
		cout<<"Case #"<<tc+1<<": ";
		cin>>N;
		rep(i,N)cin>>a[i]>>b[i];
		memset(dp,-1,sizeof(dp));
		int ans=f(0);
		if(ans>10000)cout<<"Too Bad\n";
		else cout<<ans<<endl;
	}
}
