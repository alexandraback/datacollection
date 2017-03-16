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
	string s;
	cin>>s;
	string t=" ";
	t[0]=s[0];
	for(int i=1;s[i]!='\0';i++) {
		if(s[i]>=t[0]) {
			t = s[i]+t;
		} else {
			t = t + s[i];
		}
		//cout<<t<< ' ';
	}
	cout<<t;

	
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

