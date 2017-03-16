#include <bits/stdc++.h>

using namespace std;
typedef pair<int,int> P;
typedef long long ll;
#define pb push_back
#define mp make_pair
#define fi first
#define sc second
#define INF 1000000000

int main()
{
	int t; cin >> t;
	for(int i=0;i<t;i++)
	{
		int x;
		string s; cin >> x >> s; cout << "Case #" << i+1 << ": ";
		for(int res=0;;res++)
		{
			int p = (s[0]-'0')+res;;
			for(int i=1;i<s.size();i++)
			{
				if(p >= i)
				{
					p += (s[i]-'0');
				}
				else
				{
					goto FAIL;
				}
			}
			cout << res << endl; break; FAIL:;
		}
	}
}