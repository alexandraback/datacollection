// Author: Xujie Si
// Email: six@gatech.edu
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <utility>
using namespace std;

#define FOR(i,X) for(int i=0;i<(X);++i)
#define PB(X) push_back( (X) )

typedef long long LL;
typedef vector<int> VI;

priority_queue<int> maxQ; // largest on the top
priority_queue<int, VI, greater<int> > minQ; // smallest on the top


string Sv(int i, string& s){
  if(i == 0){
    return "";
  }

  int x = s[0];
  int j = -1;
  for(int k = 0; k < i; ++k){
    if(x <= s[k]){
      x = s[k];
      j = k;
    }
  }

  string res = "";
  res +=s[j];

  string suffix = "";
  for(int k=j+1; k<i;++k){
    suffix += s[k];
  }

  return res + Sv(j, s) + suffix;


}


void solve(){
	// exact implementation appears here
  string s;
  cin >> s;

  cout << Sv(s.length(), s) << endl;

}

int main()
{
  int cs = 0, T;
  scanf("%d",&T);
  while(++cs <= T){
    printf("Case #%d: ", cs);
    solve();
  }
  return 0;
}
