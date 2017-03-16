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
	int N=16,K=50;

	int inB = (1L<<(N-1))+1;
	while(K) {

		int flag = 1;
		std::vector<long> v;
		for (int base = 2; base <= 10; ++base)
		{
			long current = getNumber(inB, base);

			long ans = checkPrime(current);
			if(ans!=0)
				v.push_back(ans);
			else {
				flag = 0;
				break;
			}
		}
		if(flag) {
			K--;
			cout<<getNumber(inB, 10)<<" ";
			for (int i = 0; i < 9; ++i)
			{
				cout<<v[i]<<' ';
			}
			cout<<endl;
		}

		inB+=2;

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

