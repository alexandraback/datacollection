#define MAX_LENGTH 18
#include <iostream>
#include <algorithm>
#include <string>
#include <utility>
#include <vector>

long long build_number(int *v, size_t m) {
  long long n = 0;
  for (size_t i = 0; i < m; i++) {
    n = n * 10 + v[i];
  }
  return n;
}

std::string revert(long long x, size_t m) {
  std::string s(m, '0');
  while (x > 0) {
    --m;
    s[m] = '0' + (x % 10);
    x /= 10;
  }
  return s;
}

void solve_case(int case_num)
{
  std::vector<std::pair<long long, std::pair<long long, long long>>> v;
  std::string s, t;
  int a[MAX_LENGTH], b[MAX_LENGTH];

  std::cin >> s >> t;
  std::cout << "CASE #" << case_num << ": ";

  size_t m = s.size();

  for (size_t i = 0; i < m; i++) {
    if (s[i] != '?') {
      a[i] = s[i] - '0';
    }
    if (t[i] != '?') {
      b[i] = t[i] - '0';
    }
  }

  size_t max_idx = 0;
  for (; max_idx < m; ++max_idx) {
    char cs = s[max_idx];
    char ct = t[max_idx];
    if (cs != '?' && ct != '?' && cs != ct) {
      break;
    }
  }

  //std::cout << "xoxo: " << max_idx << std::endl;

  for (size_t i = 0; i <= max_idx; i++) {
    for (size_t j = 0; j < i; j++) {
      if (s[j] == '?') {
	if (t[j] == '?') {
	  a[j] = b[j] = 0;
	} else {
	  a[j] = b[j] = t[j] - '0';
	}
      } else if (t[j] == '?') {
	a[j] = b[j] = s[j] - '0';
      }
    }
    /*
    std::cout << "i=" << i << std::endl;
    for (size_t j = 0; j < i; j++) {
      std::cout << a[j];
    }
    std::cout << std::endl;
    for (size_t j = 0; j < i; j++) {
      std::cout << b[j];
    }
    std::cout << std::endl;
    */
    long long sa, sb;
    if (s[i] == '?') {
      if (t[i] == '?') {
        a[i] = 0;
        b[i] = 1;
        for (size_t j = i + 1; j < m; j++) {
          if (s[j] == '?') {
            a[j] = 9;
          }
          if (t[j] == '?') {
            b[j] = 0;
          }
        }
        sa = build_number(a, m);
        sb = build_number(b, m);
        v.push_back(std::make_pair(abs(sa - sb), std::make_pair(sa, sb)));

        a[i] = 1;
        b[i] = 0;
        for (size_t j = i + 1; j < m; j++) {
          if (s[j] == '?') {
            a[j] = 0;
          }
          if (t[j] == '?') {
            b[j] = 9;
          }
        }
        sa = build_number(a, m);
        sb = build_number(b, m);
        v.push_back(std::make_pair(abs(sa - sb), std::make_pair(sa, sb)));
      } else {
        b[i] = t[i] - '0';
        a[i] = b[i] - 1;
        for (size_t j = i + 1; j < m; j++) {
          if (s[j] == '?') {
            a[j] = 9;
          }
          if (t[j] == '?') {
            b[j] = 0;
          }
        }
	if (a[i] >= 0) {
	  sa = build_number(a, m);
	  sb = build_number(b, m);
	  v.push_back(std::make_pair(abs(sa - sb), std::make_pair(sa, sb)));
	}

        b[i] = t[i] - '0';
        a[i] = b[i] + 1;
        for (size_t j = i + 1; j < m; j++) {
          if (s[j] == '?') {
            a[j] = 0;
          }
          if (t[j] == '?') {
            b[j] = 9;
          }
        }
	if (a[i] < 10) {
	  sa = build_number(a, m);
	  sb = build_number(b, m);
	  v.push_back(std::make_pair(abs(sa - sb), std::make_pair(sa, sb)));
	}
      }
    } else if (t[i] == '?') {
      a[i] = s[i] - '0';
      b[i] = a[i] + 1;
      for (size_t j = i + 1; j < m; j++) {
        if (s[j] == '?') {
          a[j] = 9;
	}
        if (t[j] == '?') {
          b[j] = 0;
	}
      }
      if (b[i] < 10) {
        sa = build_number(a, m);
        sb = build_number(b, m);
        v.push_back(std::make_pair(abs(sa - sb), std::make_pair(sa, sb)));
      }

      a[i] = s[i] - '0';
      b[i] = a[i] - 1;
      for (size_t j = i + 1; j < m; j++) {
        if (s[j] == '?') {
          a[j] = 0;
	}
        if (t[j] == '?') {
          b[j] = 9;
	}
      }
      if (b[i] >= 0) {
        sa = build_number(a, m);
        sb = build_number(b, m);
        v.push_back(std::make_pair(abs(sa - sb), std::make_pair(sa, sb)));
      }
    } else if (s[i] != t[i] || s[i] == '\0') {
      if (s[i] < t[i]) {
        for (size_t j = i + 1; j < m; j++) {
          if (s[j] == '?') {
            a[j] = 9;
          }
          if (t[j] == '?') {
            b[j] = 0;
          }
        }
        sa = build_number(a, m);
        sb = build_number(b, m);
        v.push_back(std::make_pair(abs(sa - sb), std::make_pair(sa, sb)));
      } else if (s[i] > t[i]) {
        for (size_t j = i + 1; j < m; j++) {
          if (s[j] == '?') {
            a[j] = 0;
          }
          if (t[j] == '?') {
            b[j] = 9;
          }
        }
        sa = build_number(a, m);
        sb = build_number(b, m);
        v.push_back(std::make_pair(abs(sa - sb), std::make_pair(sa, sb)));
      } else {
        sa = build_number(a, m);
        sb = build_number(b, m);
        v.push_back(std::make_pair(abs(sa - sb), std::make_pair(sa, sb)));
      }
    }
  }
  /*
  if (m == 3) {
    v.clear();
    for (int i = 0; i <= 9; i++) {
      for (int j = 0; j <= 9; j++) {
	for (int k = 0; k <= 9; k++) {
          for (int l = 0; l <= 9; l++) {
	    for (int g = 0; g <= 9; g++) {
	      for (int h = 0; h <= 9; h++) {
                if (s[0] == '?') {
		  a[0] = i;
		} else {
		  a[0] = s[0] - '0';
		}
                if (s[1] == '?') {
		  a[1] = j;
		} else {
		  a[1] = s[1] - '0';
		}
                if (s[2] == '?') {
		  a[2] = k;
		} else {
		  a[2] = s[2] - '0';
		}
                if (t[0] == '?') {
		  b[0] = l;
		} else {
		  b[0] = t[0] - '0';
		}
                if (t[1] == '?') {
		  b[1] = g;
		} else {
		  b[1] = t[1] - '0';
		}
                if (t[2] == '?') {
		  b[2] = h;
		} else {
		  b[2] = t[2] - '0';
		}
		long long sa, sb;
		sa = build_number(a, m);
		sb = build_number(b, m);
		v.push_back(std::make_pair(abs(sa - sb), std::make_pair(sa, sb)));
	      }
	    }
	  }
	}
      }
    }
  }
  */
  auto res = std::min_element(v.begin(), v.end());

  for (auto it : v) {
    //std::cout << it.first << ' ' << it.second.first << ' ' << it.second.second << std::endl;
  }

  std::cout << revert(res->second.first, m) << ' '
	    << revert(res->second.second, m) << std::endl;
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
