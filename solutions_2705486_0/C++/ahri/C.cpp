/*
ID: ahri1
PROG: C
LANG: C++
*/
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <iostream>
#include <map>
#include <fstream>
#include <set>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
#define sz(X) ((int)(X).size())
#define FOREACH(i,c) for(__typeof(c.begin()) i=(c.begin());i!=(c).end();++i)
template<class T> vector<T> tokenize_to(const string &str) { vector<T> r; T x; istringstream is(str); while (is >> x) r.push_back(x); return r; }
#define junik(X) {sort( (X).begin(), (X).end() ); (X).erase( unique( (X).begin(), (X).end() ), (X).end() ); }

vector<string> dict;
vector<int> len;
int N;

int diff (string a, string b, int bN) {
  int ret =0;
  for(int i=0;i<bN;++i) {  
    int x = abs(a[i]-b[i]);
    if (x==0) continue;
    if (x>4) ret++;
    else return -1;
  }
  return ret;
}

int d[4001];

void solve(){
  string S;
  cin >> S;
  int n = sz(S);
  for(int i=0;i<=n;++i) d[i]=n;
  d[0]=0;
  for (int j =0;j<n;j++) {    
    for(int i=0;i<N;++i) {
      //if (i==122757) cout << dict[i] << " " << len[i] <<" " <<  S << endl;
      if (len[i]>sz(S)) continue;
      int temp = diff(S, dict[i], len[i]);
      //if (i==122757) cout << temp << endl;
      if (temp==-1) continue;
      d[j+len[i]]=min(d[j+len[i]], d[j]+temp);
    }
    S=S.substr(1);
  }
  cout << d[n] << endl;
}

int main() {

  cin.sync_with_stdio(0);
  ifstream fin("garbled_email_dictionary.txt");
  string x;
  while (fin.good()) {
    fin >> x;
    dict.push_back(x);
    len.push_back(sz(x));
  }
  
  N=sz(dict);
 
  
  int T;
  cin >> T;
  for (int i=0;i<T;i++) {
    cout << "Case #" << i+1 << ": ";
    solve();
  }
  
  return 0;
}
