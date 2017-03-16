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
int ansa, ansb;
string stra, strb;

void solve(int idx) {
	if (idx == a.size() + b.size()) {
		int x = 0, y = 0;
		for (int i = 0; i < a.size(); ++i) {
			x = x * 10 + a[i] - '0';
		}
		for (int i = 0; i < b.size(); ++i) {
			y = y * 10 + b[i] - '0';
		}
		if (ansa == -1)
			ansa = x, ansb = y, stra = a, strb = b;
		else {
			int diff = abs(ansa - ansb) - abs(x - y);
			if (diff > 0 || diff == 0 && ((ansa > x) || (ansa == x) && (ansb > y)))
				ansa = x, ansb = y, stra = a, strb = b;
		}
		return;
	}
	if (idx < a.size()) {
		if (a[idx] == '?') {
			for (int i = 0; i <= 9; ++i) {
				a[idx] = '0' + i;
				solve(idx + 1);
			}
			a[idx] = '?';
		} else {
			solve(idx + 1);
		}
	} else {
		int idxb = idx - a.size();
		if (b[idxb] == '?') {
			for (int i = 0; i <= 9; ++i) {
				b[idxb] = '0' + i;
				solve(idx + 1);
			}
			b[idxb] = '?';
		}
		else {
			solve(idx + 1);
		}	
	}
}

int main() {
	int ntests;
	in >> ntests;
	for (int test = 1; test <= ntests; ++test) {		
		in >> a >> b;
		ansa = -1;
		solve(0);		
		out << "Case #" << test << ": " << stra << ' ' << strb << "\n";		
	}
	return 0;
}