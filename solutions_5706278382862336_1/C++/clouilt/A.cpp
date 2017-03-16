#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>

using namespace std;
long long pow2[43];
long long P,Q;
long long gcd(long long P,long long Q){
	if(P==0LL)
		return Q;
	return gcd(Q%P,P);
}
int main(){
	freopen("I:\\gcj\\A-large.in","r",stdin);
	freopen("I:\\gcj\\A-large.out","w",stdout);
	pow2[0]=1;
	for(int i=1;i<43;++i)
		pow2[i]=2LL*pow2[i-1];

	int T;
	char c;
	cin>>T;
	bool flag;
	for(int cs=1;cs<=T;++cs){
		cin>>P>>c>>Q;
		long long tmp=gcd(P,Q);
		P/=tmp;
		Q/=tmp;
	//	cout<<P<<' '<<Q<<endl;
		flag=false;
		for(int i=0;i<43;++i)
			if(Q==pow2[i])
				flag=true;

		if(flag){
			int cnt=1;
			P*=2LL;
			while(P<Q){
				P*=2LL;
				++cnt;
			}
			cout<<"Case #"<<cs<<": "<<cnt<<endl;
		}else{
			cout<<"Case #"<<cs<<": impossible"<<endl;
		}
	}
	return 0;
}
