#include <cmath>
#include <cstdio>
#include <cstring>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <vector>
#include <string>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

void rev(int n, string &s)
{
	for(int i=0,j=n; i<=j; ++i,--j)
	{
		swap(s[i],s[j]);
		s[i] = '+'+(int)'-'-s[i];
		if(i!=j)
			s[j] = '+'+(int)'-'-s[j];
	}
}


bool done(string &s)
{
	for(int i=0; i<s.size(); ++i)
		if(s[i] != '+')
			return 0;
	return 1;
}

int main() {
	int t;

	cin >> t;
	for(int tt=1; tt<=t; ++tt)
	{
		int n;
		string s;
		cin >> s;

		int ans = 0;
		while(!done(s))
		{
			if(s[0] == '+')
			{
				int n=0;
				for(; s[n]=='+'; ++n)
				{}
				rev(n-1, s);
			}
			else
			{
				int n=s.size()-1;
				for(; s[n]=='+'; --n)
				{}
				rev(n, s);
			}
			++ans;
		}

		cout << "Case #" << tt << ": " << ans << "\n";
		cout.flush();
	}

	return 0;
}
