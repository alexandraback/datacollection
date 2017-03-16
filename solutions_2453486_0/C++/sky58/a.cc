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
string s[5];
string cal(void){
	int t=0,f=0;
	rep(i,4){
		if(s[i][i]=='T') t++;
		if(s[i][i]=='X') f|=1;
		if(s[i][i]=='O') f|=2;
		if(s[i][i]=='.') f|=4;
	}
	if(t<2){
		if(f==1) return "X won";
		if(f==2) return "O won";
	}
	
	t=0;f=0;
	rep(i,4){
		if(s[i][3-i]=='T') t++;
		if(s[i][3-i]=='X') f|=1;
		if(s[i][3-i]=='O') f|=2;
		if(s[i][3-i]=='.') f|=4;
	}
	if(t<2){
		if(f==1) return "X won";
		if(f==2) return "O won";
	}
	
	rep(j,4){
		t=0;f=0;
		rep(i,4){
			if(s[i][j]=='T') t++;
			if(s[i][j]=='X') f|=1;
			if(s[i][j]=='O') f|=2;
			if(s[i][j]=='.') f|=4;
		}
		if(t<2){
			if(f==1) return "X won";
			if(f==2) return "O won";
		}
	}
	
	rep(j,4){
		t=0;f=0;
		rep(i,4){
			if(s[j][i]=='T') t++;
			if(s[j][i]=='X') f|=1;
			if(s[j][i]=='O') f|=2;
			if(s[j][i]=='.') f|=4;
		}
		if(t<2){
			if(f==1) return "X won";
			if(f==2) return "O won";
		}
	}
	
	rep(i,4) rep(j,4){
		if(s[i][j]=='.') return "Game has not completed";
	}
	return "Draw";
}
int main()
{
	int t;
	cin>>t;
	rep(i,t){
		rep(j,4) cin>>s[j];
		//rep(j,4) cout<<s[j]<<endl;
		cout<<"Case #"<<i+1<<": "<<cal()<<endl;
		//cin>>s[0];
	}
	return 0;
}
