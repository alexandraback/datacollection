
#include <iostream>
#include <vector>
#include <fstream>
#include <set>
#include <algorithm>
using namespace std;

using vi = vector<int>;

# define print(...)

string solve(string S)
{
  string res;
  multiset<char> cs(S.begin(), S.end());
  while (cs.find('Z') != cs.end())
  {
    cs.erase(cs.find('Z'));
    cs.erase(cs.find('E'));
    cs.erase(cs.find('R'));
    cs.erase(cs.find('O'));
    res += '0';
  }
  while (cs.find('X') != cs.end())
  {
    cs.erase(cs.find('S'));
    cs.erase(cs.find('I'));
    cs.erase(cs.find('X'));
    res += '6';
  }
  while (cs.find('W') != cs.end())
  {
    cs.erase(cs.find('T'));
    cs.erase(cs.find('W'));
    cs.erase(cs.find('O'));
    res += '2';
  }
  while (cs.find('G') != cs.end())
  {
    cs.erase(cs.find('E'));
    cs.erase(cs.find('I'));
    cs.erase(cs.find('G'));
    cs.erase(cs.find('H'));
    cs.erase(cs.find('T'));
    res += '8';
  }
  while (cs.find('H') != cs.end())
  {
    cs.erase(cs.find('T'));
    cs.erase(cs.find('H'));
    cs.erase(cs.find('R'));
    cs.erase(cs.find('E'));
    cs.erase(cs.find('E'));
    res += '3';
  }
  while (cs.find('R') != cs.end())
  {
    cs.erase(cs.find('F'));
    cs.erase(cs.find('O'));
    cs.erase(cs.find('U'));
    cs.erase(cs.find('R'));
    res += '4';
  }
  while (cs.find('F') != cs.end())
  {
    cs.erase(cs.find('F'));
    cs.erase(cs.find('I'));
    cs.erase(cs.find('V'));
    cs.erase(cs.find('E'));
    res += '5';
  }
  while (cs.find('V') != cs.end())
  {
    cs.erase(cs.find('S'));
    cs.erase(cs.find('E'));
    cs.erase(cs.find('V'));
    cs.erase(cs.find('E'));
    cs.erase(cs.find('N'));
    res += '7';
  }
  while (cs.find('I') != cs.end())
  {
    cs.erase(cs.find('N'));
    cs.erase(cs.find('I'));
    cs.erase(cs.find('N'));
    cs.erase(cs.find('E'));
    res += '9';
  }
  while (cs.find('O') != cs.end())
  {
    cs.erase(cs.find('O'));
    cs.erase(cs.find('N'));
    cs.erase(cs.find('E'));
    res += '1';
  }
  sort(res.begin(), res.end());
  return res;
}

void run(istream& in, ostream& out)
{
  int T; in >> T;
  for (int t = 1; t <= T; t++)
  {
    string S; in >> S;
    auto res = solve(S);
    out << "Case #" << t << ": " << res << endl;
  }
}

int main()
{
  ifstream fin("A-small.in");
  ofstream fout("A-small.out");
  run(fin, fout);
}

