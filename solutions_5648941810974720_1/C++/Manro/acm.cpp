// #include <bits/stdc++.h>
#include <algorithm>
#include <iostream>
#include <map>
#define ff first
#define ss second
#define D(x) cout << ">> " << #x << " = >" << x << "<\n"
#define FOR(i,a,b) for ( decltype( a ) i = (a); i < (b); ++i )
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;

pair<char,string> nums[] = {
	{ 'Z', "ZERO" },
	{ 'W', "TWO" },
	{ 'U', "FOUR" },
	{ 'X', "SIX" },
	{ 'G', "EIGHT" },
	{ 'O', "ONE" },
	{ 'H', "THREE" },
	{ 'F', "FIVE" },
	{ 'S', "SEVEN" },
	{ 'N', "NINE" }
};
int numst[] = { 0, 2, 4, 6, 8, 1, 3, 5, 7, 9 };

int main( ) {
	int t;
	string s;

	cin >> t;
	FOR( caseNr, 1, t+1 ) {
		cout << "Case #" << caseNr << ": " ;
		cin >> s;
		int cnt[256] = { 0 };
		for ( char c : s )
			++cnt[c];
		int cntd[10] = { };
		FOR( i, 0, 10 ) {
			char c = nums[i].ff;
			string s = nums[i].ss;
			while ( cnt[c] ) {
				++cntd[numst[i]];
				for ( auto c : s )
					--cnt[c];
			}
		}
		FOR( i, 0, 10 ) {
			FOR( j, 0, cntd[i] )
				cout << i;
		}
		cout << endl;
	}
	return 0;
}