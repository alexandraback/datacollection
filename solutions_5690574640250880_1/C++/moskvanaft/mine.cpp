#include <fstream>
#include <iostream>
#include <iomanip>
#include <vector>
#include <cassert>
#include <algorithm>

struct noncopyable {
  noncopyable(const noncopyable&) = delete;
  noncopyable& operator=(const noncopyable&) = delete;
  noncopyable() {}
};

struct Files : noncopyable {
  std::fstream in;
  std::fstream out;

  static std::string name_to_out(const std::string& s) {
    if (s.substr(s.size()-3) == ".in") {
      return s.substr(0, s.size()-3)+".out";
    } else {
      return s+".out";
    }
  }

  Files(const std::string& name) : in(name.c_str(), std::ios_base::in),
    out(name_to_out(name).c_str(), std::ios_base::out) {
  }

  size_t get_numline() {
    size_t N;
    in >> N;
    std::string es;
    std::getline(in, es);
    if (!es.empty()) {
      assert(false);
    }
    return N;
  }

  template<class T> std::vector<T> get_vec(size_t n) {
    std::vector<T> v;
    v.reserve(n);
    while (n-- > 0) {
      T tmp;
      in >> tmp;
      v.push_back(std::move(tmp));
    }
    return v;
  }

  template<class T> T get() {
    T tmp;
    in >> tmp;
    return tmp;
  }
};

template<class T> struct Matrix : noncopyable {
  size_t m_rows;
  size_t m_cols;
  std::vector<T> m_values;
  size_t rows() const {
    return m_rows;
  }
  size_t cols() const {
    return m_cols;
  }
  T& operator[](size_t n) {
    return m_values[n];
  }
  typename std::vector<T>::iterator get(size_t n) {
    //assert(1 <= n);
    assert(n <= m_values.size());
    return m_values.begin()+n;
  }
  T& operator()(size_t r, size_t c) {
    assert(1 <= r && r <= m_rows);
    assert(1 <= c && c <= m_cols);
    return m_values[(r-1)*m_cols+(c-1)];
  }
  const T& operator()(size_t r, size_t c) const {
    assert(1 <= r && r <= m_rows);
    assert(1 <= c && c <= m_cols);
    return m_values[(r-1)*m_cols+(c-1)];
  }
  Matrix() : m_rows(0), m_cols(0) {
  }
  Matrix(size_t r, size_t c, T v) : m_rows(r), m_cols(c), m_values(r*c, v) {
  }
  Matrix(Matrix&& m) noexcept : m_rows(std::move(m.m_rows)), m_cols(std::move(m.m_cols)), m_values(std::move(m.m_values)) {
  }
  operator bool() const {
    return m_rows != 0;
  }
};

inline std::ostream& operator<<(std::ostream& osm, const Matrix<char>& m) {
  for (size_t r = 0; r < m.rows(); ++r) {
    osm.write(&m.m_values[r*m.cols()], m.cols());
    osm << std::endl;
  }
  return osm;
}

const int MINE = -2;

template<class T> std::ostream& operator<<(std::ostream& osm, const Matrix<T>& m) {
  //auto oldw = osm.width(3);
  for (size_t r = 1; r <= m.rows(); ++r) {
    for (size_t c = 1; c <= m.cols(); ++c) {
      if (m(r, c) == MINE) {
	osm << std::setw(3) << "X";
      } else {
	osm << std::setw(3) << m(r,c);
      }
    }
    osm << std::endl;
  }
  //osm.width(oldw);
  return osm;
}

