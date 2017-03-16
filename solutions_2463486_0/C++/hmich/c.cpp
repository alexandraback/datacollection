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

ifstream in( "c.in" );
ofstream out( "c.out" );

bool less_num(string const & a, string const & b) {
    if (a.size() < b.size()) return true;
    if (a.size() > b.size()) return false;
    return lexicographical_compare(all(a), all(b));
}

bool is_palindrome(string const & s)
{
    for (int i = 0; i < s.size() / 2; ++i)
        if (s[i] != s[s.size() - i - 1])
            return false;
    return true;
}

string mul(string const & a, string const & b) {
    string res(a.size() + b.size() - 1, 0);
    for (int i = 0; i < a.size(); ++i) {
        int c = 0;
        for (int j = 0; j < b.size(); ++j) {
            res[i+j] = (a[a.size()-i-1] - '0') * (b[b.size()-j-1] - '0') + res[i+j] + c;
            c = res[i+j] / 10;
            res[i+j] = res[i+j] - c*10;
        }
        if (c) {
            if (i + b.size() >= res.size())
                res.push_back(c);
            else
                res[i+b.size()] = c;
        }
    }
    for (int i = 0; i < res.size(); ++i) res[i] += '0';
    reverse(all(res));
    return res;
}

int main() {
    vector<string> fs;
    for (int i = 1; i < 10000; i *= 10) {
        for (int j = i/10; j < i; ++j) {
            string s;
            if (j) {
                ostringstream oss;
                oss << j;
                s = oss.str();
            }
            string num = s;
            reverse(all(s));
            for(int k = 0; k < 10; ++k)
            {
                num.push_back(k+'0');
                num += s;
                string square = mul(num, num);

                if (is_palindrome(square))
                    fs.push_back(square);
                num.resize(s.size());
            }
        }
        for (int j = i; j < i * 10; ++j) {
            ostringstream oss;
            oss << j;
            string s = oss.str();
            string num = s;
            reverse(all(s));
            num += s;
            string square = mul(num, num);
            if (is_palindrome(square))
                fs.push_back(square);
        }
    }
    int ntest;
    in >> ntest;
    for (int test = 1; test <= ntest; ++test) {
        string l, r;
        in >> l >> r;
        int res = std::distance(lower_bound(all(fs), l, less_num), upper_bound(all(fs), r   , less_num));
        out << "Case #" << test << ": " << res << "\n";
    }
    return 0;
}