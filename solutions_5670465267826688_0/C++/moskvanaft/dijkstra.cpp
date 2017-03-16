#include <fstream>
#include <iomanip>
#include <string>
#include <vector>
#include <array>
#include <cassert>
#include <map>
#include <iostream>

#include <thread>
#include <mutex>
#include <condition_variable>
#include <queue>
#include <functional>
#include <limits>

typedef std::lock_guard<std::mutex> lguard;
typedef std::unique_lock<std::mutex> ulock;

constexpr size_t def_locked_queue_max_size = 20;
constexpr size_t def_num_threads = 2;

using namespace std;

struct noncopyable {
  noncopyable(const noncopyable&) = delete;
  noncopyable& operator=(const noncopyable&) = delete;
  noncopyable() {}
};

template<class T> class LockedQueue : noncopyable {
  mutable std::mutex m_mutex;
  std::condition_variable m_cond;
  std::queue<T> m_queue;
  const size_t m_max_size;
  size_t m_returned;
  bool m_stop;
  size_t m_waiting;
 public:

  enum { C_STOP = std::numeric_limits<size_t>::max() };

  typedef T value_type;

   LockedQueue(size_t max_size = def_locked_queue_max_size) : m_max_size(max_size), 
    m_returned(0), m_stop(false), m_waiting(0) {}

  ~LockedQueue() {
    assert(0 == m_waiting);
  }
  void push(const T& v) {
    lguard l(m_mutex);
    m_queue.push(v);
    m_cond.notify_one();
  }
  void push(T&& v) {
    lguard l(m_mutex);
    m_queue.push(std::move(v));
    m_cond.notify_one();
  }
  size_t pop(T& v) {
    ulock lock(m_mutex);
    while (m_queue.empty()) {
      if (m_stop) {
	return C_STOP;
      }
      ++m_waiting;
      m_cond.wait(lock);
      --m_waiting;
    }
    v = std::move(m_queue.front());
    m_queue.pop();
    return m_returned++;
  }
  size_t size() const {
    lguard(m_mutex);
    return m_queue.size();
  }
  size_t empty() const {
    lguard l(m_mutex);
    return m_queue.empty();
  }
  void stop() {
    {
      lguard l(m_mutex);
      m_stop = true;
    }
    m_cond.notify_all();
  }
};

class ThreadPool : noncopyable {
  std::vector<std::thread> m_threads;
  bool m_stoped;
public:
  template<class F> ThreadPool(size_t n, const F& f = F()) : m_stoped(false) {
    while (n-- > 0) {
      m_threads.push_back(std::thread(f));
    }
  }
  ~ThreadPool() {
    wait();
  }
  void wait() {
    if (!m_stoped) {
      for (auto& t : m_threads) {
	t.join();
      }
      m_stoped = true;
    }
  }
};

