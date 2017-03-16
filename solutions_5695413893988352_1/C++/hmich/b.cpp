#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <cmath>
#include <complex>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <vector>
#pragma warning( disable : 4244 4267 4018 4996 4800 )
//#pragma comment( linker, "/stack:10000000" )
using namespace std; 
typedef vector< int > vi; typedef vector< vector< int > > vvi; typedef vector< string > vs; typedef vector< double > vd;
typedef vector< vd > vvd; typedef long long ll; typedef vector< ll > vll; typedef vector< vll > vvll; typedef pair< int, int > pii;
#define all( v ) (v).begin( ), (v).end( )

ifstream in( "b.in" );
ofstream out( "b.out" );

string a, b;
ll ansa, ansb, ansdiff;
vll ex;

void solve(int idx, ll x, ll y) {
	if (idx == a.size()) {
		if (ansa == -1)
			ansa = x, ansb = y, ansdiff = abs(x - y);
		else {
			ll diff = ansdiff - abs(x - y);
			if (diff > 0 || diff == 0 && ((ansa > x) || (ansa == x) && (ansb > y)))
				ansa = x, ansb = y, ansdiff = abs(x - y);
		}
		return;
	}	
	if (a[idx] == '?') {
		if (b[idx] == '?') {
			if (x < y) {
				solve(idx + 1, x + 9 * ex[idx], y);
			} else if (x > y) {
				solve(idx + 1, x, y + 9 * ex[idx]);
			} else {
				solve(idx + 1, x, y);
				solve(idx + 1, x + ex[idx], y);
				solve(idx + 1, x, y + ex[idx]);
			}
		} else {
			int d = int(b[idx] - '0');
			if (x < y)
				solve(idx + 1, x + 9 * ex[idx], y + d * ex[idx]);
			else if (x > y)
				solve(idx + 1, x, y + d * ex[idx]);
			else {				
				for (int i = max(0, d - 1); i <= min(9, d + 1); ++i) {
					solve(idx + 1, x + i * ex[idx], y + d * ex[idx]);
				}
			}
		}
	} else {
		if (b[idx] == '?') {
			int d = int(a[idx] - '0');
			if (x < y)
				solve(idx + 1, x + d * ex[idx], y);
			else if (x > y)
				solve(idx + 1, x + d * ex[idx], y + 9 * ex[idx]);
			else {
				for (int i = max(0, d - 1); i <= min(9, d + 1); ++i) {
					solve(idx + 1, x + d * ex[idx], y + i * ex[idx]);
				}
			}
		} else {
			solve(idx + 1, x + (a[idx] - '0') * ex[idx], y + (b[idx] - '0') * ex[idx]);
		}		
	}
}

int main() {
	int ntests;
	in >> ntests;
	for (int test = 1; test <= ntests; ++test) {		
		in >> a >> b;
		int lena = a.size(), lenb = b.size();
		while (lena < lenb) a = '0' + a;
		while (lenb < lena) b = '0' + b;
		ex.resize(a.size());
		ex.back() = 1;
		for (int i = int(ex.size()) - 2; i >= 0; --i)
			ex[i] = 10 * ex[i + 1];
		ansa = -1;
		solve(0, 0, 0);
		string stra = to_string(ansa);
		while (stra.size() < lena) stra = '0' + stra;
		string strb = to_string(ansb);
		while (strb.size() < lenb) strb = '0' + strb;
		out << "Case #" << test << ": " << stra << ' ' << strb << "\n";		
	}
	return 0;
}