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
	int B;
	ll M;
	cin>>B>>M;
	std::vector<std::vector<int> > G = std::vector<std::vector<int> > (B,std::vector<int>(B,0));
	for (int i = 0; i < B; ++i)
	{
		for (int j = i+1; j < B-1; ++j)
		{
			G[i][j]=1;
		}
	}
	if(M>0)
	{
		G[0][B-1] = 1;
		M--;
	}
	int index = 0,allgood=1;
	while(M) {
		if(M&1) {
			if(index+1>=B-1) {
				allgood = 0;
				break;
			}
           G[index+1][B-1]=1;
		}
		index++;
		M>>=1;
	}
	if(allgood)
	{
		cout<<"POSSIBLE\n";
		for (int i = 0; i < B; ++i)
		{
			for (int j = 0; j < B; ++j)
			{
				cout<<G[i][j];
			}
			if(i!=B-1)
			cout<<endl;
		}
	}
	else {
		cout<<"IMPOSSIBLE";
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

