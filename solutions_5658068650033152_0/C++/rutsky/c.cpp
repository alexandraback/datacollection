/*
 * Google Code Jam 2014. Round 1C. Problem C
 * Vladimir Rutsky
 * 11.05.2014
 */

#undef NDEBUG

#include <iostream>
#include <algorithm>
#include <array>
#include <iterator>
#include <set>
#include <cassert>
#include <vector>
#include <cstdio>
#include <map>

using namespace std;

string solve(size_t N, size_t M, size_t K)
{
  assert(N >= 1 && M >= 1);
  assert(K <= N * M);

  if (N > M)
    return solve(M, N, K);

  if (N == 1 || N == 2)
  {
    return to_string(K);
  }

  map<size_t, size_t> req_to_cov;

  for (size_t a = 1; a <= N - 2; ++a)
  {
    for (size_t b = 1; b <= M - 2; ++b)
    {
      size_t req = 2 * a + 2 * b;
      size_t covers = a * b + req;

      auto r2c_it = req_to_cov.find(req);

      if (r2c_it != req_to_cov.end() && r2c_it->second >= covers)
      {
        continue;
      }
      else
      {
        req_to_cov[req] = covers;
      }
    }
  }

  size_t res = K;

  for (pair<size_t, size_t> const & r2c: req_to_cov)
  {
    res = min(res, r2c.first + max((int)K - (int)r2c.second, 0));
  }

  return to_string(res);


  /*
  map<size_t, size_t> cov_to_req, req_to_cov;

  for (size_t a = 1; a <= N - 2; ++a)
  {
    for (size_t b = 1; b <= M - 2; ++b)
    {
      size_t req = 2 * a + 2 * b;
      size_t covers = a * b + req;

      auto r2c_it = req_to_cov.find(req);
      auto c2v_it = cov_to_req.find(covers);

      if (r2c_it != req_to_cov.end() && c2v_it != cov_to_req.end())
      {
        continue;
      }
      else if (r2c_it != req_to_cov.end())
      {
        size_t other_covers = r2c_it->second;
        if (other_covers < covers)
        {
          req_to_cov.erase(r2c_it);
          auto it = cov_to_req.find(other_covers);
          assert(it != other_covers.end());
          cov_to_req.erase(it);
        }
        else
        {
          continue;
        }
      }
      else if (c2v_it != cov_to_req.end())
      {
        size_t other_req = c2v_it->second;
        if (other_req > req)
        {
          cov_to_req.erase(c2v_it);

          auto it = req_to_cov.find(other_req);
          assert(it != req_to_cov.end());
          req_to_cov.erase(r2c_it);
        }
        else
        {
          continue;
        }
      }


      assert(req_to_cov.find(req) == req_to_cov.end());
      assert(cov_to_req.find(covers) == cov_to_req.end());

      req_to_cov[req] = covers;
      cov_to_req[covers] = req;
    }
  }

  auto it = cov_to_req.lower_bound(K);
  if (it == cov_to_req.end())
  {
    size_t last_req = prev(cov_to_req.end())->second;

    auto last_it = req_to_cov.find(last_req);
    size_t res = last_it->first + (K - last_it->second);
    return to_string(res);
  }

  auto prev_it = prev(it);
  assert(prev_it != cov_to_req.end());
  assert(next_it->first > K);

  size_t req1 = it->second + (K - it->first);
  size_t req1 = it->second + (K - it->first);
  */

  //return to_string(0);
}

int main()
{
  FILE * res = stdin;
  //res = std::freopen("small.in", "rt", stdin);
  //res = std::freopen("A-small-attempt0.in", "rt", stdin);
  //res = std::freopen("A-large.in", "rt", stdin);
  assert(res);

  size_t T;
  cin >> T;

  for (size_t ci = 1; ci <= T; ++ci)
  {
    size_t N, M, K;
    cin >> N >> M >> K;

    cout << "Case #" << ci << ": " << solve(N, M, K) << "\n";
  }
}
