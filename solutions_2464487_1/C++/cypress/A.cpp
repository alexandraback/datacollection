#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;

typedef long long LL;

const double pi=acos(-1);
const double eps=1e-10;

LL r,t;

bool check(LL k){
	long double s=t;
	long double tmp=(2*r+2*double(k)-1)*double(k);
	return tmp<=s+eps;
}

LL getans(LL r,LL t) {
	LL L,R,MID;
	L=1,R=t;
	while (R-L>1) {
		LL MID=(R+L)/2;
		if (check(MID)) L=MID;
			else R=MID;
	}
	if (check(R)) return R;
		else return L;
}

void solve(){
	cin>>r>>t;
	LL ans=getans(r,t);
	cout<<ans<<"\n";
}

int main(){
	
	freopen("A-large.in","r",stdin);
	freopen("A-large.out","w",stdout);
	
	int T;	
	cin>>T;
	for (int cs=1;cs<=T;cs++) {
		cout<<"Case #"<<cs<<": ";
		solve();
	}
	
	
	return 0;
}
