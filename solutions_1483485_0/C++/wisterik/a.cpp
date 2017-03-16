#include <iostream>
#include <string>
#include <map>
#include <algorithm>

#define rep(i,n) for(int i = 0; i < n; i++)
#define SZ(v) ((int)(v).size())
#define pb push_back
#define all(v) (v).begin(), (v).end()

using namespace std;

map<char, char> mp;

bool w(char c) { 
  return c == ' ' || c == '\n' || c == '\t' || c == '\r'; 
}

void add(string s, string t){
  rep(i, SZ(s)){
    if(!w(s[i])) mp[s[i]] = t[i];
  }
}

string transform(string s){
  rep(i, SZ(s)){
    if(!w(s[i])) s[i] = mp[s[i]];
  }
  return s;
}

int main(){

  add("ejp mysljylc kd kxveddknmc re jsicpdrysi", "our language is impossible to understand");
  add("rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd", "there are twenty six factorial possibilities");
  add("de kr kd eoya kw aej tysr re ujdr lkgc jv", "so it is okay if you want to just give up");

  add("z", "q");
  add("q", "z");

  int t;
  string g;

  cin >> t;
  getline(cin, g);

  rep(i,t){
    getline(cin, g);
    cout << "Case #" << i+1 << ": " << transform(g) << endl;
  }

  return 0;

}
