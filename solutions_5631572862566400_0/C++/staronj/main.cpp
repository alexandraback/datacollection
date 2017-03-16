//Jakub Staro�
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <list>
#include <deque>
#include <queue>
#include <stack>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <stdexcept>
#include <unordered_map>
#include <unordered_set>
#include <random>
#include <memory>
#include <utility>

std::knuth_b random(time(0));

#define DEBUG_MODE

//using namespace std;

using int8 = char;
using uint8 = unsigned char;
using int16 = short int;
using uint16 = unsigned short int;
using int32 = int;
using uint32 = unsigned int;
using int64 = long long;
using uint64 = unsigned long long;

using int32_pair = std::pair<int32, int32>;
using uint32_pair = std::pair<uint32, uint32>;
using int64_pair = std::pair<int64, int64>;
using uint64_pair = std::pair<uint64, uint64>;

using bit_vector = std::vector<bool>;

#ifdef DEBUG_MODE
#define debug_print(x) cerr << #x << " = " << x << endl
#define print_line cerr << "Line " << __LINE__ << endl

#include <cassert>

#else
#define debug_print(x)
#define print_line
#define assert(x)
#endif

#define rep(i, x) for(int32 i = 0 ; i < (x) ; i++)
#define for_range(i, begin, end) for(auto i = (begin) ; i != (end) ; ++i )
#define all(c) (c).begin(),(c).end()
#define sort_all(x) std::sort( all(x) )
#define divide(a, b) ( ( (b)%(a) ) == 0 )
#define mp(x, y) make_pair(x,y)
#define pb(x) push_back(x)

#define sig(x) ( (x) == 0 ? 0 : ( (x) < 0 ? -1 : 1 ) )

constexpr double epsilon = 1e-5;
constexpr int64 int64_infinity = 1000000000000000000LL;
constexpr uint64 uint64_infinity = int64_infinity;
constexpr int32 int32_infinity = 1000000000LL;
constexpr uint32 uint32_infinity = int32_infinity;


template <class T>
void unique(std::vector<T>& v) {
  sort_all(v);
  v.resize(std::unique(all(v)) - v.begin());
}

std::ostream& newline(std::ostream& str) {
  str.put('\n');
  return str;
}

template <typename T1, typename T2>
std::istream& operator>>(std::istream& stream, std::pair<T1, T2>& pair) {
  stream >> pair.first >> pair.second;
  return stream;
}

template <typename T1, typename T2>
std::ostream& operator<<(std::ostream& stream, const std::pair<T1, T2>& pair) {
#ifdef DEBUG_MODE
  stream << "(" << pair.first << ", " << pair.second << ")";
#else
  stream << pair.first << ' ' << pair.second;
#endif
  return stream;
}

template <typename Iter>
inline std::ostream& print_iterator_range(std::ostream& stream, Iter begin, Iter end) {
#ifdef DEBUG_MODE
  stream << "(";
#endif
  for (Iter it = begin ; it != end ; ++it) {
    if (it != begin) {
#ifdef DEBUG_MODE
      stream << ", ";
#else
      stream << " ";
#endif
    }
    stream << *it;
  }
#ifdef DEBUG_MODE
  stream << ")";
#endif
  return stream;
}

template <typename T>
std::ostream& operator<<(std::ostream& stream, const std::vector<T>& v) {
  return print_iterator_range(stream, all(v));
}

template <typename T>
std::ostream& operator<<(std::ostream& stream, const std::list<T>& v) {
  return print_iterator_range(stream, all(v));
}

template <typename T>
std::ostream& operator<<(std::ostream& stream, const std::set<T>& v) {
  return print_iterator_range(stream, all(v));
}

template <typename T1, typename T2>
std::ostream& operator<<(std::ostream& stream, const std::map<T1, T2>& v) {
  return print_iterator_range(stream, all(v));
}

template <typename T>
std::ostream& operator<<(std::ostream& stream, const std::deque<T>& v) {
  return print_iterator_range(stream, all(v));
}

template <typename T>
std::ostream& operator<<(std::ostream& stream, const std::unordered_set<T>& v) {
  return print_iterator_range(stream, all(v));
}

