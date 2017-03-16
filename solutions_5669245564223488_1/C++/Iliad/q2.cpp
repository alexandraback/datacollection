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
bool tek2[MAXn][26];
int num[26];
int nxt[26];
bool mark[26];
int ind[MAXn];
bool canSt[26];
LL fac[MAXn];
bool hav[26], used[26];

inline LL solve2()
{
	LL ret = 0;
	rep(i, n)
		ind[i] = i;
	do {
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
		ret += ok ? 1 : 0;
	}while(next_permutation(ind, ind+n));

	return ret;
}

inline LL solve()
{
	memset(tek, 0, sizeof(tek));
	memset(tek2, 0, sizeof(tek2));	
	rep(i, 26) {
		hav[i] = used[i] = num[i] = 0;
		nxt[i] = -1;
		canSt[i] = 1;
	}
	rep(i, n) rep(j, Size(s[i])) s[i][j] -= 'a';
	rep(i, n) {
		int ind = 0;
		while(ind<Size(s[i])) {
			if(tek[i][s[i][ind]])
				return 0;
			tek[i][s[i][ind]] = tek2[i][s[i][ind]] = true;
			int j = ind+1;
			while(j<Size(s[i]) && s[i][j]==s[i][ind])
				++j;
			ind = j;
		}
		tek[i][s[i][0]] = tek[i][s[i][Size(s[i])-1]] = false;
	}

	rep(i, 26)
		rep(x, n) rep(y, n) if(x!=y)
		if(tek2[x][i] && tek[y][i])
			return 0;

	rep(i, n)
		if(s[i][0]==s[i][Size(s[i])-1])
			++num[s[i][0]], hav[s[i][0]]=true;
		else {
			if(nxt[s[i][0]]!=-1)
				return 0;
			hav[s[i][0]] = hav[s[i][Size(s[i])-1]] = true;
			nxt[s[i][0]] = s[i][Size(s[i])-1];
			canSt[s[i][Size(s[i])-1]] = false;
		}

//	rep(i, 26)
//		cerr << hav[i]; cerr << endl;

	fac[0] = 1;
	rep(i, MAXn-1)
		fac[i+1] = fac[i] * (i+1) % mod;

	fill_n(mark, 26, 0);
	LL ret = 1;
	int cnt = 0;
	rep(i, 26)
		if(canSt[i] && (num[i] || nxt[i]!=-1)) {
			int j = i;
			LL cur = fac[num[j]];
			used[j] = true;
			while(nxt[j]!=-1) {
				j = nxt[j];
				used[j] = true;
				cur = cur * fac[num[j]] % mod;
			}
			ret = ret * cur % mod;
			++cnt;
		}

//	rep(i, 26)
//		cerr << hav[i] << ' '; cerr << endl;	

	rep(i, 26)
		if(hav[i] && !used[i]) {
//			cerr << i << "? " << endl;
			return 0;
		}

//	cerr << "NOmORE " << endl;

	ret = ret * fac[cnt] % mod;

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
		cout << "Case #" << ii << ": " << solve() << endl;
	}

	return 0;
}
