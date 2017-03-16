#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <map>
#include <cmath>

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
	
	string C,S;
	cin>>C>>S;
	int l = C.length();
	int M = pow(10,l);

	std::vector<int> vA,vB;

	int MIN = 1e9;
	int a=-1,b;

	for (int i = 0; i < M; ++i)
	{
		int t = i;
		int in = 0;
		for (int k = 0; k < l; ++k)
		{
			if(C[l-1-k]!='?')
				if(t%10 != C[l-1-k]-'0')
					{in = 1;break;}
			t/=10;
		}
		if(in) continue;


		for (int j = M-1; j >=0; --j)
		{
			t = j;
			in = 0;
			for (int k = 0; k < l; ++k)
				{
					if(S[l-1-k]!='?')
						if(t%10 != S[l-1-k]-'0')
							{in = 1;break;}
					t/=10;
				}
				if(in) continue;


			int ans = abs(i-j);
			if(MIN > ans) {
				//cout<<"UPDATING "<<MIN<<' '<<ans<<endl;
				MIN = ans;
				vA.clear();
				vB.clear();
				a = i;
				b = j;
			} 
			 if (MIN == ans) {
				//cout<<i<<','<<j<<" "<<MIN<<endl;
				if(i<a) {
					a = i;
					b = j;
				} else if(i==a && j<b)
				{
					a=i;
					b=j;
				}
			}
		}


	}
	string A,B;
	while(a) {
		A+=(char)(a%10+'0');
		a/=10;
	}
	while(b) {
		B+=(char)(b%10+'0');
		b/=10;
	}
	for (int i = 0; i < l-A.length(); ++i)
	{
		cout<<"0";
	}
	for (int i = 0; A[i]!='\0'; ++i)
	{
		cout<<A[A.length()-1-i];
	}
	cout<<" ";
	for (int i = 0; i < l-B.length(); ++i)
	{
		cout<<"0";
	}
	for (int i = 0; B[i]!='\0'; ++i)
	{
		cout<<B[B.length()-1-i];
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

