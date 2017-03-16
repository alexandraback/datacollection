#include <cstdlib>
#include <cmath>
#include <map>
#include <utility>
#include <set>
#include <sstream>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>
#include <list>
#include <algorithm>
#include <functional>
#include <stack>
#include <queue>
#include <numeric>
using namespace std;

#define	mp						make_pair
#define	pb						push_back
#define	bg						begin
#define	ed						end
#define	fs						first
#define	sc						second
#define	sz(x)					((int)((x).size()))
#define	For(i,a,b)				for(int i=(a);i<(b);++i)
#define	rep(i,n)				For(i,0,(n))
#define	rFor(i,a,b)				for(int i=(a);i>=(b);--i)
#define	rrep(i,n)				rFor(i,(n),0)
#define	all(v)					(v).begin(),(v).end()
#define	ITER(type)				type::iterator
#define	EACH(type,cont,it)		for(ITER(type) it=(cont).bg,s___=(cont).ed;it!=s___;++it)

typedef	long long				LL;
typedef	vector<int>				VI;
typedef	vector<LL>				VLL;
typedef	vector<vector<int> >	VVI;
typedef	vector<bool>			VB;
typedef	vector<string>			VS;
typedef	list<int>				LI;
typedef	list<LL>				LLL;
typedef	list<string>			LS;
typedef	pair<int,int>			PII;


int maxbanana;

long double calc(int L, const map<char, long double> &keyset, const string &tword, string &typed, long double exp)
{
	if(!L) {
		size_t pos = 0;
		int matched = 0;
		while((pos = typed.find(tword, pos)) != string::npos) {
			++matched;
			++pos;
		}
		maxbanana = max(maxbanana, matched);
		return exp * (maxbanana - matched);
	}

	long double res = 0;
	for(map<char, long double>::const_iterator it = keyset.begin() ; it != keyset.end() ; ++it) {
		typed.pb(it->first);
		res += calc(L - 1, keyset, tword, typed, exp * it->second);
		typed.pop_back();
	}
	return res;
}

double solve()
{
	int K, L, S;
	string keyboard;
	string targetword;

	cin >> K >> L >> S;
	cin >> keyboard;
	cin >> targetword;

	long double res = 0.0;

	map<char, long double> keyset;
	rep(i, keyboard.size())
		keyset[keyboard[i]] += 1;
	for(map<char, long double>::iterator it = keyset.begin() ; it != keyset.end() ; ++it)
		it->second /= keyboard.size();

	string typed;
	maxbanana = 0;
	// calc maxbanana
	calc(S, keyset, targetword, typed, 1);
	return calc(S, keyset, targetword, typed, 1);
}

int main()
{
	int T;

	cin >> T;

	rep(i, T)
		printf("Case #%d: %.10f\n", i + 1, (double)solve());
}
