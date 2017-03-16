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

bool checkIfCorrect(vector<int>& temp, vector<int>& vec)
{
	bool flag = true;
	for(int k = 0; k <  SZ(temp); k++)
	{
		if (vec[temp[k]-1] != temp[(k+1)%SZ(temp)] && vec[temp[k]-1] != temp[(k - 1 + SZ(temp))%SZ(temp)])
			flag = false;
	}
	return flag;

}

int main()
{
	int tc; cin >> tc;
	FOR(i,1,tc + 1)
	{
		int n, ans = 2; cin >> n;
		vector<int> vec(n);
		REP(i,n)
			cin >> vec[i];
		for(int i = 3; i <= n; i++)
		{
			vector<int> permute;
			for(int j = 0; j < n - i; j++)
				permute.pb(0);
			for(int j = 0; j < i; j++)
				permute.pb(1);
			do
			{
				vector<int> temp;
				for(int i = 0; i < SZ(permute); i++)
				{
					if (permute[i] == 1)	
						temp.pb(i+1);
				}
				do
				{
					if (checkIfCorrect(temp, vec) == true)
						ans = max(ans, SZ(temp));
				}while(next_permutation(all(temp)));
				
			}while(next_permutation(all(permute)));
		}
		cout << "Case #"<<i<<": "<<ans << "\n";
	}
	return (0);
}
