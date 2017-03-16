#include <iostream>
#include <cctype>
#include <string>

using namespace std;

const string ex1[3] = {"ejp mysljylc kd kxveddknmc re jsicpdrysi",
		       "rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd",
		       "de kr kd eoya kw aej tysr re ujdr lkgc jv"};

const string ex2[3] = {"our language is impossible to understand",
		       "there are twenty six factorial possibilities",
		       "so it is okay if you want to just give up"};

int main () {

  string map(26,'?');
  
  for (int i=0; i<3; i++)
    for (int j=0; j<ex1[i].size(); j++) 
      if (isalpha(ex1[i][j])) map[ex1[i][j]-'a'] = ex2[i][j];

  map['q'-'a'] = 'z';
  map['z'-'a'] = 'q';

  int runs;
  cin>>runs;

  string s;
  getline(cin,s);
  
  for (int run=1; run<=runs; run++) {
    getline(cin,s);
    for (int i=0; i<s.size(); i++)
      if (isalpha(s[i])) s[i] = map[s[i]-'a'];
    cout << "Case #" << run << ": " << s << endl;
  }   
  
  return 0;
}
