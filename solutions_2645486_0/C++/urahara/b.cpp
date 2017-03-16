#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<cctype>
#include<ctime>
#include<climits>
#include<iostream>
#include<sstream>
#include<string>
#include<vector>
#include<map>
#include<stack>
#include<queue>
#include<deque>
#include<algorithm>
#include<complex>
#include<set>
#include<bitset>
#include<utility>
#include<valarray>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef vector<vector<int> > vvi;
typedef vector<string> vs;
typedef vector<pair<int,int> > vpii;

#define pb push_back
#define mp make_pair
#define PI acos(-1)
#define all(a) (a).begin(),(a).end()
#define len(a) ((int)(a).size())
#define mem(a,n) memset(a,n,sizeof(a))
#define eps 1e-9
#define rep(i,n) for(int i=0;i<(n);i++)
#define repi(i,a,n) for(int i=(a);i<(n);i++)
#define repr(i,a,n) for(int i=(n);i>=(a);i--)


int ary[11][100],e,r,n;
vi v;
int dp(int pos,int en){
	
	//~ cout<<pos<<" "<<en<<endl;
	if(pos>=n)return 0;
	int &ret=ary[pos][en];
	if(ret!=-1)return ret;
	ret=0;
	rep(i,en+1){
		int t=i*v[pos]+dp(pos+1,min(e,en-i+r));
		ret=max(ret,t);
	}
	//~ cout<<pos<<" "<<en<<" "<<ret<<" "<<x<<endl;
	
	return ret;
}



int main(void){
	ios_base::sync_with_stdio(0);
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	
	int t;
	cin>>t;
	rep(k,t){
		cin>>e>>r>>n;
		v.clear();
		v.resize(n);
		rep(i,n)cin>>v[i];
		mem(ary,-1);
		cout<<"Case #"<<k+1<<": "<<dp(0,e)<<endl;
	}
	return 0;
}
