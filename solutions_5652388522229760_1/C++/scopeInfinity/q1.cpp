#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
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

long solve(long N) {
	int A[10] = {0};
	long c = -1;
	if(N==0)
	{
		cout<<"INSOMNIA";
		return 0;
	} 
	int cc=1;
	long ans = N;
	while(1) {
		
		int x = cc*N;
		int a = x;
		while(a) {
			A[a%10] = 1;
			a/=10;
		}
		

		int flag  = 1;
		for (int i = 0; i < 10; ++i)
		{
			if(A[i]==0)
			{
				flag = false;
				break;
			}
		}
		if(flag)
			break;

		cc++;
		
		c++;

		
		//cout<<x<<endl;


	}
	cout<<(cc*N);
	
}

int main(int argc, char const *argv[])
{
	std::ios::sync_with_stdio(false);
	
	
	int T;
	cin>>T;
	for (int i = 0; i < T; ++i)
	{
			cout<<"Case #"<<i+1<<": ";
			long n;
			cin>>n;
			solve(n);
			cout<<endl;
	}
	

	return 0;
}

