// #define NDEBUG
#include <bits/stdc++.h>
using namespace std;

using int8 = int8_t;
using int16 = int16_t;
using int32 = int32_t;
using int64 = int64_t;
// using int128 = __int128;
using uint8 = int8_t;
using uint16 = uint16_t;
using uint32 = uint32_t;
using uint64 = uint64_t;
// using uint128 = unsigned __int128;
using float128 = __float128;


 
#define max(a, b) (((a) >= (b)) ? a : b)
#define min(a, b) (((a) <= (b)) ? a : b)
#define abs(a) (((a) < 0) ? -(a) : (a))
#define sz size()
#define mt make_tuple
#define pb push_back
#define has(s, v) ((s).find(v) != (s).end())
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define unique(s) s.resize(unique(all(s)) - s.begin())
#define clr(a, b) memset(a, b, sizeof(a))
#define sqr(a) ((a) * (a))
/*
// Array definition.
template <class T, size_t head, size_t... tail>
struct MultiArray 
{
  using nested = typename MultiArray<T, tail...>::type;
  using type = array<nested, head>;
};
 
template <class T, size_t size>
struct MultiArray<T, size> 
{
  using type = array<T, size>;
};

template <class T, size_t head, size_t... tail>
using A = typename MultiArray<T, head, tail...>::type;

// Vector definition.
template <class T, size_t dimension>
struct MultiVector 
{
  using nested = typename MultiVector<T, dimension - 1>::type;
  using type = vector<nested>;
};
 
template <class T>
struct MultiVector<T, 1> 
{
  using type = vector<T>;
};

template <class T, size_t dimension>
using V = typename MultiVector<T, dimension>::type;

// Debug output.
void dout() { cout << endl; }

template <typename Head, typename... Tail>
void dout(Head head, Tail... tail) {
  cout << head << ' ';
  dout(tail...);
}
*/
char buffer[1 << 20];

inline int readInt() {
  int value;
  scanf("%d", &value);
  return value;
}

inline int64 readInt64() {
  int64 value;
  scanf("%" SCNd64, &value);
  return value;
}

inline int64 readUInt64() {
  uint64 value;
  scanf("%" SCNu64, &value);
  return value;
}

inline char readChar() {
  char value;
  scanf("%c", &value);
  return value;
}

inline double readDouble() {
  double value;
  scanf("%lf", &value);
  return value;
}

inline string readString() {
  scanf("%s", buffer);
  return string(buffer);
}

inline string readLine() {
  string value;
  getline(cin, value);
  return value;
}

inline void print(int value) {
  printf("%d", value);
}

inline void print(int64 value) {
  printf("%" PRId64, value);
}

inline void print(uint64 value) {
  printf("%" PRIu64, value);
}

inline void print(char value) {
  printf("%c", value);
}

inline void print(double value) {
  printf("%.20lf", value);
}

inline void print(string value) {
  printf("%s", value.c_str());
}

template<typename T>
inline void printLine(const T& value) {
  print(value);
  print('\n');
}
/*
template <typename Iterator>
inline void printLine (Iterator first, Iterator last) {
  if (first != last) {
    while(true) {
      print(*first);
      ++first;
      if (first == last) {
        print('\n');
        break;
      } else {
        print(' ');
      }
    }
  }
}

template<typename T>
inline void printLine(const V1<T>& vec) {
  printLine(all(vec));
}

template<typename T>
inline void printLine(const V2<T>& vec) {
  for (auto& x : vec)
    printLine(all(x));
}

template<typename T, size_t N>
inline void printLine(const A1<T, N>& arr) {
  printLine(all(arr));
}

template<typename T, size_t N1, size_t N2>
inline void printLine(const A2<T, N1, N2>& arr) {
  for (auto& x : arr)
    printLine(all(x));
}*/

// START

int64 dp[32][2][2][2];

int A, B, K;

int64 f(int pos, int la, int lb, int lk) {
	if (pos < 0) return 1;

	int64& r = dp[pos][la][lb][lk];
	if (r != -1) return r;

	int64 res = 0;
	for (int bita = 0; bita <= 1; ++bita)
		for (int bitb = 0; bitb <= 1; ++bitb) {
			int nla, nlb, nlk;

			if (bita) {
				if (la) {
					nla = 1;
				} else {
					if ((A >> pos) & 1) {
						nla = 0;
					} else {
						nla = -1;
					}
				}
			} else {
				if (la) {
					nla = 1;
				} else {
					if ((A >> pos) & 1) {
						nla = 1;
					} else {
						nla = 0;
					}
				}
			}

			if (bitb) {
				if (lb) {
					nlb = 1;
				} else {
					if ((B >> pos) & 1) {
						nlb = 0;
					} else {
						nlb = -1;
					}
				}
			} else {
				if (lb) {
					nlb = 1;
				} else {
					if ((B >> pos) & 1) {
						nlb = 1;
					} else {
						nlb = 0;
					}
				}
			}


			if (bita & bitb) {
				if (lk) {
					nlk = 1;
				} else {
					if ((K >> pos) & 1) {
						nlk = 0;
					} else {
						nlk = -1;
					}
				}
			} else {
				if (lk) {
					nlk = 1;
				} else {
					if ((K >> pos) & 1) {
						nlk = 1;
					} else {
						nlk = 0;
					}
				}
			}


			if (nla >= 0 && nlb >= 0 && nlk >= 0)
				res += f(pos - 1, nla, nlb, nlk);
		}

	return r = res;
}

void solve() {
	int T = readInt();
	for (int t = 0; t < T; ++t) {
		printf("Case #%d: ", t + 1);
		A = readInt() - 1;
		B = readInt() - 1;
		K = readInt() - 1;
		clr(dp, -1);
		cout << f(30, 0, 0, 0) << endl;	
	}
}

// END

int main() {
#ifdef LOCAL
  freopen("/home/outside/coding/workspace/c++/io/input.txt", "r", stdin);
  freopen("/home/outside/coding/workspace/c++/io/output.txt", "w", stdout);
#else
  // freopen("file_name","r",stdin);
  // freopen("file_name","w",stdout);
#endif

  srand(time(nullptr));
  solve();
  
  return 0;
}
