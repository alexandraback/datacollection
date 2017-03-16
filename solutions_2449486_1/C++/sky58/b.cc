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
typedef pair<int,pint> tint;
#define All(s) s.begin(),s.end()
#define rAll(s) s.rbegin(),s.rend()
#define REP(i,a,b) for(int i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)
bool ta[110],yo[110];
vector <pint> p[110];
int ma[110][110];
string ret[2]={"NO","YES"};
int main()
{
	int t,h,w,f;
	cin>>t;
	rep(i,t){
		cin>>h>>w;f=1;
		rep(j,110) p[j].clear();
		memset(ta,false,sizeof(ta));
		memset(yo,false,sizeof(yo));
		rep(j,h) rep(k,w){
			cin>>ma[j][k];
			p[ma[j][k]].pb(mp(j,k));
		}
		for(int j=100;j>0;j--){
			rep(k,p[j].size()){
				if(ta[p[j][k].fi] && yo[p[j][k].se]) f=0;
			}
			rep(k,p[j].size()){
				ta[p[j][k].fi]=yo[p[j][k].se]=true;
			}
		}
		cout<<"Case #"<<i+1<<": "<<ret[f]<<endl;
	}
	return 0;
}
