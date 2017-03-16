#include <iostream>
#include <set>


int rev(int x)
{
  int r = 0;
  while ( x > 0 )
  {
    r = r*10 + (x%10);
    x /= 10;
  }
  return r;
}


int count(int N)
{
  std::set<int> state, state1, used;
  int cnt = 1;
  state.insert(1);
  while ( true )
  {
    if ( state.find(N) != state.end() )
      return cnt;
    ++cnt;
    state1.clear();
    for ( auto x: state )
    {
      int nx = x + 1;
      if ( used.find(nx) == used.end() )
      {
        state1.insert(nx);
        used.insert(nx);
      }
      nx = rev(x);
      if ( used.find(nx) == used.end() )
      {
        state1.insert(nx);
        used.insert(nx);
      }
    }
    state1.swap(state);
  }
  return cnt;
}


int main()
{
  int T;
  std::cin >> T;
  for ( int t = 1; t <= T; ++t )
  {
    int N;
    std::cin >> N;
    std::cout << "Case #" << t << ": " << count(N) << '\n';
  }
  return 0;
}
