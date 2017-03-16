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

  int count = 0;

  FOR(i, s.length()){
    int count2 = 0;
    FORS(j, i, s.length()) {
      if(iscon(s[j])) count2++; else count2 = 0;
      if(count2 == n){
	count += s.length()-j;
	break;
      }
    }
  }

  cout<<": "<<count<<endl;
}

int main(){
  int T;
  cin >> T;

  FOR(t, T){
    cout<<"Case #"<<t+1;
    process();
  }
  return 0;
}
