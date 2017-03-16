#define MAX_N 16
#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <vector>

int gr[MAX_N][MAX_N];

void solve_case(int case_num)
{
  int n;
  std::vector<std::string> v, u;
  std::string s, t;

  std::cin >> n;
  for (int i = 0; i < n; i++) {
    std::cin >> s >> t;
    v.push_back(s);
    u.push_back(t);
  }
  std::cout << "CASE #" << case_num << ": ";

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      gr[i][j] = 0;
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      if (v[i] == v[j]) {
	gr[i][j] |= 1;
	gr[j][i] |= 1;
      }
      if (u[i] == u[j]) {
	gr[i][j] |= 2;
	gr[j][i] |= 2;
      }
    }
  }

  int mask = 1 << n;
  int res = 0;
  for (int i = 0; i < mask; i++) {
    int v[MAX_N];
    int sz = 0;
    for (int j = 0, x = i; j < n; j++, x >>= 1) {
      v[j] = x & 1;
      sz += v[j];
    }
    bool found = true;
    for (int j = 0; j < n; j++) {
      if (v[j]) {
	bool fa = false;
	bool fb = false;
	for (int k = 0; k < n; k++) {
	  if (!v[k]) {
	    if (gr[j][k] & 1) {
	      fa = true;
	    }
	    if (gr[j][k] & 2) {
	      fb = true;
	    }
	  }
	}
	if (!fa || !fb) {
	  found = false;
	  break;
	}
      }
    }
    if (found) {
      res = std::max(res, sz);
    }
  }

  for (int i = 0; i < n; i ++) {
    //std::cout << u[i] << std::endl;
  }

  std::cout << res << std::endl;
}

int main()
{
  int num_cases;

  std::cin >> num_cases;
  for (int i = 1; i <= num_cases; i++) {
    solve_case(i);
  }
  
  return 0;
}
