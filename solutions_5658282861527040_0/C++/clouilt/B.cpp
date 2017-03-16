#include <iostream>
#include <cstdio>
using namespace std;

int main(){
	freopen("I:\\1b\\B-small-attempt0.in","r",stdin);
	freopen("I:\\1b\\B-small-attempt0.in.txt","w",stdout);
	int A,B,K,T;
	cin>>T;
	for(int cs=1;cs<=T;++cs){
		cin>>A>>B>>K;
		int cnt=0;
		for(int i=0;i<A;++i)
			for(int j=0;j<B;++j)
				if((i&j)<K)
					++cnt;

		cout<<"Case #"<<cs<<": "<<cnt<<endl;
	}
	return 0;

}
