#include<vector>
#include<cmath>
#include<map>
#include<cstdlib>
#include<iostream>
#include<sstream>
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
vector <lint> ka;
bool kai(lint a){
	string s="";
	while(a>0){s+=((a%10)+'0');a/=10;}
	string t=s;reverse(All(t));
	if(s==t) return true;return false;
}
int main()
{
	lint a,b;int t;
	for(a=1;a<=1000;a++){
		if(kai(a)){if(kai(a*a)) ka.pb(a);}
	}
	//cout<<ka.size()<<endl;
	cin>>t;
	rep(i,t){
		int ret=0;cin>>a>>b;
		rep(j,ka.size()){
			if(a<=ka[j]*ka[j] && ka[j]*ka[j]<=b) ret++;
		}
		cout<<"Case #"<<i+1<<": "<<ret<<endl;
	}
	return 0;
}
