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

ll Gcd(ll a,ll b){
	ll r;
	while(1) {
		r=b%a;if(r==0) return a;
		b=a;a=r;
	}
}

ll Pow(ll a ,int b ,int Mo){
    ll ans = 1;
    for (; b; b >>= 1, a = a * a % Mo)
        if (b&1) ans = ans * a % Mo;
    return ans;
}

long solve() {
	int N;
	std::vector<int> v(2501,0);
	cin>>N;
	for (int i = 0; i < 2*N-1; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
		int x;
		cin>>x;
		v[x]++;
     	}
	}
	std::vector<int> a;
	for (int i = 1; i <2501; ++i)
	{
		if(v[i]%2==1)
			a.push_back(i);
	}
	if(a.size()==N) {
		for (int i = 0; i < N; ++i)
		{
			sort(a.begin(),a.end());
			cout<<a[i]<<' ';
		}
	} else {
		cerr<<"Error";
		exit(-1);
	}
	
}

int main(int argc, char const *argv[])
{
	std::ios::sync_with_stdio(false);
	
	
	int T;
	cin>>T;
	for (int i = 0; i < T; ++i)
	{
			cout<<"Case #"<<i+1<<": ";
			solve();
			cout<<endl;
	}
	

	return 0;
}

