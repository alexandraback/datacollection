#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)
#define all(c) c.begin(),c.end()
#define pb push_back
#define fs first
#define sc second
#define show(x) cout << #x << " = " << x << endl
#define chmin(x,y) x=min(x,y)
#define chmax(x,y) x=max(x,y)
using namespace std;
template<class S,class T> ostream& operator<<(ostream& o,const pair<S,T> &p){return o<<"("<<p.fs<<","<<p.sc<<")";}
template<class T> ostream& operator<<(ostream& o,const vector<T> &vc){o<<"sz = "<<vc.size()<<endl<<"[";for(const T& v:vc) o<<v<<",";o<<"]";return o;}
typedef long long ll;
int T;
int main(){
	cin>>T;
	rep1(tt,T){
		printf("Case #%d: ",tt);
		int K,C,S;
		cin>>K>>C>>S;
		if(C*S<K){
			puts("IMPOSSIBLE");
		}else{
			bool done=0;
			int i=0;
			rep(j,S){
				ll x=0;
				rep(k,C){
					x=x*K+i;
					if(!done) i++;
					if(i==K) done=1,i=0;
				}
				cout<<x+1<<" ";
				if(done) break;
			}
			puts("");
		}
	}
}
