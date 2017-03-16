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

ifstream in( "a.in" );
ofstream out( "a.out" );

int main() {
    int ntests;
    in >> ntests;    
    for (int test = 1; test <= ntests; ++test) {                
		string str;
		in >> str;
		char cnt[256] = {};
		for (char ch : str) cnt[ch]++;
		int res[10] = {};
		res[0] = cnt['Z'];
		res[2] = cnt['W'];
		res[6] = cnt['X'];
		res[8] = cnt['G'];
		res[3] = cnt['H'] - res[8];
		res[4] = cnt['R'] - res[0] - res[3];
		res[5] = cnt['F'] - res[4];
		res[1] = cnt['O'] - res[0] - res[2] - res[4];
		res[7] = cnt['S'] - res[6];
		res[9] = (cnt['N'] - res[1] - res[7]) / 2;
		assert(accumulate(res, res + 10, 0) == accumulate(cnt, cnt + 256, 0));
		out << "Case #" << test << ": ";
		for (int i = 0; i < 10; ++i)
			for (int j = 0; j < res[i]; ++j)
				out << i;
		out << "\n";
    }
    return 0;
}