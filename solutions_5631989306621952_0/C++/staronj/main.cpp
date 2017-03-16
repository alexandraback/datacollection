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

std::knuth_b random(time(0));

#ifdef COMPILING_HOME
#define DEBUG_MODE
#endif

//using namespace std;

using int8 = char;
using uint8 = unsigned char;
using int16 = short int;
using uint16 = unsigned short int;
using int32 = int;
using uint32 = unsigned int;
using int64 = long long;
using uint64 = unsigned long long;

using int32_pair = std::pair<int32,int32>;
using uint32_pair = std::pair<uint32, uint32>;
using int64_pair = std::pair<int64,int64>;
using uint64_pair = std::pair<uint64,uint64>;

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
constexpr int64  int64_infinity = 1000000000000000000LL;
constexpr uint64 uint64_infinity = int64_infinity;
constexpr int32  int32_infinity = 1000000000LL;
constexpr uint32 uint32_infinity = int32_infinity;


template<class T>
void unique(std::vector<T>& v) {
	sort_all(v);
	v.resize(std::unique(all(v)) - v.begin());
}

std::ostream& newline(std::ostream& str) {
	str.put('\n');
	return str;
}

template<typename T1, typename T2>
std::istream& operator>>(std::istream& stream, std::pair<T1, T2>& pair) {
	stream >> pair.first >> pair.second;
	return stream;
}

template<typename T1, typename T2>
std::ostream& operator<<(std::ostream& stream, const std::pair<T1, T2>& pair) {
#ifdef DEBUG_MODE
	stream << "(" << pair.first << ", " << pair.second << ")";
#else
	stream << pair.first << ' ' << pair.second;
#endif
	return stream;
}

template<typename Iter>
inline std::ostream& print_iterator_range(std::ostream& stream, Iter begin, Iter end) {
	#ifdef DEBUG_MODE
	stream << "(";
	#endif
	for (Iter it = begin ; it != end ; ++ it) {
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

template<typename T>
std::ostream& operator<<(std::ostream& stream, const std::vector<T>& v) {
	return print_iterator_range(stream, all(v));
}

template<typename T>
std::ostream& operator<<(std::ostream& stream, const std::list<T>& v) {
	return print_iterator_range(stream, all(v));
}

template<typename T>
std::ostream& operator<<(std::ostream& stream, const std::set<T>& v) {
	return print_iterator_range(stream, all(v));
}

template<typename T1, typename T2>
std::ostream& operator<<(std::ostream& stream, const std::map<T1, T2>& v) {
	return print_iterator_range(stream, all(v));
}

template<typename T>
std::ostream& operator<<(std::ostream& stream, const std::deque<T>& v) {
	return print_iterator_range(stream, all(v));
}

template<typename T>
std::ostream& operator<<(std::ostream& stream, const std::unordered_set<T>& v) {
	return print_iterator_range(stream, all(v));
}

template<typename T1, typename T2>
std::ostream& operator<<(std::ostream& stream, const std::unordered_map<T1, T2>& v) {
	return print_iterator_range(stream, all(v));
}

template<class T>
inline std::pair<T,T> operator+(const std::pair<T,T>& a, const std::pair<T,T>& b) {
	return std::pair<T,T>(a.first + b.first, a.second + b.second);
}

template<class T>
inline std::pair<T,T> operator-(const std::pair<T,T>& a, const std::pair<T,T>& b) {
	return std::pair<T,T>(a.first - b.first, a.second - b.second);
}

template<class T>
inline void operator+=(std::pair<T,T>& a, const std::pair<T,T>& b) {
	return a = a + b;
}

template<class T>
inline void operator-=(std::pair<T,T>& a, const std::pair<T,T>& b) {
	return a = a - b;;
}

using namespace std;

template<typename Vertex, typename Edge>
class Graph {
public:
	using vertex_type = Vertex;
	using edge_type = Edge;
	using edge_pointer = std::shared_ptr<edge_type>;
	using entry_type = std::pair<uint32, edge_pointer>;
	using list_type = std::vector<entry_type>;

	Graph() = default;

	Graph(uint32 size) {
		resize(size);
	}

	void resize(uint32 k) {
		graph_.resize(k);
		vertex_.resize(k);
	}

	void add(uint32 a, uint32 b, edge_type&& edge) {
		edge_pointer edge_ptr = std::make_shared<edge_type>(std::move(edge));
		graph_[a].emplace_back(b, edge_ptr);
		graph_[b].emplace_back(a, edge_ptr);
	}

	vertex_type& vertex(uint32 n) {
		return vertex_[n];
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

		deque<char> result;
		pair<char, char> prefix('\0', '\0');

		for (char c : word) {
			pair<char, char> t(c, c);

			if (t < prefix) {
				result.push_back(c);
			}
			else {
				result.push_front(c);

				if (c != prefix.first) {
					prefix.second = prefix.first;
					prefix.first = c;
				}
			}
		}

		for (char c : result) {
			cout << c;
		}

		cout << newline;
	}


	void WczytajDane() {
    cin >> ws;
    getline(cin, word);
	}
	string word;
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
