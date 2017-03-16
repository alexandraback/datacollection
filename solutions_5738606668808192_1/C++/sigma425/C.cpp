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
bool B(int x,int i){return (x>>i)&1;}
int main(){
	int N,J;
	cin>>N>>J;
	printf("Case #1:\n");
	rep(i,1<<(N-2)){
		int c=0;
		rep(j,N-2){
			if(B(i,j)){
				if(j%2==0) c++;
				else c--;
			}
		}
		if(c==0){
			J--;
			cout<<"1";
			rep(j,N-2) cout<<B(i,j);
			cout<<"1 ";
			rep(j,9) cout<<j+3<<" ";
			puts("");
			if(J==0) break;
		}
	}
}