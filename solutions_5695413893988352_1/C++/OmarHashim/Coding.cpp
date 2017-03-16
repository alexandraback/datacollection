#include<bits/stdc++.h>
using namespace std;

#define scl(x) scanf("%lld",&x)
#define sc(x)  scanf("%d",&x)
#define ll long long
#define lop(i,n) for(int i=0;i<n;++i)
typedef pair<int,int> ii;
typedef pair<ll,ll> pll;
typedef pair<string,string> pss;

pss out;
ll mndif;
int t,n;
string x,y;

void rec(string s1,string s2,ll mul,ll cur,int idx,bool mnf,bool mxf){
	if(idx==n){
		if(abs(cur)<mndif){
			out=pss(s1,s2);
			mndif=abs(cur);
		}
		return ;
	}
	int d1,d2;
	if(mnf){
		if(x[idx]=='?')s1.push_back('0'),d1=0;
		else s1.push_back(x[idx]),d1=x[idx]-'0';
		if(y[idx]=='?')s2.push_back('9'),d2=9;
		else s2.push_back(y[idx]),d2=y[idx]-'0';
		rec(s1,s2,mul/10,cur+(d1-d2)*mul,idx+1,mnf,mxf);
		return ;
	}
	if(mxf){
		if(x[idx]=='?')s1.push_back('9'),d1=9;
		else s1.push_back(x[idx]),d1=x[idx]-'0';
		if(y[idx]=='?')s2.push_back('0'),d2=0;
		else s2.push_back(y[idx]),d2=y[idx]-'0';
		rec(s1,s2,mul/10,cur+(d1-d2)*mul,idx+1,mnf,mxf);
		return ;
	}
	if(x[idx]!='?'&&y[idx]!='?'){
		s1.push_back(x[idx]);
		s2.push_back(y[idx]);
		if(x[idx]==y[idx])rec(s1,s2,mul/10,cur,idx+1,mnf,mxf);
		else if(x[idx]<y[idx])rec(s1,s2,mul/10,cur+(x[idx]-y[idx])*mul,idx+1,0,1);
		else rec(s1,s2,mul/10,cur+(x[idx]-y[idx])*mul,idx+1,1,0);
		return ;
	}
	if(x[idx]=='?'&&y[idx]=='?'){
		s1.push_back('0');
		s2.push_back('0');
		rec(s1,s2,mul/10,cur,idx+1,0,0);
		s1[idx]='0';
		s2[idx]='1';
		rec(s1,s2,mul/10,cur-1*mul,idx+1,0,1);
		s1[idx]='1';
		s2[idx]='0';
		rec(s1,s2,mul/10,cur+1*mul,idx+1,1,0);
		return ;
	}
	if(x[idx]=='?'){
		if(y[idx]!='0'){
			s1.push_back(y[idx]-1);
			s2.push_back(y[idx]);
			rec(s1,s2,mul/10,cur-1*mul,idx+1,0,1);
			s1.resize(s1.size()-1);
			s2.resize(s2.size()-1);
		}
		s1.push_back(y[idx]);
		s2.push_back(y[idx]);
		rec(s1,s2,mul/10,cur,idx+1,0,0);
		if(y[idx]!='9'){
			s1[idx]=y[idx]+1;
			s2[idx]=y[idx];
			rec(s1,s2,mul/10,cur+1*mul,idx+1,1,0);
		}
		return ;
	}

	if(x[idx]!='0'){
		s1.push_back(x[idx]);
		s2.push_back(x[idx]-1);
		rec(s1,s2,mul/10,cur+1*mul,idx+1,1,0);
		s1.resize(s1.size()-1);
		s2.resize(s2.size()-1);
	}
	s1.push_back(x[idx]);
	s2.push_back(x[idx]);
	rec(s1,s2,mul/10,cur,idx+1,0,0);
	if(x[idx]!='9'){
		s1[idx]=x[idx];
		s2[idx]=x[idx]+1;
		rec(s1,s2,mul/10,cur-1*mul,idx+1,0,1);
	}
	return ;
}
int main(){
#ifndef ONLINE_JUDGE
	freopen("i.txt","r",stdin);
	freopen("o.txt","w",stdout);
#endif
	cin>>t;
	lop(C,t){
		mndif=1LL<<61;
		cin>>x>>y;
		n=x.size();
		ll mul=1;
		lop(i,n-1)mul*=10;
		rec("","",mul,0,0,0,0);
		printf("Case #%d: ",C+1);
		cout<<out.first<<" "<<out.second<<endl;
	}
};
