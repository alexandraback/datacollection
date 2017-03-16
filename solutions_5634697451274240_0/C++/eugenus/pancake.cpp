#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <iomanip>
#include <cmath>
#include <algorithm>
#include <queue>
#include <map>
#include <string>
#include <vector>
#include <cstring>
#include <set>

#define forn(i,n) for(int i = 0; i < (n); i++)
#define forsn(i,s,n) for(int i = (s); i < (n); i++)
#define all(v) ((v).begin, (v).end)
#define pb push_back
#define x first
#define y second
#define mp make_pair

using namespace std;

typedef pair<int,int> par;
typedef long long int tint;

int main()
{
	freopen("test.txt","r",stdin);
	freopen("out.txt","w",stdout);

	int t; string s;

	cin >> t;

	forsn(caso,1,t+1)
	{
		cin >> s;
		int n = s.size();

		int ans = 0;

		bool end = false;

		while(!end)
		{
			int j = -1;
			for(int i = (n-1); i >= 0; i--)
			{
				if(s[i] == '-')
				{
					j = i;
					break;
				}
			}
			if(j == -1) end = true;
			else
			{
				if(s[0] == '+')
				{
					int k = 0;
					forn(i,n)
					{
						if(s[i] == '-')
						{
							k = i;
							break;
						}
					}

					forn(i,k) s[i] = '-';

					//cout << s << endl;
					ans++;
				}
				reverse(s.begin(), s.begin()+j+1);
				//cout << s << endl;
				forn(i,j+1)	s[i] = s[i] == '+' ? '-' : '+';
				//cout << s << endl;
				ans++;
			}
		}

		cout << "Case #" << caso << ": " << ans << endl;
	}

	return 0;
}