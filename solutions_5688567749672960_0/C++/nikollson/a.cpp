#include<cstdio>
#include<vector>
#include<string>
#include<algorithm>
#include<iostream>
#include<map>
#include<set>
#include<queue>
#include<sstream>

using namespace std;

#define reps(i,f,n) for(int i=f;i<int(n);i++)
#define rep(i,n) reps(i,0,n)
#define fi first
#define se second


#ifdef __BORLANDC__
	typedef __int64 ll;
#else
	typedef long long ll;
#endif


const int T = 1111111;
int visit[T];


ll n;
void input(){
	cin>>n;
}

ll rev(ll num){
	stringstream sst;
	sst<<num;
	
	string a;
	sst>>a;
	
	reverse(a.begin(), a.end());
	
	ll ret;
	stringstream sst2;
	sst2<<a;
	sst2>>ret;
	
	return ret;
}

ll solve(){
	rep(i,T)visit[i]=-1;
	
	typedef pair<ll,ll> P;
	queue<P> que;
	que.push(P(1,1));
	
	while(1){
		if(que.empty())break;
		
		P u = que.front();
		que.pop();
		
		if(visit[(int)u.fi]!=-1)continue;
		visit[(int)u.fi]=1;
		
		que.push(P(u.fi+1, u.se+1));
		que.push(P(rev(u.fi), u.se+1));
		
		if(u.fi==n){
			return u.se;
		}
	}
	return -1;
}


int main(){
	int ttt;
	cin>>ttt;
	
	rep(i,ttt){
		input();
		cout<<"Case #"<<(i+1)<<": "<<solve()<<endl;
	}
}