inline Matrix<char> solve(size_t R, size_t C, size_t M) {
  if (R*C <= M) {
    return Matrix<char>();
  }
  size_t N = R*C-M;
  if (1 == N) {
    Matrix<char> m(R, C, '*');
    m(1,1) = 'c';
    return m;
  }
  if (1 == R || 1 == C) {
    Matrix<char> m(R, C, '*');
    std::fill(m.get(0), m.get(N), '.');
    m(1,1) = 'c';
    return m;
  } else if (2 == R || 2 == C) {
    if (0 == N%2 && N >= 4) {
      Matrix<char> m(R, C, '*');
      if (2 == C) {
	std::fill(m.get(0), m.get(N), '.');
      } else {
	std::fill(m.get(0), m.get(N/2), '.');
	std::fill(m.get(C), m.get(C+N/2), '.');
      }
      m(1,1) = 'c';
      return m;
    } else {
      return Matrix<char>();
    }
  } else {
    assert(R >= 3 && C >= 3);
    if (N >=8 || 4 == N || 6 == N) {
      Matrix<char> m(R, C, '*');
      size_t K = (0 == N%2) ? N-2 : N-3;
      size_t left = N-K;
      assert(0 == K%2);

      size_t start = 0;
      //size_t R2 = 2*C/
      while (K >= 2*C) {
	std::fill(m.get(start), m.get(start+2*C), '.');
	K -= 2*C;
	start += 2*C;
      }
      //std::cout << m << std::endl; //XXX
      assert(K <= 2*C-2);
      size_t x = K/2;

      if (x > 0 && R*C-start >=2*C) {

	std::fill(m.get(start), m.get(start+x), '.');
	std::fill(m.get(start+C), m.get(start+C+x), '.');
	//std::cout << m << std::endl; //XXX
	//X left == 3
	if (2 == left) {
	  if (C == x) {
	    std::fill(m.get(start+2*C), m.get(start+2*C+left), '.');
	  } else {
	    *m.get(start+x) = '.';
	    *m.get(start+C+x) = '.';
	  }
	} else {
	  assert(3 == left);
	  if (C-x >= 2) {
	    if (start >= C) {
	      *m.get(start+x) = '.';
	      *m.get(start+x+1) = '.';
	      *m.get(start+C+x) = '.';
	    } else if (0 == start) {
	      assert(x >= 3);
	      std::fill(m.get(start+2*C), m.get(start+2*C+left), '.');
	    } else {
	      assert(false);
	    }
	  } else if (1 == C-x) {
	    if (start > C) {
	      *m.get(start+x) = '.';
	      std::fill(m.get(start+2*C), m.get(start+2*C+2), '.');
	    } else if (0 == start) {
	      assert(x >= 3);
	      std::fill(m.get(start+2*C), m.get(start+2*C+3), '.');
	    } else {
	      assert(false);
	    }
	  } else {
	    assert(false);
	  }
	}
      } else {
	//assert(C == x || 0 == x);
	std::fill(m.get(start), m.get(start+K+left), '.');
      }
      //std::cout << m << std::endl; //XXX
      m(1,1) = 'c';
      return m;
    } else {
      return Matrix<char>();
    }
  }
}

int neigh(const Matrix<char>& m, size_t r, size_t c) {
  size_t count = 0;
  for (size_t i = std::max(size_t(1), r-1); i <= std::min(m.rows(), r+1); ++i) {
    for (size_t j = std::max(size_t(1), c-1); j <= std::min(m.cols(), c+1); ++j) {
      if ((i != r || j != c) && '*' == m(i, j)) {
	++count;
      }
    }
  }
  return count;
}

bool near_zero(const Matrix<int>& m, size_t r, size_t c) {
  for (size_t i = std::max(size_t(1), r-1); i <= std::min(m.rows(), r+1); ++i) {
    for (size_t j = std::max(size_t(1), c-1); j <= std::min(m.cols(), c+1); ++j) {
      if ((i != r || j != c) && 0 == m(i, j)) {
	return true;
      }
    }
  }
  return false;
}

