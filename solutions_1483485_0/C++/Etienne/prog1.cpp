#include <iostream>
#include <string>
#include <map>
#include <cassert>

using namespace std;

void doCase();

// This morning's paper's ink stains my fingers
// My hands grow darker every day

int main()
{
  int cases;
  cin >> cases;
  cin.ignore();

  for(int c=0; c<cases; c++)
    {
      cout << "Case #" << c+1 << ": ";
      doCase();
    }
}

void doCase()
{
  map<char, char> code;
  code['q'] = 'z';
  string encoded ("ejpmysljylckdkxveddknmcrejsicpdrysirbcpcypcrtcsradkhwyfrepkymveddknkmkrkcddekrkdeoyakwaejtysrreujdrlkgcjv");
  string plain = ("ourlanguageisimpossibletounderstandtherearetwentysixfactorialpossibilitiessoitisokayifyouwanttojustgiveup");
  for(int i=0; i<encoded.length(); i++)
    code[encoded[i]] = plain[i];
  for(int i=0; i<26; i++)
    {
      char c = 'a'+i;
      if(code.find(c) == code.end())
	{
	  code[c] = 'q';
	}
    }
  assert(code.size() == 26);

  string s;
  getline(cin, s);
  for(int i=0; i<s.size(); i++)
    {
      if(s[i] == ' ')
	cout << " ";
      else cout << code[s[i]];
    }
  cout << endl;
}
