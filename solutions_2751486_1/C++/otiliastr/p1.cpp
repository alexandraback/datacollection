#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <queue>

using namespace std;

long long solve(string s, int n)
{
	int L=s.length();
	int upoz = -1;
	int cnt = 0;
	long long sol = 0;
	for (int i=0; i<L; ++i)
	{
		if (! (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')) //cons
			++cnt;
		else
			cnt = 0;
		if (cnt >= n)
			upoz = i - n + 1;
		sol += upoz + 1;
	}
	return sol;
}

int main()
{
	freopen("A-large.in","r",stdin);
	freopen("rez2.out","w",stdout);
	int T,n;
	string s;
	cin>>T;
	for (int t=1; t<=T; ++t){
		cin>>s>>n;
		cout<<"Case #"<<t<<": "<<solve(s,n)<<"\n";
	}
	
	return 0;
}
