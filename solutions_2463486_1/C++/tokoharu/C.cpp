#include <algorithm>
#include <cmath>
#include <climits>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <stack>
#include <utility>
#include <vector>
using namespace std;


typedef long long LL;
typedef pair<int,int> PII;
#define MP make_pair
#define REP(i,n) for(int i=0;i<(int)n;i++) 
#define EACH(i,c) for(__typeof((c).begin()) i=(c).begin();i!=(c).end();i++) 
#define ALL(c) (c).begin(),(c).end() 


vector<string> data;

void trans(string s) {
  int n = s.size();
  string k = "";
  for(int i=0; i<101-n; i++) k+="0";
  data.push_back(k+s);
  
}


string two(string s) {
  string ret;
  int n = s.size();
  for(int i=0; i<2*n-1; i++) {
    ret += "0";
  }
  for(int i=0; i<n; i++) if(s[i]!='0') {
      for(int j=0; j<n; j++) {
	ret[i+j] += (s[i]-'0') * (s[j]-'0');
      }
  }
  
  return ret;
  
}


void saiki(string t, string s, int sum, int length) {
  if(s.size()+t.size()>=51) return;
  if(sum>=6) return;
  if(t[0]!='0')
    trans(two(t+s));
  
  saiki("0"+t, s+"0", sum, length+1 );
  
  saiki("1"+t, s+"1", sum+1, length+1);
  
}


void init() {
  {
    string t="";
    string s ="2";
    trans("9");
    //    trans("484");
    saiki(t,s,3,1);
    s = "1";
    saiki(t,s,1,1);
    saiki(s,s,2,1);
    s="0";
    saiki(t,s,0,1);
    saiki(s,s,1,1);
    
  }
  
  {
    string s = "2";
    string t = "";
    for(int i=0; i<25; i++) {
      trans(two("2"+t+"0"+t+"2"));
      trans(two("2"+t+"1"+t+"2"));
      trans(two("2"+t+t+"2"));
      t+="0";
    }
    
  }
  sort(ALL(data)); 
}
int solve() {
  string s,t;
  cin>>s>>t;
  
  while(s.size()<=100) s = "0"+s;
  while(t.size()<=100) t = "0"+t;
  
  int ans =upper_bound(ALL(data),t) - upper_bound(ALL(data),s);
  if(binary_search(ALL(data), s)) ans++;
  return ans;
}


int main() {
  init();
  /*
  for(int i=0; i<40; i++) {
    cout<<data[i]<<endl;
    }*/
  
  int t;
  cin>>t;
  REP(i,t) {
    int ans = solve();
    cout<<"Case #"<<i+1<<": "<<ans<<endl;
  }
  
}

