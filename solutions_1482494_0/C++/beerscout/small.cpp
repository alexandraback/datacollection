#include <iostream>
#include <vector>
#include <deque>


struct state
{
  int completed;
  int stars;
  int time;
};


struct level
{
  int a, b;
};


int p[] = {1, 3, 9, 27, 81, 243, 729, 2187, 6561, 19683, 59049, 531441};


int simu(std::vector<level> const &v)
{
  int N = v.size();
  int target = p[N] - 1;
  std::deque<state> q;
  {
    state s;
    s.completed = s.stars = s.time = 0;
    q.push_back(s);
  }
  std::vector<int> vis(target + 1, -1);
  while ( not q.empty() )
  {
    state x = q[0];
    q.pop_front();
    if ( vis[x.completed] >= x.stars ) 
      continue;
    vis[x.completed] = x.stars;
    if ( x.completed == target )
      return x.time;
    for ( size_t i = 0; i < v.size(); ++i )
    {
      state s = x;
      int d = (s.completed/p[i])%3;
      if ( d == 2 )
        continue;
      if ( d == 1 )
      {
        if ( s.stars >= v[i].b )
        {
          ++s.time; ++s.stars;
          s.completed += p[i];
          q.push_back(s);
        }
        continue;
      }
      ++s.time;
      int stars = s.stars;
      int completed = s.completed;
      if ( stars >= v[i].a )
      {
        s.stars = stars + 1; s.completed = completed + p[i];
        q.push_back(s);
      }
      if ( stars >= v[i].b )
      {
        s.stars = stars + 2; s.completed = completed + 2*p[i];
        q.push_back(s);
      }
    }
  }
  return -1;
}


int main()
{
  int T;
  std::cin >> T;
  for ( int t = 1; t <= T; ++t )
  {
    int N;
    std::cin >> N;
    std::vector<level> v(N);
    for ( int i = 0; i < N; ++i )
      std::cin >> v[i].a >> v[i].b;
    int r = simu(v);
    std::cout << "Case #" << t << ": ";
    if ( r < 0 )
      std::cout << "Too Bad\n";
    else
      std::cout << r << '\n';
  }
  return 0;
}
