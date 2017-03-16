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
int main(){
	int T;
	cin>>T;
	rep1(tt,T){
		printf("Case #%d: ",tt);
		int N;
		cin>>N;
		if(N==0) puts("INSOMNIA");
		else{
			bool a[10]={};
			int now=N;
			while(true){
				int t=now;
				while(t){
					a[t%10]=1;
					t/=10;
				}
				bool ok=1;
				rep(i,10) if(!a[i]) ok=0;
				if(ok){
					cout<<now<<endl;
					break;
				}
				now+=N;
			}
		}
	}
}
