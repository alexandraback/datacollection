#include <bits/stdc++.h>

#define ll long long
#define ff first
#define ss second
#define mp make_pair

using namespace std;

typedef pair < ll , ll > pie;

int main()
{
	ios_base::sync_with_stdio(false);
	int T;
	cin >> T;
	for(int k = 1; k <= T; k++)
	{
		string s;
		cin >> s;
		string ss = "";
		ss += s[0];
		for(int i = 1; i < s.size(); i++)
			if(ss[0] <= s[i])
				ss = s[i] + ss;
			else
				ss = ss + s[i];
		cout<<"Case #"<<k<<": "<<ss<<endl;
	}
	return 0;
}