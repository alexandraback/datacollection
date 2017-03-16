#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	string s;
	cin>>T;
	for(int tc = 1; tc <= T; tc++)
	{
		cin>>s;
		cout<<"Case #"<<tc<<": ";
		char ch = '+';
		int ans = 0, ln = s.length()-1;
		while(ln>=0)
		{
			while(ln>=0)
			{
				if(s[ln]!=ch)
					break;
				ln--;
			}
			if(ln>=0)
				ans++;
			ch = (ch=='+')?'-':'+';
		}
		cout<<ans<<"\n";
	}
}