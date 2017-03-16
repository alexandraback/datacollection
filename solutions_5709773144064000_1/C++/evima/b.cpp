// Enjoy your stay.

#include <bits/stdc++.h>

#define EPS 1e-9
#define INF 1070000000LL
#define MOD 1000000007LL
#define fir first
#define foreach(it,X) for(auto it=(X).begin();it!=(X).end();it++)
#define ite iterator
#define mp make_pair
#define mt make_tuple
#define rep(i,n) rep2(i,0,n)
#define rep2(i,m,n) for(int i=m;i<(n);i++)
#define pb push_back
#define sec second
#define sz(x) ((int)(x).size())

using namespace std;

typedef istringstream iss;
typedef long long ll;
typedef pair<ll,ll> pi;
typedef stringstream sst;
typedef vector<ll> vi;

double C,F,X;

double f(int x){
	double res = 0;
	rep(j,x){
		res += C / (2 + j*F);
	}
	res += X / (2 + x*F);
	return res;
}

void main2(){
	cin>>C>>F>>X;
	double ans = INF*INF;
	int lo = 0, hi = 111111;
	while(lo+10 < hi){
		int L = (lo*2+hi)/3;
		int R = (lo+hi*2)/3;
		double fL = f(L);
		double fR = f(R);
		if(fL < fR) hi = R;
		else lo = L;
	}
	rep2(i,lo,hi+1){
		ans = min(ans, f(i));
	}
	cout<<setprecision(16)<<ans<<endl;
	/*rep(i,INF){

		if(i%1000==0)cerr<<i<<" "<<res<<endl;
		if(res > ans){
			cout<<setprecision(16)<<ans<<endl;
			break;
		}else{
			ans = res;
		}
	}*/
}

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	
	
	int T;
	cin>>T;
	time_t start=clock(),pre=start;
	rep(tc,T){
		cout<<"Case #"<<tc+1<<": ";
		main2();
		time_t now=clock();
		cerr<<tc+1<<"/"<<T<<": "<<(double)(now-pre)/CLOCKS_PER_SEC<<endl;
		if(tc==T-1){
			cerr<<"Total: "<<(double)(now-start)/CLOCKS_PER_SEC<<endl;
			cerr<<"  Ave: "<<(double)(now-start)/CLOCKS_PER_SEC/T<<endl;
		}
		pre=now;
	}
}
