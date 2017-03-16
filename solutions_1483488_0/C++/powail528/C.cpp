

#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(), (c).end()

bool is_match(string &A, string &B){
  int len = A.size();
  for(int st = 0; st < len; st++){
    bool flag = true;
    for(int i = st, j = 0; j < len; ++i %= len, ++j){
      if( A[i] != B[j] ){
	flag = false;
	break;
      }
    }
    if( flag )
      return true;
  }
  return false;
}

int main() {
  int T;
  cin >> T;
  int A,B;
  stringstream ss;
  string Astr,Bstr;
  for(int caseNum = 1; caseNum <= T; caseNum++){
    cout << "Case #" << caseNum << ": ";
    cin >> A >> B;
    int ans = 0;
    for(int i = A; i < B; i++){
      for(int j = i+1; j <= B; j++){
	ss.str("");
	ss << i; Astr = ss.str();
	ss.str("");
	ss << j; Bstr = ss.str();
	if( Astr.size() == Bstr.size() && is_match(Astr,Bstr) )
	  ans++;
      }
    }
    cout << ans << endl;
  }
  
  return 0;
}
