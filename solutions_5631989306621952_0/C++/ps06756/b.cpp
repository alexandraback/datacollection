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
	FOR(i,1,tc + 1)
	{
		string str, ans;
		cin >> str;
		char prev = str[0];
		ans = str[0];
		FOR(i,1, SZ(str))
		{
			if (str[i] >= ans[0])
				ans = str[i] + ans;
			else
				ans = ans + str[i];
		}
		cout << "Case #"<<i<<": "<<ans << "\n";
	}
	return (0);
}
