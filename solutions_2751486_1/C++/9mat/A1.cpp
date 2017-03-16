#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <utility>
#include <algorithm>
#include <sstream>

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>


#define FOR(i,n) for(int i = 0, n_ = (n); i < n_; i++)
#define FORS(i,s,n) for(int i = (s), n_ = (n); i < n_; i++)
#define ITER(i,l) for(typeof((l).begin()) i = (l).begin(); i != (l).end(); ++i)


#define X first
#define Y second
#define PB push_back
#define MP make_pair

using namespace std;

template<typename T> inline void updatemax(T &a, T b) { if(a<b) a = b; }
template<typename T> inline void updatemin(T &a, T b) { if(a>b) a = b; }


bool iscon(char c){
  return isalpha(c) && c != 'a' && c != 'e' 
    && c != 'i' && c != 'o' && c != 'u';
}

void process(){
  string s;
  int n;

  cin>>s>>n;
  
  vector< pair<int, int> > mark;

  int count = 0, i = -1;
  FOR(j, s.length()){
    if(!iscon(s[j])){
      if(count >= n) mark.PB(MP(i,j-1));
      count = 0;
      continue;
    }

    if(count == 0) i = j;
    count++;
  }

  if(count>=n) mark.PB(MP(i,s.length()-1));
  
  count = 0;
  FOR(i, mark.size()){
    int l = 0, r = s.length() - 1;
    if(i>0) l = mark[i-1].Y - n + 2;

    int d = mark[i].Y - mark[i].X + 1;
    count += (mark[i].X - l) * (r - mark[i].Y);
    count += (d+1-n)*(mark[i].X - l + r - mark[i].Y);
    count += (d-n+1)*(d-n+2)/2;
  }

  cout<<count<<endl;
}

int main(){
  int T;
  cin >> T;

  FOR(t, T){
    cout<<"Case #"<<t+1<<": ";
    process();
  }
  return 0;
}