bool check(const Matrix<char>& m) {
  Matrix<int> res(m.rows(), m.cols(), -1);
  size_t mines = 0;
  for (size_t r = 1; r <= m.rows(); ++r) {
    for (size_t c = 1; c <= m.cols(); ++c) {
      if (m(r, c) == '*') {
	res(r, c) = MINE;
	++mines;
      } else {
	res(r, c) = neigh(m, r, c);
      }
    }
  }
  if (mines < m.cols()*m.rows()-1) {
    for (size_t r = 1; r <= m.rows(); ++r) {
      for (size_t c = 1; c <= m.cols(); ++c) {
	if (res(r,c) != MINE) {
	  assert(-1 != res(r, c));
	  if (res(r,c) != 0 && !near_zero(res, r, c)) {
	    std::cout << m << std::endl;
	    std::cout << res << std::endl;
	    assert(false);
	  }
	}
      }
    }
  }
  return true;
}

bool solve_test(size_t R, size_t C, size_t M) {
  auto m = solve(R, C, M);
  std::cout << "M = " << M << " (" << R << 'x' << C << ')' << std::endl;
  if (m) {
    std::cout << m << std::endl;
    assert((size_t)std::count(m.get(0), m.get(R*C), '*') == M);
    check(m);
  } else {
    std::cout << "Impossible" << std::endl;
  }
  return bool(m);
}

