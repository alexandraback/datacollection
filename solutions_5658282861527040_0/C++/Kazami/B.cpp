#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	int T; cin>>T;
	for(int iT=1;iT<=T;iT++)
	{
		int A,B,K; cin>>A>>B>>K;
		int ans = 0;
		for(int i=0;i<A;i++)
			for(int j=0;j<B;j++)
				if((i&j)<K) ans++;
		cout<<"Case #"<<iT<<": "<<ans<<'\n';
	}
	return 0;
}