template<class T, class R> class Runner2 {
  LockedQueue<T> m_queue;
  std::vector<R> m_out;
  ThreadPool m_pool;
  template<class F> void processq(F func) {
    while (1) {
      T value;
      auto i = m_queue.pop(value);
      if (i == LockedQueue<T>::C_STOP) {
	return;
      }
      m_out[i] = func(std::move(value));
      cout << i << ' ';
      cout.flush();
    }
  }
 public:
  template<class F> Runner2(size_t n, const F& func) : m_pool(def_num_threads, std::bind(&Runner2::processq<F>, this, func)) {
    m_out.resize(n);
  }
  ~Runner2() {
    wait();
  }
  
  void push(T&& t) {
    m_queue.push(std::move(t));
  }
  void push(const T& t) {
    m_queue.push(t);
  }
  void wait() {
    m_queue.stop();
    m_pool.wait();
  }
  const std::vector<R>& result() {
    wait();
    return m_out;
  }
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

typedef unsigned int uint;
/*
static map<pair<char, char>, pair<bool, char> > table = {
  { { '1', '1'}, { false, '1' } },
  { { '1', 'i'}, { false, 'i' } },
  { { '1', 'j'}, { false, 'j' } },
  { { '1', 'k'}, { false, 'k' } },

  { { 'i', '1'}, { false, 'i' } },
  { { 'i', 'i'}, { true, '1' } },
  { { 'i', 'j'}, { false, 'k' } },
  { { 'i', 'k'}, { true, 'j' } },

  { { 'j', '1'}, { false, 'j' } },
  { { 'j', 'i'}, { true, 'k' } },
  { { 'j', 'j'}, { true, '1' } },
  { { 'j', 'k'}, { false, 'i' } },

  { { 'k', '1'}, { false, 'k' } },
  { { 'k', 'i'}, { false, 'j' } },
  { { 'k', 'j'}, { true, 'i' } },
  { { 'k', 'k'}, { true, '1' } },
};
*/

inline pair<bool, char> table(char a, char b) {
  if ('1' == a) {
    switch(b) {
    case '1': return { false, '1' };
    case 'i': return { false, 'i' };
    case 'j': return { false, 'j' };
    case 'k': return { false, 'k' };
    default:
      assert(false);
    }
  } else if('i' == a) {
    switch(b) {
    case '1': return { false, 'i' };
    case 'i': return { true, '1' };
    case 'j': return { false, 'k' };
    case 'k': return { true, 'j' };
    default:
      assert(false);
    }
  } else if ('j' == a) {
    switch(b) {
    case '1': return { false, 'j' };
    case 'i': return { true, 'k' };
    case 'j': return { true, '1' };
    case 'k': return { false, 'i' };
    default:
      assert(false);
    }
  } else if ('k' == a) {
    switch(b) {
    case '1': return { false, 'k' };
    case 'i':return { false, 'j' };
    case 'j': return { true, 'i' };
    case 'k': return { true, '1' };
    default:
      assert(false);
    }
  } else {
      assert(false);
  }
  return {true, 0};
};

array<char, 3> exp = { 'i', 'j', 'k' };

bool solve(const string& s, size_t start, size_t pos) {
  if (start < s.size()) {
    char c = s[start];
    bool minus = false;
    if (pos != 2 && c == exp[pos] && minus == false) {
      if (solve(s, start+1, pos+1)) {
	return true;
      }
    }
    for (size_t i = start+1; i < s.size(); ++i) {
      auto res = table(c, s[i]);
      c = res.second;
      minus = (minus != res.first);
      if (pos != 2 && c == exp[pos] && minus == false) {
	if (solve(s, i+1, pos+1)) {
	  return true;
	}
      }
    }
    if (pos == 2) {
      return c == exp[2] && minus == false;
    } else {
      return false;
    }
  } else {
    assert(s.size() == start);
    return false;
  }
}

void test() {
  cout << "Test OK" << endl;
}

bool solve1(const string& s) {
  return solve(s, 0, 0);
}

int main(int argc, char** argv) {
  if (argc < 2) {
    std::cerr << "Use ./a.out <file>" << std::endl;
    test();
    return 1;
  }

  Files f(argv[1]);
  size_t T;
  f.in >> T;
  Runner2<string, bool> r(T, solve1);
  for (size_t t = 1; t <= T; ++t) {
    //cout << t << ' ';
    //cout.flush();
    size_t x, length;
    string s;
    f.in >> length >> x >> s;
    string str;
    str.reserve(x*s.size());
    while (x-- > 0) {
      str.append(s);
    }
    r.push(move(str));
    //bool yes = solve(str, 0, 0);
    //f.out << "Case #" << t << ": " << (yes ? "YES" : "NO") << endl;
    
  }
  auto res = r.result();
  for (size_t t = 1; t <= T; ++t) {
    f.out << "Case #" << t << ": " << (res.at(t-1) ? "YES" : "NO") << endl;
  }
}
