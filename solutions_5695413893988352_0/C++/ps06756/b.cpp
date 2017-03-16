#include <bits/stdc++.h>
using namespace std;
#define all(c) (c).begin(), (c).end()
#define cnt(c, x) ((c).find(x) != (c).end())
#define pb push_back
#define FOR(i, a, n) for(int i = (a); i < (n); i++)
#define REP(i, n) for(int i = 0; i < (n); i++)
#define SZ(x) ((int) (x).size())
#define mp(x,y) make_pair((x), (y))
#define mp3(x,y,z) make_pair((x), make_pair( (y), (z)))
#define foreach(C, i) for(auto i = (C).begin(); i != (C).end(); i++)
#define xx first
#define yy second
#define clr clear()
#define var(x) cout<< #x << " = "<<x<<"\n";
#define print(x) for_each((x).begin(), (x).end(), [](auto n) { cout<<x<<" " })
typedef int32_t i3;
typedef int64_t i6;
typedef vector<i3> vi;
typedef pair<i3,i3> ii;
typedef vector<pair<i3,i3> > vii;

void recurse(string str, int cnt, vector<string>& vec)
{
	if (cnt == SZ(str))
		vec.push_back(str);
	else
	{
		if (str[cnt] == '?')
		{
			for(char c = '0'; c <= '9'; c++)
			{
				str[cnt] = c;
				recurse(str, cnt + 1, vec);
			}
		}
		else
			recurse(str, cnt + 1, vec);
	}
}

int main()
{
	int tc; cin >> tc;	
	FOR(i, 1, tc + 1)
	{
		string str1, str2;
		cin >> str1 >> str2;
		vector<string> vec1, vec2;
		recurse(str1,0, vec1);
		recurse(str2,0, vec2);
		sort(all(vec1));
		sort(all(vec2));
		int cMin = INT_MAX;
		pair<string,string> ans = {"000", "000"};
		for(int i = 0; i < SZ(vec1); i++)
		{
			for(int j = 0; j < SZ(vec2);j++)
			{
				if (abs(stoi(vec1[i]) - stoi(vec2[j])) < cMin)
				{
					cMin = abs(stoi(vec1[i]) - stoi(vec2[j]));
					ans = make_pair(vec1[i], vec2[j]);
				}
			}
		}
		cout << "Case #" <<i<<": " << ans.first << " " << ans.second << "\n";
	}
	return (0);
}
