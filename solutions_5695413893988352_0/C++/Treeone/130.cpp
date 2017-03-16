#include <bits/stdc++.h>
#define rep(i,a,n) for(int i=a;i<n;i++)
#define repb(i,a,b) for(int i=a;i>=b;i--)
#define all(a) a.begin(),a.end()
#define o(a) cout<<a<<endl
//#define int long long
#define fi first
#define se second
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;

signed main(){
	int test_case;
	cin>>test_case;
	rep(x,0,test_case){
		string c,js;
		cin>>c>>js;
		int l=c.size();
		int C,J,MIN=10000;
		int dc[3]={},dj[3]={};
		rep(i,0,l){
			if(c[i]=='?') dc[i]=-1; 
			else dc[i]=c[i]-'0';
		}
		rep(i,0,l){
			if(js[i]=='?') dj[i]=-1;
			else dj[i]=js[i]-'0';
		}
		int lim;
		if(l==1) lim=10;
		if(l==2) lim=100;
		if(l==3) lim=1000;
		rep(i,0,lim){
			rep(j,0,lim){
				bool f=true,g=true;
				int t=i;
				rep(k,0,l){
					int tmp=t%10;
					if(dc[l-k-1]!=-1 && dc[l-k-1]!=tmp) f=false;
					t/=10;
				}
				t=j;
				rep(k,0,l){
					int tmp=t%10;
					if(dj[l-k-1]!=-1 && dj[l-k-1]!=tmp) g=false;
					t/=10;
				}
				if(!f||!g) continue;
				if(abs(i-j)<MIN){
					MIN=abs(i-j); C=i; J=j;
				}if(abs(i-j)==MIN){
					if(C>i){
						C=i; J=j;
					}else if(C==i && J>j) J=j;
				}
			}
		}
		cout<<"Case #"<<x+1<<": ";
		if(l==1) printf("%d %d\n",C,J);
		if(l==2) printf("%02d %02d\n",C,J);
		if(l==3) printf("%03d %03d\n",C,J);

	}
}
