#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <set>

using namespace std;

int main()
{
  int t, ca, i;
  string s, letter, word;
  ifstream fin;
  ofstream fout;
  
  fin.open("input.txt");
  fout.open("output.txt");
  fin >> t;
  for (ca = 1; ca <= t; ++ca) {
    cout << "Case #" << ca << ": ";
    fout << "Case #" << ca << ": ";
    fin >> s;
    //cout << s << endl;
    if (s.length() == 1) {
      cout << s << endl;
      fout << s << endl;
    }
    else {
      word = s[0];
      //cout << word << endl;
      for (i = 1; i < s.length(); ++i) {
	if (s[i] < word[0]) word.push_back(s[i]);
	else {
	  letter = s[i];
	  letter.append(word);
	  word = letter;
	}
      }
      cout << word << endl;
      fout << word << endl;
    }
  }
  fin.close();
  fout.close();
  return 0;
}
