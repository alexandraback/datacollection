#include <map>
#include <cstdio>
#include <string>
#include <iostream>
#include <cstdlib>

using namespace std;

map<char, char> M;

char trans[27] = "yhesocvxduiglbkrztnwjpfmaq";

int slovo(char a) {
  return a >= 'a' && a <= 'z';
}

int main() {
  string t;
  int casen;
  getline(cin, t);
  int cs = 0;
  for (casen = atoi(t.c_str()); casen; --casen) {
    getline(cin, t);
    string sol; 
    for (size_t j = 0; j < t.size(); ++j)
      sol.push_back(t[j] == ' ' ? ' ' : trans[t[j]-'a']);
    cs++;
    cout << "Case #" << cs << ": " << sol << endl;
  }
  
  return 0;
}
