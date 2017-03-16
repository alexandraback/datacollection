#include <iostream>
#include <algorithm>
#include <vector>
#include <string>


std::string j(std::vector<std::string> const &v, std::vector<int> const &k)
{
  std::string r;
  for ( auto &s: k )
    r += v[s];
  return r;
}


bool good(std::string const &s)
{
  std::vector<char> sn('z' - 'a' + 1);
  char pc = 0;
  int rn = 0;
  for ( char c: s)
  {
    if ( pc )
    {
      if ( pc != c )
      {
        if ( sn[c - 'a'] )
          return false;
      }
      else
        rn += 1;
    }
    pc = c;
    sn[c - 'a'] = true;
  }
  return true;
}


long count(std::vector<std::string> const &tr)
{
  std::vector<int> k(tr.size());
  for ( int i = 0; i < int(k.size()); ++ i )
    k[i] = i;
  long p = 0;
  do
  {
    if ( good(j(tr, k)) )
      p += 1;
  }
  while ( std::next_permutation(k.begin(), k.end()) );
  return p;
}



int main()
{
  int T;
  std::cin >> T;
  for ( int t = 1; t <= T; ++t )
  {
    int N;
    std::cin >> N;
    std::vector<std::string> v;
    for ( int i=0; i < N; ++i )
    {
      std::string w;
      std::cin >> w;
      v.push_back(w);
    }
    std::cout << "Case #" << t << ": " << count(v) << '\n';
  }
  return 0;
}
