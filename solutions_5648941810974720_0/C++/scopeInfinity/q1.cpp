#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <map>
#include <cstring>

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
	std::vector<int> count(255,0),C;
	for (int i = 0; s[i]!='\0'; ++i)
	{
		count[s[i]]++;
	}

	const char *words[] = {"Z1E1R1O1","F1O1U1R1","T1W1O1","E1I1G1H1T1","S1I1X1","S1E2V1N1","O1N1E1","N2I1E1","T1H1R1E2", "F1I1V1E1"  };
	int T[] = {0,4,2,8,6,7,1,9,3,5};
	std::vector<int> v;
	for (int i = 0; i <=9; ++i)
	{
		while(true) {
			int len = strlen(words[i]);
			int pos = 1;
			for (int j = 0; j < len; j+=2)
			{
				int x= words[i][j+1]-'0';
				if(count[words[i][j]]<x)
				{
					pos = 0;break;
				}
			}
			if(pos==0) break;
			for (int j = 0; j < len; j+=2)
			{
				int x= words[i][j+1]-'0';
				count[words[i][j]]-=x;
			}
			v.push_back(T[i]);
			//cout<<i;

		}
	}
	sort(v.begin(),v.end());
	for (int i = 0; i < v.size(); ++i)
	{
		cout<<v[i];
	}
	for (int i = 0; i < count.size(); ++i)
	{
		if(count[i]!=0)
		{
			cerr<<(char)i<<" : "<<count[i]<<endl;

		}
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