void test() {
  assert(solve_test(1, 1, 0));
  assert(!solve_test(1, 1, 1));

  assert(solve_test(1, 2, 0));
  assert(solve_test(1, 2, 1));

  assert(solve_test(2, 1, 0));
  assert(solve_test(2, 1, 1));

  assert(solve_test(1, 3, 0));
  assert(solve_test(1, 3, 1));

  assert(solve_test(3, 1, 1));
  assert(solve_test(3, 1, 2));

  assert(solve_test(4, 1, 0));
  assert(solve_test(4, 1, 2));
  assert(solve_test(4, 1, 3));

  assert(solve_test(1, 4, 0));
  assert(solve_test(1, 4, 2));
  assert(solve_test(1, 4, 3));

  assert(solve_test(2, 2, 0));
  assert(!solve_test(2, 2, 1));
  assert(!solve_test(2, 2, 2));
  assert(solve_test(2, 2, 3));

  assert(solve_test(2, 3, 0));
  assert(!solve_test(2, 3, 1));
  assert(solve_test(2, 3, 2));
  assert(!solve_test(2, 3, 3));
  assert(!solve_test(2, 3, 4));
  assert(solve_test(2, 3, 5));

  assert(solve_test(3, 2, 0));
  assert(!solve_test(3, 2, 1));
  assert(solve_test(3, 2, 2));
  assert(!solve_test(3, 2, 3));
  assert(!solve_test(3, 2, 4));
  assert(solve_test(3, 2, 5));

  assert(solve_test(4, 2, 0));
  assert(!solve_test(4, 2, 1));
  assert(solve_test(4, 2, 4));
  assert(!solve_test(4, 2, 6));

  assert(solve_test(2, 4, 0));
  assert(!solve_test(2, 4, 1));
  assert(solve_test(2, 4, 4));
  assert(!solve_test(2, 4, 6));

  assert(solve_test(3, 3, 0));
  assert(solve_test(3, 3, 1));
  assert(!solve_test(3, 3, 2));
  assert(solve_test(3, 3, 3));
  assert(!solve_test(3, 3, 4));
  assert(solve_test(3, 3, 5));
  assert(!solve_test(3, 3, 6));
  assert(!solve_test(3, 3, 7));
  assert(solve_test(3, 3, 8));

  
  assert(solve_test(3, 4, 4));
  assert(solve_test(3, 4, 6));
  assert(solve_test(3, 4, 8));
  assert(solve_test(3, 4, 11));
  assert(!solve_test(3, 4, 10));
  assert(!solve_test(3, 4, 9));

  assert(solve_test(4, 3, 4));
  assert(solve_test(4, 3, 6));
  assert(solve_test(4, 3, 8));
  assert(solve_test(4, 3, 11));
  assert(!solve_test(4, 3, 10));
  assert(!solve_test(4, 3, 9));
 
  assert(solve_test(4, 4, 0));
  assert(solve_test(4, 4, 1));
  assert(solve_test(4, 4, 2));
  assert(solve_test(4, 4, 3));
  assert(solve_test(4, 4, 4));
  assert(solve_test(4, 4, 5));
  assert(solve_test(4, 4, 6));
  assert(solve_test(4, 4, 7));
  assert(solve_test(4, 4, 8));
  assert(!solve_test(4, 4, 9));
  assert(solve_test(4, 4, 10));
  assert(!solve_test(4, 4, 11));
  assert(solve_test(4, 4, 12));
  assert(!solve_test(4, 4, 13));
  assert(!solve_test(4, 4, 14));
  assert(solve_test(4, 4, 15));
  assert(!solve_test(4, 4, 16));
  assert(!solve_test(4, 4, 17));

  assert(solve_test(5, 4, 0));
  assert(solve_test(5, 4, 1));
  assert(solve_test(5, 4, 2));
  assert(solve_test(5, 4, 3));
  assert(solve_test(5, 4, 7));
  assert(solve_test(5, 4, 8));
  assert(solve_test(5, 4, 9));
  assert(solve_test(5, 4, 10));
  assert(solve_test(5, 4, 11));
  assert(solve_test(5, 4, 12));
  assert(!solve_test(5, 4, 13));
  assert(solve_test(5, 4, 14));
  assert(!solve_test(5, 4, 15));
  assert(solve_test(5, 4, 16));

  assert(solve_test(4, 5, 0));
  assert(solve_test(4, 5, 1));
  assert(solve_test(4, 5, 2));
  assert(solve_test(4, 5, 3));
  assert(solve_test(4, 5, 7));
  assert(solve_test(4, 5, 8));
  assert(solve_test(4, 5, 9));
  assert(solve_test(4, 5, 10));
  assert(solve_test(4, 5, 11));
  assert(solve_test(4, 5, 12));
  assert(!solve_test(4, 5, 13));
  assert(solve_test(4, 5, 14));
  assert(!solve_test(4, 5, 15));
  assert(solve_test(4, 5, 16));

  assert(solve_test(5, 5, 0));
  assert(solve_test(5, 5, 2));
  assert(solve_test(5, 5, 5));
  assert(solve_test(5, 5, 6));
  assert(solve_test(5, 5, 7));
  assert(solve_test(5, 5, 8));
  assert(solve_test(5, 5, 9));
  assert(solve_test(5, 5, 10));
  assert(solve_test(5, 5, 19));
  assert(solve_test(5, 5, 17));
  assert(solve_test(5, 5, 24));

  
  assert(solve_test(4, 4, 4));
  assert(solve_test(4, 4, 4));
  assert(solve_test(3, 3, 5));
  assert(solve_test(1, 2, 1));
  assert(solve_test(2, 1, 1));
  assert(solve_test(5, 1, 4));
  assert(solve_test(1, 5, 4));
  assert(solve_test(5, 1, 1));
  assert(solve_test(1, 5, 1));
  assert(solve_test(1, 5, 0));
  assert(solve_test(5, 5, 0));
  assert(solve_test(4, 4, 8));
  assert(solve_test(2, 2, 0));
  assert(!solve_test(2, 3, 1));
  assert(!solve_test(2, 8, 3));
  assert(!solve_test(2, 8, 9));
  assert(solve_test(2, 8, 4));
  assert(solve_test(2, 8, 12));

  assert(solve_test(5, 3, 2));
  assert(solve_test(3, 5, 6));
  assert(solve_test(5, 3, 7));
}

int main(int argc, char** argv) {
  if (argc < 2) {
    //std::cerr << "Use ./a.out <file>" << std::endl;
    test();
    return 1;
  }
  Files f(argv[1]);
  size_t N;
  f.in >> N;
  for (size_t n = 1; n <= N; ++n) {
    size_t R, C, M;
    f.in >> R >> C >> M;
    auto m = solve(R, C, M);
    if (bool(m)) {
      //check(m);
      //auto m = solve_test(R, C, M); //XXX
      f.out << "Case #" << n << ":" << std::endl << m;
    } else {
      f.out << "Case #" << n << ":"  << std::endl << "Impossible" << std::endl;
    }
  }
  return 0;
}
