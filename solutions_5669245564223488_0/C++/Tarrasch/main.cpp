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
typedef vector < LL > VLL;
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

const LL MOD = 1000000007;


VS kill(VS trains, VI indices) {
	sort(all(indices));
	reverse(all(indices));
	foru(i, sz(indices)) {
		trains.erase(trains.begin() + indices[i]);
	}
	return trains;
}

VS kill(VS trains, int index) {
	VI indices(1, index);
	return kill(trains, indices);
}

bool is_broken(string train) {
	set <char> sc;
	sc.insert(train[0]);
	foru(i, sz(train)) {
		if(i > 0 && train[i] != train[i-1]) {
			if(sc.count(train[i])) {
				return true;
			}
			sc.insert(train[i]);
		}
	}
	return false;
}


VLL factorial;

bool is_ok(VS trains) {
	int n = sz(trains);
	foru(i, n) {
		string &train = trains[i];
		if(is_broken(train)) return false;
		int m = sz(train);
		foru(j, m) {
			char c = train[j];
			if(c == train[m-1] || c == train[0] ) continue;
			foru(i2, n) {
				if(i2 == i) continue;
				foru(j2, sz(trains[i2])) {
					if(c == trains[i2][j2]) {
						return false;
					}
				}
			}
		}
	}
	return true;
}

LL solve(VS trains) {
	if(!is_ok(trains)) return 0;
	int n = sz(trains);
	foru(i, n) {
		string &train = trains[i];
		int m = sz(train);
		if(m == 1) {
			train.push_back(train[0]);
		} else {
			string new_train;
			new_train.push_back(train[0]);
			new_train.push_back(train[m-1]);
			train = new_train;
		}
	}
	VLL arr(244);
#define CHARS(c) for(char c = 'a'; c <= 'z'; c++)
	CHARS(c) {
		foru(i, n) {
			string &train = trains[i];
			if(train[0] == train[1] && train[0] == c) {
				arr[c]++;
			}
		}
	}
	CHARS(c) {
		if(arr[c] > 0) {
			arr[c] = factorial[arr[c]];
		}
	}
	VI taken0(240);
	VI taken1(240);
	foru(i, n) {
		string &train = trains[i];
		if(train[0] != train[1]) {
			char c0 = train[0];
			char c1 = train[1];
			if(taken0[c0]++) return 0;
			if(taken1[c1]++) return 0;
			while(arr[c0] < 0) { c0 = -arr[c0]; }
			while(arr[c1] < 0) { c1 = -arr[c1]; }
			MAX(arr[c0], 1LL);
			MAX(arr[c1], 1LL);
			arr[c1] *= arr[c0];
			arr[c1] %= MOD;
			arr[c0] = -c1;
		}
	}
	VLL groups;
	CHARS(c) {
		if(arr[c] > 0) {
			groups.push_back(arr[c]);
		}
	}
	LL ans = factorial[sz(groups)];
	foru(i, sz(groups)) {
		ans *= groups[i];
		ans %= MOD;
	}
	return ans;
}

int main(){
	factorial = VLL(105);
	LL x = 1;
	factorial[0] = 1;
	foru(i, 102){
		if(i == 0) continue;
		x*=i;
		x%=MOD;
		factorial[i] = x;
	}
	mr(int, numTestCases);
	sfor(int, testCase, 1, numTestCases+1) {
		mr(int, n);
		VS trains(n);
		cin >> trains;
		cout << "Case #" << testCase << ": " << solve(trains) << endl;
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

