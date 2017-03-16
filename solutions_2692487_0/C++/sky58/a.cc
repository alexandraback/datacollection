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
vector <lint> mo;
int main()
{
	int t,n,a,b;
	cin>>t;
	rep(i,t){
		mo.clear();
		cin>>a>>n;
		rep(j,n){
			scanf("%d",&b);mo.pb(b);
		}
		sort(All(mo));
		//rep(j,n) cout<<mo[j]<<endl;
		if(a<2){
			cout<<"Case #"<<i+1<<": "<<n<<endl;continue;
		}
		lint now=a;int ret=n,co=0;
		rep(j,n){
			while(now<=mo[j]){now+=now-1;co++;}
			now+=mo[j];
			ret=min(ret,n-1-j+co);
		}
		cout<<"Case #"<<i+1<<": "<<ret<<endl;
	}
	return 0;
}
