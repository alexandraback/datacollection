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

int main()
{
	int tc; cin >> tc; 
	FOR(i,1,tc+1)
	{
		map<char, int> mp;
		vector<pair<string,char> > vec;
		vector<int> yo = {0,2,8,6,4,5,7,1,3,9};
		vector<int> ans;
		vec.push_back(mp("ZERO", 'Z'));
		vec.pb(mp("TWO",'W'));	
		vec.pb(mp("EIGHT", 'G'));
		vec.pb(mp("SIX", 'X'));
		vec.pb(mp("FOUR", 'U'));
		vec.pb(mp("FIVE",'F'));
		vec.pb(mp("SEVEN", 'V'));
		vec.pb(mp("ONE", 'O'));
		vec.pb(mp("THREE", 'T'));
		vec.pb(mp("NINE", 'N'));
		string str; cin >> str;
		REP(i, SZ(str))
			mp[str[i]]++;
		int index = 0;
		for(pair<string,char> p : vec)
		{
			bool flag = true;
			for(auto it = mp.begin(); it != mp.end(); it++)
			{
				if (it->second != 0)
					flag = false;
			}
			if (flag == true)
				break;
			int cnt = mp[p.second]/count(all(p.first), p.second);
			for(int j = 0; j < cnt; j++)
				ans.pb(yo[index]);
			for(char c : p.first)
				mp[c] -= cnt;
			index++;
		}
		sort(all(ans));
		cout << "Case #"<<i<<": ";
		for(int num : ans)
			cout << num;
		cout << "\n";
	}
	return (0);
}
