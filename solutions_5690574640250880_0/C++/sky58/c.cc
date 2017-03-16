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
int ret[55];
string out[55];
int main()
{
	int t,h,w,m;
	cin>>t;
	rep(i,t){
		cin>>h>>w>>m;
		string s(w,'*');rep(j,h) out[j]=s;
		rep(j,h) ret[j]=0;
		cout<<"Case #"<<i+1<<":"<<endl;
		if(h<2){
			cout<<"c";
			rep(j,w-m-1) cout<<".";
			rep(j,m) cout<<"*";
			cout<<endl;
			continue;
		}
		if(w<2){
			cout<<"c"<<endl;
			rep(j,h-m-1) cout<<"."<<endl;
			rep(j,m) cout<<"*"<<endl;
			continue;
		}
		if(m==h*w-1){
			out[0][0]='c';
			rep(j,h) cout<<out[j]<<endl;
			continue;
		}
		int f=0;
		REP(j,2,w+1){
			int lest=w*h-m-j*2;
			if(lest>j*(h-2) || lest<0) continue;
			if(h>2 && lest==1) continue;
			if(j==2 && lest%2==1) continue;
			ret[0]=ret[1]=j;
			rep(k,lest/j) ret[2+k]=j;
			if(lest%j>0) ret[2+lest/j]=lest%j;
			if(ret[2+lest/j]==1){
				ret[2+lest/j]++;ret[1+lest/j]--;
			}
			f=1;break;
		}
		if(f<1) cout<<"Impossible"<<endl;
		//if(i==4) cerr<<ret[4]<<endl;
		else{
			rep(j,h) rep(k,ret[j]) out[j][k]='.';
			out[0][0]='c';
			rep(j,h) cout<<out[j]<<endl;
		}
	}
}
