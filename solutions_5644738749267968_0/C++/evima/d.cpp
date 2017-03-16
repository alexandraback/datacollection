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

int N;
int a[1010],b[1010];

void main2(){
	cin>>N;
	rep(i,N){
		double x;
		cin>>x;
		a[i] = x*100000+0.5;
	}
	sort(a,a+N);
	rep(i,N){
		double x;
		cin>>x;
		b[i] = x*100000+0.5;
	}
	sort(b,b+N);
	int ans1=0, ans2=0;
	for(int sac = 0; sac <= N; sac++){
		int res = 0;
		set<int> S;
		rep2(i,sac,N)S.insert(a[i]);
		int cur = 0;
		rep(i,N-sac){
			auto up = S.upper_bound(b[cur]);
			if(up == S.end()){
				S.erase(S.begin());
			}
			else{
				S.erase(up);
				res++;
				cur++;
			}
		}
		ans1 = max(ans1, res);
	}
	set<int> S;
	rep(i,N)S.insert(b[i]);
	rep(i,N){
		auto up = S.upper_bound(a[i]);
		if(up == S.end()){
			S.erase(S.begin());
			ans2++;
		}else{
			S.erase(up);
		}
	}
	cout<<ans1<<" "<<ans2<<endl;
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
