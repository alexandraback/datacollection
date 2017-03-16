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

long solve() {
	string s;
	cin>>s;
	int l =0,c=0;
	while(1) {
		l = -1;
		for (int i = 0; s[i]!='\0'; ++i)
		{
			if(s[i]=='-')
				l = i;

		}
		if(l==-1)
			break;

		for (int i = 0; i <=l; ++i)
		{
			if(s[i]=='+')
				s[i] = '-';
			else s[i] = '+';
		}
		c++;


	}
	cout<<c;
	
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

		