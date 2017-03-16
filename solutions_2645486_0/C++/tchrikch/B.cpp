#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
#include<set>
#include<sstream>
#include<cmath>
#include<cstdio>
using namespace std;
#define REP(i,n) for(int i=0;i<n;++i)
#define REPD(i,n) for(int i=n;i>-1;--i)
#define FOR(i,j,k) for(int i=j;i<k;++i)
#define PB push_back
#define LL unsigned long long
#define MAX_S 101
#define MP make_pair

LL solve(LL c,LL e,LL r,int wsk,vector<LL> & v)
{
//	cout<<c<<" "<<wsk<<endl;
	if(wsk==v.size()) return 0;
	LL ret = 0;
	
	REP(i,c+1)
	{
		LL tmp =  i * v[wsk];
		LL nc = min(c-i+r,e);
	//	cout<<i<<" "<<ret<<" "<<tmp<<" "<<nc<<" "<<wsk<<" "<<v[wsk]<<endl;
		
		ret = max(ret,tmp + solve(nc,e,r,wsk+1,v)); 
	}
	
	return ret;
}

int main(){
	 int ts=0; cin>>ts;
	 REP(ww,ts)
	 {
	    LL ret = 0;
		
		LL e,r,n; cin>>e>>r>>n;
		vector<LL> v(n,0); REP(i,n) cin>>v[i];
		LL step = min(r,e);
		
		
		int wsk = 0 ;
		
		int j = -1;
		FOR(k,wsk,n) {if(j == -1 || v[k] > v[j]) j = k;}
			
		REP(i,j) ret+=r*v[i];
		ret+= e*v[j];
		wsk = j+1;
		
		//cout<<ret<<endl;
		ret+=solve(min(e,r),e,r,wsk,v);
		
		cout<<"Case #"<<(ww+1)<<": "<<ret<<endl;
	 }
	
	return 0;
}
