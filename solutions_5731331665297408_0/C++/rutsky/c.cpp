/*
 * CodeJam 2014. Round 1B. Problem C
 * Vladimir Rutsky
 * 03.05.2014
 */

#include <iostream>
#include <algorithm>
#include <array>
#include <iterator>
#include <set>
#include <cassert>
#include <vector>
#include <cstdio>

using namespace std;

typedef std::vector<std::vector<size_t>> adj_list_t;

void iterate(std::vector<size_t> const & zips, adj_list_t const & g, std::vector<bool> & visited,
             std::vector<size_t> & cur_zip, size_t v, std::vector<size_t> & min_zip)
{
  if (visited[v])
    return;

  cur_zip.push_back(zips[v]);

  if (cur_zip.size() == zips.size())
  {
    if (min_zip.empty() || cur_zip < min_zip)
    {
      min_zip = cur_zip;
    }

    cur_zip.pop_back();
    return;
  }

  visited[v] = true;
  for (size_t adj_v: g[v])
  {
    iterate(zips, g, visited, cur_zip, adj_v, min_zip);
  }
  visited[v] = false;

  cur_zip.pop_back();
}

std::string solve(std::vector<size_t> const & zips, adj_list_t const & g)
{
  std::vector<bool> visited(g.size(), false);
  std::vector<size_t> cur_zip;

  std::vector<size_t> min_zip;

  for (size_t start_v = 0; start_v != g.size(); ++start_v)
  {
    iterate(zips, g, visited, cur_zip, start_v, min_zip);
  }

  std::string res;
  for (size_t zip: min_zip)
    res += std::to_string(zip);

  return res;
}

int main()
{
  size_t T;

  //FILE * res = std::freopen("small.in", "rt", stdin);
  //FILE * res = std::freopen("A-small-attempt0.in", "rt", stdin);
  //FILE * res = std::freopen("A-large.in", "rt", stdin);
  //assert(res);

  std::cin >> T;

  for (size_t idx = 0; idx != T; ++idx)
  {
    size_t N, M;
    std::cin >> N >> M;

    std::vector<size_t> zips;
    std::copy_n(std::istream_iterator<size_t>(std::cin), N, std::back_inserter(zips));

    adj_list_t g(N);
    for (size_t i = 0; i != M; ++i)
    {
      size_t v0, v1;
      std::cin >> v0 >> v1;
      g[v0 - 1].push_back(v1 - 1);
      g[v1 - 1].push_back(v0 - 1);
    }

    std::cout << "Case #" << (idx + 1) << ": " << solve(zips, g) << "\n";
  }
}
