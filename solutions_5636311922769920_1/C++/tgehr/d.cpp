#include <bits/stdc++.h>
using namespace std;
#define int long long
#define vc vector
#define pb push_back
#define all(v) (v).begin(),(v).end()

void solve(int k,int c,int s){
	vc<int> r;
	int cur=0;
	while(cur<k){
		int x=0;
		for(int j=cur;j<min(cur+c,k);j++)
			x=x*k+j;
		cur+=c;
		r.pb(x);
		if(r.size()>s){
			cout<<"IMPOSSIBLE\n";
			return;
		}
	}
	for(int i=0;i<(int)r.size();i++)
		cout<<r[i]+1<<(i+1==(int)r.size()?"\n":" ");
}

main(){
	int T;
	cin>>T;
	for(int t=1,k,c,s;t<=T;t++){
		cin>>k>>c>>s;
		cout<<"Case #"<<t<<": ";
		solve(k,c,s);
	}
}


