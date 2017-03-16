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


pair<LL, LL>	box[5];
pair<LL, LL>	toy[200];
int		N;
int		M;

LL rec(int bi, int ti)
{
	LL	res = 0;

	if(bi == N || ti == M)
		return 0;

	if(box[bi].sc == toy[ti].sc) {
		if(box[bi].fs == toy[ti].fs) {
			res = max(res, min(box[bi].fs, toy[ti].fs) + rec(bi + 1, ti + 1));
		} else if(box[bi].fs < toy[ti].fs) {
			LL	tmp = box[bi].fs;
			toy[ti].fs -= tmp;
			res = max(res, tmp + rec(bi + 1, ti));
			toy[ti].fs += tmp;
		} else {
			LL	tmp = toy[ti].fs;
			box[bi].fs -= tmp;
			res = max(res, tmp + rec(bi, ti + 1));
			box[bi].fs += tmp;
		}
	}
	res = max(res, rec(bi + 1, ti));
	res = max(res, rec(bi, ti + 1));

	return res;
}

LL solve()
{
	int	N, M;

	cin >> N >> M;

	rep(i, N)
		cin >> box[i].fs >> box[i].sc;
	rep(i, N - 1) {
		if(box[i].sc == box[i+1].sc) {
			box[i].fs += box[i+1].fs;
			For(j, i + 1, N - 1)
				box[j] = box[j+1];
			--N;
		}
	}

	rep(i, M)
		cin >> toy[i].fs >> toy[i].sc;
	rep(i, M - 1) {
		if(toy[i].sc == toy[i+1].sc) {
			toy[i].fs += toy[i+1].fs;
			For(j, i + 1, M - 1)
				toy[j] = toy[j+1];
			--M;
		}
	}

	return rec(0, 0);
}

int main( void )
{
	int	T;

	cin >> T;
	rep(i, T) {
		cout << "Case #" << (i+1) << ": " << solve() << endl;
	}
}
