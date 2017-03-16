//Arash Rouhani
#define _GLIBCXX_DEBUG
//#define NDEBUG
#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <sstream>
#include <string>
#include <math.h>
#include <fstream>
#include <numeric>
#include <set>
#include <queue>
#include <stack>
#include <map>
#include <bitset>
#include <assert.h>

using namespace std;

typedef long long LL;
typedef pair < int, int > II;
typedef pair < int, II > I_II;
typedef vector < int > VI;
typedef vector < II > VII;
typedef vector < VI > VVI;
typedef vector < VII > VVII;
typedef vector < VVI > VVVI;
typedef vector < string > VS;
typedef vector < VS > VVS;
typedef vector < char > VC;
typedef vector < VC > VVC;
typedef stringstream SS;
typedef set < int > SI;
typedef set < SI > SSI;
typedef vector < SI > VSI;

#define sz(c) (int((c).size()))
#define all(c) (c).begin(), (c).end()
#define tr(c, it) for(typeof((c).begin()) it = (c).begin(); it!=(c).end(); it++)
#define sfor(type, e, start, stop) for(type e=start; e<stop; e++)
#define foru(var, stop) sfor(int, var, 0, stop)
#define sford(type, e, start, stop) for(type e=start; e>=stop; e--)
#define ford(var, start) sford(int, var, start, 0)
#define mp make_pair
#define error(msg) {cout << msg << endl; throw;}
#define mr(type, v1) \
  type v1; \
  cin >> v1;
#define mr2(type, v1, v2) \
  type v1, v2; \
  cin >> v1 >> v2;
#define mr3(type, v1, v2, v3) \
  type v1, v2, v3; \
  cin >> v1 >> v2 >> v3;
#define mr4(type, v1, v2, v3, v4) \
  type v1, v2, v3, v4; \
  cin >> v1 >> v2 >> v3 >> v4;
#define mr5(type, v1, v2, v3, v4, v5) \
  type v1, v2, v3, v4, v5; \
  cin >> v1 >> v2 >> v3 >> v4 >> v5;
#define MAX(l, r) l = max((l),(r))
#define MIN(l, r) l = min((l),(r))

template <class T> string toString(T n){ostringstream oss;oss<<n;oss.flush();return oss.str();}
template <class T> string vectorToString(vector < T > v, string seperator = " "){
  ostringstream oss;
  tr(v, e) {
    oss << *e << seperator;
  }
  oss.flush();
  return oss.str();
}
template <class T1, class T2> std::ostream& operator << ( std::ostream& out,
                        const std::pair< T1, T2 >& rhs )
{
    out << "(" << rhs.first << ", " << rhs.second << ")";
    return out;
}

template <class T> std::ostream& operator << ( std::ostream& out,
                                               const vector< T >& rhs )
{
	cout << "[ ";
	tr(rhs, it){
		out << *it << " ";
	}
	cout << "]";
	return out;
}


template <class T> std::istream& operator >> ( std::istream& in,
                        vector< T >& rhs )
{

    if(false /* sz(rhs) == 0 */){
      // Do getline and assume that's our elements
      string s;
      getline(in, s);
      if(s == "\n" || s == "") getline(in, s);
      stringstream sin(s);
      T temp;
      while(sin >> temp) rhs.push_back(temp);
    } else {
      // read fixed number of elements
      tr(rhs, it) in >> *it;
    }
    return in;
}

template <class InIt> string rangeToString(InIt begin, InIt end, string seperator = " "){
  ostringstream oss;
  for(InIt it = begin; it != end; it++)
    oss << *it << seperator;
  oss.flush();
  return oss.str();
}

int nDirs = 4; // Change to 8 if needed
int yDirs[] = { 1, 0, -1, 0, 1, -1, -1, 1 };
int xDirs[] = { 0, 1, 0, -1, 1, 1, -1, -1 };

int reverseDir(int dir) {
  assert(0 <= dir && dir < nDirs);
  return (dir&4) // Type of diagonal or not
       + (dir + 2)%4;
}

string solve(LL A, LL B) {
	LL gcd = __gcd(A, B);
	A/= gcd;
	B/= gcd;
	//cout << A << "/" << B << endl;
	if(__builtin_popcount(B) > 1) {
		return "impossible";
	}
	while(A>1) {
		A/=2;
		B/=2;
		//cout << A << "/" << B << endl;
	}
	int ans = 0;
	while((B&1) == 0) {
		ans++;
		B/=2;
		//cout << B << endl;
	}
	return toString(ans);
}

int main(){
	mr(int, numTestCases);
	sfor(int, testCase, 1, numTestCases+1) {
		LL A, B;
		scanf("%lld/%lld", &A, &B);
		cout << "Case #" << testCase << ": " << solve(A, B) << endl;
	}
}

/*

4
30.0 1.0 2.0
30.0 2.0 100.0
30.50000 3.14159 1999.19990
500.0 4.0 2000.0


Case #1: 1.0000000
Case #2: 39.1666667
Case #3: 63.9680013
Case #4: 526.1904762


 */

