#include <set>
#include <map>
#include <cmath>
#include <ctime>
#include <queue>
#include <stack>
#include <vector>
#include <string>
#include <cctype>
#include <cstdio>
#include <iomanip>
#include <sstream>
#include <cstdlib>
#include <cassert>
#include <climits>
#include <complex>
#include <numeric>
#include <valarray>
#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;

#define inf 1061109567
#define pb push_back
#define mp make_pair
#define all(a) a.begin(),a.end()
#define mem(x,a) memset(x,a,sizeof(x))
#define rep(i,n) for(int i(0),_n(n);i<_n;++i)
#define repi(i,a,b) for(int i(a),_b(b);i<_b;++i)
#define repr(i,a,b) for(int i(a),_b(b);i>=_b;--i)
#define repe(it,c) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();++it)
#define len(x) ((int)(x.size()))



int E,R;

int n,t1,t2,t3;

vi v;


int dp[11][10];


int fun(int pos,int e){
	
	if(pos==n)return 0;
	
	int &ret=dp[pos][e];
	
	if(ret!=-1)return ret;
	
	ret=0;
	
	rep(i,e+1){
		ret=max(ret,fun(pos+1,min(e-i+R,E))+v[pos]*i);
	}
	
	return ret;
}



int main(){
	ios_base::sync_with_stdio(0);
	freopen("in", "r", stdin);
	freopen("out", "w", stdout);
	
	
	int tests;
	cin>>tests;
	for(int t=1;t<=tests;t++){
		cout<<"Case #"<<t<<": ";
		
		cin>>E>>R>>n;
		v.clear();
		rep(i,n){
			cin>>t1;
			v.pb(t1);
		}
		
		mem(dp,-1);
		
		cout<<fun(0,E)<<endl;
		
		
	}
	
	
	
}









