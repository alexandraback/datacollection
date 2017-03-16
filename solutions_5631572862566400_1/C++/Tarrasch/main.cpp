//Arash Rouhani
//#define _GLIBCXX_DEBUG
#define NDEBUG
#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <sstream>
#include <string>
#include <math.h>
#include <cmath>
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
typedef vector < double > VD;
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
#define PRINT(x) std::cout << #x << " = " << x << std::endl;
#define ECHO(x) std::cout << x << std::endl;

int count_bits (unsigned int x) { return __builtin_popcount(x); } // mnemonic reasons
int toInt(string s) { stringstream ss; ss << s; int res; ss >> res; return res; }
LL toLL(string s) { stringstream ss; ss << s; LL res; ss >> res; return res; }
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

template <class T1, class T2> std::istream& operator >> ( std::istream& in,
							  std::pair< T1, T2 >& rhs  )
{
	// This is not really the opposide of the (<<) operator,
	// since we read just as whitespace seperated input.
    in >> rhs.first >> rhs.second;
    return in;
}


template <class T> std::ostream& operator << ( std::ostream& out,
                                               const vector< T >& rhs )
{
	out << "[ ";
	tr(rhs, it){
		out << *it << " ";
	}
	out << "]";
	return out;
}

template <class T> std::ostream& operator << ( std::ostream& out,
                                               const set< T >& rhs )
{
	out << "{ ";
	tr(rhs, it){
		out << *it << " ";
	}
	out << "}";
	return out;
}


template <class T> std::istream& operator >> ( std::istream& in,
                        vector< T >& rhs )
{
    tr(rhs, it) in >> *it;
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
string arrowDirs="v>^<"; // arrowDirs.find('^') == 2; arrowDirs.find('a') == -1;

int reverseDir(int dir) {
  assert(0 <= dir && dir < nDirs);
  return (dir&4) // Type of diagonal or not
       + (dir + 2)%4;
}

typedef pair < LL, LL > LL_LL;
typedef multiset < LL_LL > MSLL_LL;
typedef set < II > SII;
typedef map < LL, int> MII;
typedef vector < LL > VLL;



int try_circle(int n, VI bffs) {
	int best = 3;
	foru(i, n) {
		int curr_kid = i;
		foru(j, n+4) {
				curr_kid = bffs[curr_kid];
				if(curr_kid == i) {
					best = max(best, j+1);
					break;
				}
		}
	}
	return best;
}


int try_mutual_fittings(int n, VI bffs) {
	VI mutuals(n);
	foru(i, n) {
		if(bffs[bffs[i]] == i) mutuals[i]=true;
	}
	VI score(n);
	foru(i, n) {
		int curr_kid = i;
		if(mutuals[i]) continue;
		foru(j, n+4) {
				curr_kid = bffs[curr_kid];
				if(mutuals[curr_kid]) {
					score[curr_kid] = max(score[curr_kid], j+1);
					break;
				}
		}
	}
	int res = 0;
	foru(i, n) if(mutuals[i]) res += 1 + score[i];
	return res;
}

int solveCase() {
	mr(int, n);
	VI bffs(n);
	cin >> bffs;
	foru(i,n) bffs[i]--;
	return max(try_circle(n, bffs), try_mutual_fittings(n, bffs));
}

int main(){
	mr(int, numCases);
	foru(tc, numCases) {
		cout << setprecision(100);
		cout << "Case #" << tc+1 << ": " << solveCase() << endl;
	}
}

