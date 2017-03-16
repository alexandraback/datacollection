#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
#define forn(i,n) for(int i = 0;i < (int)(n); i++)
#define forsn(i,s,n) for(int i=(int)(s);i<(int)(n);i++)
#define dforn(i,n) for(int i=((int)(n)-1);i>=0;i--)

int n,m,lawn[128][128];
typedef pair<int,int> pii;

string solve()
{
	vector< pair<int, pii> > v;
	forn(i,n) forn(j,m)
		v.push_back(make_pair(lawn[i][j],make_pair(i,j)));
	sort(v.begin(),v.end());

	forn(i,v.size()){
		pii pos = v[i].second; 
		int val = v[i].first;

		int cr = pos.first, cc = pos.second;

		bool row = true, col = true;
		forn(c,m) row &= lawn[cr][c] <= val;
		forn(r,n) col &= lawn[r][cc] <= val;

		if(!row && !col) return "NO";
	}
	return "YES";
}
int main()
{
	int tcases; cin >> tcases;
	forsn(tcase,1,tcases+1){
		cin >> n >> m;
		forn(i,n) forn(j,m) cin >> lawn[i][j];	
		cout << "Case #" << tcase << ": " << solve() << endl;
	}
	return 0;
}
