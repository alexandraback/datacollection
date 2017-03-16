#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <utility>
#include <algorithm>
#include <boost/algorithm/string.hpp>
#include <boost/lexical_cast.hpp>

using namespace std;

int main(){
  map<char,char> trans;
  vector<string> from(4), to(4);

  set<char> a1,a2;
  string alpha("abcdefghijklmnopqrstuvwxyz");
  for(int i = 0 ; i < static_cast<int>(alpha.size()); i++){
    a1.insert(alpha[i]);
    a2.insert(alpha[i]);
  }

  from[0] = string("y qee");
  from[1] = string("ejp mysljylc kd kxveddknmc re jsicpdrysi");
  from[2] = string("rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd");
  from[3] = string("de kr kd eoya kw aej tysr re ujdr lkgc jv");
  to[0] = string("a zoo");
  to[1] = string("our language is impossible to understand");
  to[2] = string("there are twenty six factorial possibilities");
  to[3] = string("so it is okay if you want to just give up");
  
  for(int i = 0; i < 4; i++) {
    vector<string> f,t;
    boost::algorithm::split(f, from[i], boost::is_space());
    boost::algorithm::split(t, to[i], boost::is_space());
    for(int j = 0; j < static_cast<int>(f.size()); j++) {
      for(int k = 0; k < static_cast<int>(f[j].size()); k++) {
	trans[f[j][k]] = t[j][k];
	set<char>::iterator l;
	if((l = a1.find(f[j][k])) != a1.end()) a1.erase(l);
	if((l = a2.find(t[j][k])) != a2.end()) a2.erase(l);
      }
    }
  }
  if(a1.size() == 1) {
    trans[*(a1.begin())] = *(a2.begin());
  }
  trans[' '] = ' ';
  /*
  map<char,char>::iterator i;
  for(i = trans.begin(); i != trans.end(); ++i) {
    cout << i->first << " " << i->second << endl;
  }
  */

  string s;
  int num_cases;
  getline(cin,s);
  num_cases = boost::lexical_cast<int>(s);
  for(int i = 0; i < num_cases; i++){
    getline(cin,s);
    string translate(string,map<char,char>);
    string t = translate(s,trans);
    cout << "Case #" << i+1 << ": " << t << endl;;
  }
}

string translate(string from, map<char,char> trans) {
  string r;
  for(int i = 0; i < static_cast<int>(from.size()); i++) {
    r.push_back(trans[from[i]]);
  }
  return r;
}