template <typename T1, typename T2>
std::ostream& operator<<(std::ostream& stream, const std::unordered_map<T1, T2>& v) {
  return print_iterator_range(stream, all(v));
}

template <class T>
inline std::pair<T, T> operator+(const std::pair<T, T>& a, const std::pair<T, T>& b) {
  return std::pair<T, T>(a.first + b.first, a.second + b.second);
}

template <class T>
inline std::pair<T, T> operator-(const std::pair<T, T>& a, const std::pair<T, T>& b) {
  return std::pair<T, T>(a.first - b.first, a.second - b.second);
}

template <class T>
inline void operator+=(std::pair<T, T>& a, const std::pair<T, T>& b) {
  return a = a + b;
}

template <class T>
inline void operator-=(std::pair<T, T>& a, const std::pair<T, T>& b) {
  return a = a - b;;
}

using namespace std;

template <typename Vertex>
class Graph {
  public:
  using vertex_type = Vertex;
  using entry_type = uint32;
  using list_type = std::vector<entry_type>;

  Graph() = default;

  Graph(uint32 size) {
    resize(size);
  }

  void resize(uint32 k) {
    graph_.resize(k);
    vertex_.resize(k);
  }

  void add(uint32 a, uint32 b) {
    graph_[a].push_back(b);
  }

  uint32 deg(uint32 k) {
    return graph_[k].size();
  }

  list_type& obok(uint32 k) {
    return graph_[k];
  }

  uint32 size() {
    return graph_.size();
  }

  private:
  std::vector<list_type> graph_;
  std::vector<vertex_type> vertex_;
};


class Application {
  public:
  Application() {

  }

  void Run(uint32 number) {
    WczytajDane();
    cout << "Case #" << (number + 1) << ": ";

    rep (i, N) {
      if (result[i] == -1)
        SolveCircle(i);
    }

    sort(all(cycles), [](const vector<uint32>&a, const vector<uint32>&b) {
      return a.size() < b.size();
    });

    rep (i, N) {
      if (on_cycle[i]) {
        path_length[i] = DFS(i);
      }
    }

    uint32 paths = 0;
    for (const vector<uint32>& cycle : cycles) {
      if (cycle.size() > 2)
        break;

      paths += 2 + path_length[cycle[0]] + path_length[cycle[1]];
    }

    uint32 max_cycle = *max_element(all(result));

    //debug_print(path_length);
    //debug_print(cycles);

    cout << max(paths, max_cycle);
    cout << newline;
  }

  uint32 DFS(uint32 v) {
    uint32 max_result = 0;
    for (uint32 u : reverse_graph.obok(v)) {
      if (!on_cycle[u])
        max_result = max(max_result, 1 + DFS(u));
    }
    return max_result;
  }

  void SolveCircle(uint32 v) {
    vector<uint32> path;
    uint32 u = v;

    // first, find the cycle or already visited place
    do {
      path.push_back(v);
      v = best[v];
      u = best[best[u]];
    } while (u != v && result[v] == -1);


    if (result[v] == -1) {
      vector<uint32> cycle;

      // second, find the cycle length
      uint32 length = 0;
      do {
        length++;
        cycle.push_back(u);
        path.push_back(u);
        on_cycle[u] = true;
        u = best[u];
      } while (u != v);

      result[v] = length;
      cycles.push_back(std::move(cycle));
    }

    for (uint32 g : path) {
      result[g] = result[v];
    }
  }


  void WczytajDane() {
    cin >> N;
    best.resize(N);
    reverse_graph.resize(N);
    on_cycle.assign(N, false);
    path_length.assign(N, -1);
    rep (i, N) {
      uint32 t;
      cin >> t;
      best[i] = t - 1;
      reverse_graph.add(t - 1, i);
    }
    result.assign(N, -1);
  }

  vector<uint32> best;
  vector<int32> result;
  vector<vector<uint32>> cycles;
  bit_vector on_cycle;
  uint32 N;

  vector<int32> path_length;
  Graph<uint32> reverse_graph;
};


int main() {
  std::ios::sync_with_stdio(0);
  uint32 T;
  cin >> T;
  rep (i, T) {
    Application application;
    application.Run(i);
  }
  return 0;
}
