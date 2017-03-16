#include <algorithm>
#include <bitset>
#include <cctype>
#include <cerrno>
#include <clocale>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cwchar>
#include <cwctype>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <ostream>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <utility>
#include <vector>

using namespace std;

#define mp make_pair
#define pb push_back
#define rep(i,m,n) for(long long i = m; i < n; ++i)
#define re return
#define fi first
#define se second
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define sqr(x) ((x) * (x))
#define eps 1e-7
#define FOR(it,c) for(typeof((c).begin()) it=(c).begin();it!=(c).end();++it)

typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<string> vs;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef vector<vll> vvll;
typedef vector<vii> vvii;
bool vow(char cha){
  re cha=='a'||cha=='e'||cha=='i'||cha=='o'||cha=='u';
}
int main() {
  ios_base::sync_with_stdio(false);
  ifstream fin("submission.in");
  ofstream fout("submission.out");
  int T;
  fin >> T;
  for (int TAT = 1; TAT < T + 1; ++TAT) {
    string s;
    fin>>s;
    int L=sz(s), n,qi=-1;
    fin>>n;
    queue<ii> st;
    rep(i,0,L+1){
      if(qi!=-1&&(i==L||vow(s[i]))){
        if(i-qi>=n) st.push(mp(qi,i));
        qi=-1;
      }else if(i<L&&qi==-1&&!vow(s[i])){
        qi=i;
      }
    }
    ll res=0;
    for(int i=0;i<L&&!st.empty();++i){
      ii te=st.front();
      if(te.se-i>=n){
        res+=ll(L+1-max(te.fi,i)-n);//pay attention!
      }else{
        st.pop();
        --i;
      }
    }
    fout << "Case #" << TAT << ": " << res << endl;
  }
  return 0;
}
