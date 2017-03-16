#include <iostream>
#include <map>
#include <set>
#include <string>

using namespace std;

map<char, char> tr;
map<char, char> reversetr;

void train(string in, string out) {
  for(int i=0;i<in.size();++i) {
    char left = in[i];
    char right = out[i];
    tr[right] = left;
    reversetr[left] = right;
  }
}

void lastletter() {
  char missingin = ' ';
  char missingout = ' ';
  for(char i='a';i<='z';++i) {
    if (tr.find(i)==tr.end()) {
      missingin = i;
    }
    if (reversetr.find(i)== reversetr.end()) {
      missingout = i;
    }
  }
  tr[missingin] = missingout;
  reversetr[missingout] = missingin;
}

void print() {
  map<char, char>::iterator i;
  for(i=tr.begin();i!=tr.end();++i) {
    cerr<<i->first << i->second <<endl;
  }
  cerr<<tr.size()<<endl;
}


int main(int argc, char** argv) {

  train("y qee", "a zoo");
  train("ejp mysljylc kd kxveddknmc re jsicpdrysi",
        "our language is impossible to understand");
  train("rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd",
        "there are twenty six factorial possibilities");
  train("de kr kd eoya kw aej tysr re ujdr lkgc jv",
        "so it is okay if you want to just give up");
  lastletter();
  //print();

  int ntc;
  string line;
  cin>>ntc;
  getline(cin, line); // remove end-of-line
  for(int tc=0;tc<ntc;++tc) {
    cout<<"Case #"<<tc+1<<": ";
    getline(cin, line);
    for(int i=0;i<line.size();++i) {
      char left = line[i];
      char right = left;
      if (reversetr.find(left) != reversetr.end()) {
        right = reversetr[left];
      }
      cout<<right;
    }
    cout<<endl;
  }
  return 0;
}
