#include <map>
#include <vector>
#include <iostream>

typedef std::map<long, std::vector<int> > SMap;

SMap create_smap(std::vector<int> const &v)
{
  SMap sm;
  int N = v.size();
  for ( int i = 1; i < (1<<N); ++i )
  {
    long s = 0;
    for ( int r = 0; r < N; ++r )
      if ( i&(1<<r) )
        s += v[r];
    sm[s].push_back(i);
  }
  return sm;
}

void outp(std::vector<int> const &v, int m)
{
  int N = v.size();
  for ( int r = 0; r < N; ++r )
    if ( m&(1<<r) )
      std::cout << v[r] << ' ';
}

void output(std::vector<int> const &v)
{
  SMap sm = create_smap(v);
  for ( SMap::const_iterator p = sm.begin(); p != sm.end(); ++p )
  {
    if ( p->second.size() >= 2 )
    {
      std::cout << '\n';
      outp(v, p->second[0]);
      std::cout << '\n';
      outp(v, p->second[1]);
      std::cout << std::endl;
      return;
    }
  }
  std::cout << "Impossible" << std::endl;
}


int main()
{
  int T;
  std::cin >> T;
  for ( int t = 1; t <= T; ++t )
  {
    int N;
    std::cin >> N;
    std::vector<int> v(N);
    for ( int r = 0; r < N; ++r )
      std::cin >> v[r];
    std::cout << "Case #" << t << ": ";
    output(v);
  }
  return 0;
}
