#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
#include <cstdio>
#include <map>

using namespace std;

typedef long long ll;

ll MOD = 1e9+7;

ll powMod(ll b,ll p,ll M) {
	if(p==0)
		return 1;
	if(p%2)
		return (b*powMod(b,p-1,M))%M;
	ll t = powMod(b,p/2,M);
	return (t*t)%M; 
}
int checkPrime(long n) {
	//n>=3
	if(n%2==0) return 2;
	long s = sqrt(n)+1;
	for (int i = 3; i <=s ; i+=2)
	{
		if(n%i==0)
			return i;
	}
	return 0;
}

long getNumber(long inBin,int b) {
	long a = 0;
	long p = 1;
	while(inBin) {

		if((inBin&1))
			a =  a + p;
		p*=b;
	//	cout<<">"<<inBin<<' '<<a<<"<";

	inBin>>=1;
	}
	return a;

}
long solve() {
	int N=32,K=500;

	int temp = 0;
	
	string ans(N,'0');
	ans[0]=ans[1]=ans[N-1]=ans[N-2]='1';


	while(K) {
		long t2 = temp;
		int p = 1;
		for (int i = 2; i < N-2; ++i)
		{
			ans[i] = '0';
		}

		while(t2) {
			if(t2&1)
				ans[N-2-p]=ans[N-2-p-1] = '1';

			t2>>=1;
			p+=2;
		}
		cout<<ans<<" 3 4 5 6 7 8 9 10 11 \n";


		temp++;
		K--;

	}
	
}

int main(int argc, char const *argv[])
{
	std::ios::sync_with_stdio(false);
	
	
	int T=1;
	//cin>>T;
	//for (int i = 2; i <= 100; ++i)
	//cout<<i<<":"<<checkPrime(i)<<endl;
	
	for (int i = 0; i < T; ++i)
	{
			cout<<"Case #"<<i+1<<": ";
			cout<<endl;
			solve();
			
	}
	

	return 0;
}

