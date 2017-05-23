#include <algorithm>
#include <bitset>
//# define NDEBUG
#include <cassert>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ALL(x) (x).begin(), (x).end()
#define EPS (1E-11)
#define FGE(i, a, b) for(decltype(a) (i) = (a); (i) >= (b); --(i))
#define FGT(i, a, b) for(decltype(a) (i) = (a); (i) >  (b); --(i))
#define FLE(i, a, b) for(decltype(a) (i) = (a); (i) <= (b); ++(i))
#define FLT(i, a, b) for(decltype(a) (i) = (a); (i) <  (b); ++(i))
#define INN(x, y) ((x).find(y) != (x).end())
#define MEM(x, y) memset((x), (y), sizeof(x))
#define PI (3.141592653589793238)
#define S(args...) ({ Phoenix1369::readnum, args; })
#define X first
#define Y second

#define PBDS_RBT(T, U) tree<T, U, std::less<T>, \
	rb_tree_tag, tree_order_statistics_node_update>

#ifndef NDEBUG
	#define Err(args...) { std::cout << "Line " << __LINE__ << ": "; \
		Phoenix1369::debugerr << #args, args; std::cout << std::endl; }
#else
	#define Err(args...)
#endif

typedef long double          lf;
typedef long long int       lld;
typedef long long unsigned  llu;
typedef std::pair<int, int> pii;
typedef std::string         str;
typedef std::vector<int>    vin;
typedef std::vector<pii>    vip;
typedef std::vector<str>    vst;

namespace Phoenix1369
{
	struct DebugErr
	{
		str buf; std::stringstream StringStream;
		template <typename T> DebugErr& operator ,  (const T& val)
		{
			std::getline(StringStream, buf, ',');
			std::cout << buf << " = " << val << ',';
			return *this;
		}

		template <typename T> DebugErr& operator << (const T& val)
		{
			this->StringStream.clear( );
			this->StringStream.str(val);
			return *this;
		}
	} debugerr;

	bool isNum(char C) { return (C == '-') || (('0' <= C) && (C <= '9')); }
	struct ReadNum
	{
		bool neg; char ptr; int iof = 0;
		template <typename C> ReadNum& operator , (C& var)
		{
			do {
				iof = ptr = getchar();
			} while((iof != EOF) && !isNum(ptr));
			if(iof != EOF)
			{
				if(neg = (ptr == '-')) ptr = getchar();
				for(var = ptr - '0'; ((ptr = getchar()) != EOF) && isNum(ptr);
					var = (var << 3) + (var << 1) + (ptr - '0') );
				if(ptr == EOF)
					iof = ptr;
				if(neg) var *= -1;
			}
			return *this;
		}
	} readnum;
}
/** ----------------------------------- END OF TEMPLATE ----------------------------------- **/
const int MAXN = 55;
bool graph[MAXN+15][MAXN]{ };
llu D, L, M;
int N, T;

int main()
{
	//freopen("data.in", "r", stdin);
	freopen("B-small-attempt4.in", "r", stdin);
	freopen("out.txt", "w", stdout);
	S(T);
	for(int T_ = 1; T_ <= T; ++T_)
	{
		S(N, M);
		printf("Case #%d: ", T_);
		L = 1LLU << (N - 2);
		if(M > L)
		{
			puts("IMPOSSIBLE");
			continue;
		}
		puts("POSSIBLE");
		for(int i = 1; i < N; ++i)
			for(int j = i+1; j <= N; ++j)
				graph[i][j] = true;
		D = L - M;
		int k = 0;
		graph[1][N] = false;
		for(llu bit = 1LLU; k < 64; ++k, bit <<= 1) {
			graph[k+2][N] = !!(M & bit);
		}
		if(!D || graph[N][N])
		{
			graph[N][N] = false;
			for(int i = 1; i < N; ++i)
				graph[i][N] = true;
		}
		for(int i = 1; i <= N; ++i)
		{
			for(int j = 1; j <= N; ++j)
				putchar((graph[i][j]) ? '1' : '0');
			putchar('\n');
		}
	}
	return 0;
}