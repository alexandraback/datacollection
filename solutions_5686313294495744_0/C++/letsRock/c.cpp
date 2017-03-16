#include <iostream>
#include <algorithm>
#include <vector>

typedef unsigned long long ull;
typedef long long ll;
using namespace std;

int tot = 0;

vector<pair<int,int> > ori;

string p(string s, vector<vector<string> > t){
  string r = s;
  for(int i=0; i<s.size(); i++){
    if(s[i] == '1'){
      int suc = false;
      for(int j=0; j<s.size(); j++){
	if(t[i][0] == t[j][0] && j != i && s[j] == '0'){
	  suc = true; break;
	} 
      }
      if(suc){
	suc = false;
	for(int j=0; j<s.size(); j++){
	  if(t[i][1] == t[j][1] &&  j != i && s[j] == '0'){
	    suc = true; break;
	  }
	}
      } 
      if(suc) r[i] = '0';
    }
  }
  return r;
}

void check(string s, vector<vector<string> > c, int N){
  if(s.size() == N){
    string ss = p(s,c);
    string pre = s;
    while(ss != pre){
      pre = ss;
      ss = p(s,c);
    }
    bool suc = true;
    for(int i=0; i<ss.size(); i++){
      if(ss[i] != '0'){suc = false; break;} 
    }
    if(suc){
      int r = 0;
      for(int i=0; i<s.size(); i++){
	if(s[i] == '1') r++;
      }
      if(r > tot) tot = r;
    }
  }
  else{
    check(s + '1', c,N);
    check(s + '0', c,N);
  }
} 

int main(){

  int T;
  cin >> T;
  for(int i=0; i< T; i++){
    tot = 0;
    string s1,s2;
    int n;
    cin >> n;
    vector<vector<string > > t;
    for(int j=0; j<n; j++){
      cin >> s1 >> s2;
      vector<string> r;
      r.push_back(s1);
      r.push_back(s2);
      t.push_back(r);
    }

    check("",t,n);
    
    
    cout << "Case #" << (i+1) << ": " << tot << endl;
    
  }

}
