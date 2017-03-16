# include <iostream>
# include <iomanip>
# include <sstream>

# include <cstdio>
# include <cstdlib>
# include <cstring>
# include <cmath>
# include <ctime>
# include <cassert>
# include <cctype>
# include <climits>

# include <algorithm>
# include <bitset>
# include <deque>
# include <map>
# include <queue>
# include <set>
# include <stack>
# include <string>
# include <vector>

# include <functional>
# include <limits>
# include <numeric>
# include <utility>
# include <typeinfo>

using namespace std;

# define LIM(T) numeric_limits<T>::max()
# define INF numeric_limits<float>::infinity()

typedef unsigned char 		u8;
typedef unsigned short 		u16;
typedef unsigned int 			u32;
typedef unsigned long long 	u64;

template <typename T> string toString(const T &what)
{
	ostringstream os;
	os << what;				// Bad precision for floats
	return os.str();
}

template <typename T_out, typename T_in> T_out fromString(const T_in &what) 
{
	T_out res;
	istringstream(what) >> res;
	return res;
}

template <typename T> ostream& operator<< (ostream &os, const vector<T> &vec) 
{
	for(size_t i=0; i<vec.size(); ++i) {
		os << vec[i] << " ";
	}
	return (os << endl);
}

template <u64 N> struct F { enum { ret = F<N-1>::ret*N }; };
template <> struct F<0> { enum { ret = 1 }; }; 

void init()
{
	int T; cin >> T;
	for(int q=1; q<=T; ++q)
	{
		string name; cin >> name;
		int len; cin >> len;
		
		cerr << name << len << endl;
		
		int count = 0;
		for(int i=len; i<=name.size(); ++i)
		{
			for(int k=0; k+i<=name.size(); ++k)
			{
				cerr << i << " " << k << endl;
				int mx = -1, cur = 0;
				for(int x=k; x<k+i; ++x)
				{
					if (string("aeiou").find(name[x]) == string::npos)
					{
						if (cur == 0) cur = 1;
						else ++cur;
					}
					else {
						mx = max(mx, cur);
						cur = 0;
					}
				}
				mx = max(mx, cur);
				count += (mx >= len);
			}
		}
		printf("Case #%d: %d\n", q, count);
	}
}

void checktime()
{
	clock_t start = clock();
		init();
	clock_t end = clock();
	
	fprintf(stderr, "Time is %.4f\n", (end-start)*1.0/CLOCKS_PER_SEC);
}

int main()
{
	freopen("input", "r", stdin);
	freopen("output", "w", stdout);
	freopen("error", "w", stderr);
	
	//init();
	checktime();
	
	fflush(stdout);
	return 0;
}
