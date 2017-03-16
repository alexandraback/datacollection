#include <bits/stdc++.h>
using namespace std;


#define Size(s) ((int)s.size())
#define rep(i, n) for(int i=0; i<n; ++i)
#define Foreach(i, x) for (__typeof(x.begin()) i = x.begin(); i != x.end(); i++)
#define F first
#define S second
#define X real()
#define Y imag()
#define MP make_pair

template<class P, class Q> inline bool mmin(P &a, Q b) { if (a > b){ a = b; return true;} return false;}
template<class P, class Q> inline bool mmax(P &a, Q b) { if (a < b){ a = b; return true;} return false;}

typedef long long LL;
typedef pair<int, int> pii;

const int MAXn = 100 + 10;
const LL mod = 1e9 + 7;
int n;
string s[MAXn];
bool tek[MAXn][26];
int num[26];
int nxt[26];
bool mark[26];
int ind[MAXn];

inline LL solve()
{
	memset(tek, 0, sizeof(tek));
	rep(i, n) {
		int ind = 0;
		while(ind<Size(s[i])) {
			int j = ind+1;
			while(j<Size(s[i]) && s[i][j]==s[i][ind])
				++j;
			if(tek[i][s[i][ind]-'a'])
				return 0;
			tek[i][s[i][ind]-'a'] = true;
			ind = j;
		}
		tek[i][s[i][0]-'a'] = tek[i][s[i][Size(s[i])-1]-'a'] = false;
	}

	rep(i, 26)
		rep(x, n) for(int y=x+1; y<n; ++y)
		if(tek[x][i] && tek[y][i])
			return 0;

	rep(i, 26)
		nxt[i] = -1;
	
	rep(i, n)
		if(s[i][0]==s[i][Size(s[i])-1])
			++num[s[i][0]-'a'];
		else {
			if(nxt[s[i][0]-'a']!=-1)
				return 0;
			nxt[s[i][0]-'a'] = s[i][Size(s[i])-1]-'a';
		}
}

inline LL solve2()
{
	LL ret = 0;
	rep(i, n)
		ind[i] = i;
//	cerr << n << endl;
	do {
//		cerr << "HI " << endl;
//		rep(i, n)
//			cerr << ind[i] << ' '; cerr << endl;
		string st;
		rep(i, n)
			st += s[ind[i]];
		fill_n(mark, 26, 0);
		int i=0;
		bool ok = true;
		while(i<Size(st)) {
			if(mark[st[i]-'a']) {
				ok = false;
				break;
			}
			mark[st[i]-'a'] = true;
			int j= i +1;
			while(j<Size(st) && st[i]==st[j])
				++j;
			i = j;
		}
//		cerr << st << ' ' << ok << endl;
		ret += ok ? 1 : 0;
	}while(next_permutation(ind, ind+n));

	return ret;
}

int main()
{
	ios_base::sync_with_stdio(false);

	int nt;
	cin >> nt;

	for(int ii=1; ii<=nt; ++ii) {
		cin >> n;
		rep(i, n)
			cin >> s[i];
		cout << "Case #" << ii << ": " << solve2() << endl;
	}

	return 0;
}


