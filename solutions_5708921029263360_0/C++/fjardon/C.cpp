#include <algorithm>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <limits>
#include <numeric>
#include <map>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;
typedef unsigned long long ull;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef pair<unsigned,unsigned> uu;
typedef pair<ull,ull> ullull;
typedef pair<string,string> ss;
typedef vector<ss> vss;

typedef vector<ull> vull;
typedef vector<bool> vb;

template <class K, class V>
using dict = unordered_map<K, V>;

template <class K>
using hset = unordered_set<K>;

string to_string(ull j, ull p, ull s) {
  stringstream buffer;
  buffer << (j+1) << " " << (p+1) << " " << (s+1);
  return buffer.str();
}


int main() 
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  // Brute-force version
  
  ull T;
  cin >> T;
  for(ull t=1; t<=T; ++t) {
    ull J, P, S, K;
    cin >> J >> P >> S >> K;

    vector<string> days;

    vector<vull> jp(J, vull(P, K));
    vector<vull> js(J, vull(S, K));
    vector<vull> ps(P, vull(S, K));
    vector<vector<vb>> jps(J, vector<vb>(P, vb(S)));
    
    ull j = 0, p = 0, s = 0;
    ull MAX = J*P*S;
    while(true) {
      ull tries = 0;
      while(!jp[j][p] || !js[j][s] || !ps[p][s] || jps[j][p][s]) {
	++tries;
	if(tries > J*P*S)
	  break;
	++j;
	if(j >= J) {
	  j = 0;
	  ++p;
	  if(p >= P) {
	    p = 0;
	    ++s;
	    if(s >= S) {
	      s = 0;
	    }
	  }
	}
      }
      if(tries > J*P*S)
	break;
      if(jp[j][p] && js[j][s] && ps[p][s] && !jps[j][p][s]) {
	-- jp[j][p];
	-- js[j][s];
	-- ps[p][s];
	jps[j][p][s] = true;
	days.push_back(to_string(j, p, s));
	continue;
      }
    }
    
    cout << "Case #" << t << ": " << days.size() << "\n";
    copy(begin(days), end(days), ostream_iterator<string>(cout, "\n"));
  }
}
