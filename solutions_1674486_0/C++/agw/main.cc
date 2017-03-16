#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <deque>

#include <cstring>


#define EACH(i, x) for (typeof((x).begin()) i = (x).begin(); i != (x).end(); ++ i)


int N;

std::map<int, std::vector<int> > dep;


bool bfs(int i)
{
  std::deque<int> queue;

  std::set<int> visited;

  queue.push_back(i);

  while (queue.size()) {
    int i = queue.front();

    queue.pop_front();

    if (visited.count(i))
      return true;

    visited.insert(i);

    EACH(it, dep[i])
      queue.push_back(*it - 1);
  }
  return false;
}

std::string main2()
{
  std::cin >> N;
  
  for (int i = 0; i < N; i ++) {
    int M;

    std::cin >> M;

    dep[i].resize(M);

    for (int j = 0; j < M; j ++)
      std::cin >> dep[i][j];
  }

  for (int i = 0; i < N; i ++)
    if (bfs(i))
      return "Yes";

  return "No";
}

int main(int argc, char** argv)
{
  int T;

  std::cin >> T;

  for (int t = 1; t <= T; t ++)
    std::cout << "Case #" << t << ": " << main2() << std::endl;
}
