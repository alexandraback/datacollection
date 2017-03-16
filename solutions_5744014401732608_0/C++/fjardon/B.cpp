#include <algorithm>
#include <functional>
#include <iomanip>
#include <iostream>
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

typedef vector<bool> vb;

template <class K, class V>
using dict = unordered_map<K, V>;

template <class K>
using hset = unordered_set<K>;


int main() 
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  ull T;
  cin >> T;
  for(ull t=1; t<=T; ++t) {
    cout << "Case #" << t << ": ";
    ull B, M;
    cin >> B >> M;
    if(M > (1 << (B-2))) {
      cout << "IMPOSSIBLE\n";
      continue;
    }

    cout << "POSSIBLE\n";
    --M;
    cout << "0";
    for(int i=(B-3); i>=0; --i)
      cout << ((M & (1 << i)) ? 1 : 0);
    cout << "1\n";
    for(ull i=2; i<=B; ++i) {
      for(ull j=1; j<=B; ++j)
	cout << ((j>i)?1:0);
      cout << "\n";
    }
  }
}
