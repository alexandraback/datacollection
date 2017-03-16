# include <iostream>
# include <cstdio>
# include <cstdlib>
# include <vector>
# include <string>
# include <cmath>
# include <algorithm>
# include <iomanip>
# include <deque>
# include <queue>
# include <stack>
# include <numeric>
# include <ios>
# include <set>
# include <map>
# include <sstream>
# include <iterator>
# include <limits>
# include <cstring>
# include <string.h>
# include <list>
# include <bitset>
# include <climits>
# include <cassert>

# define INF numeric_limits<long double>::infinity()
# define Fi 1.6180339887
# define eps 1e-5
# define quattro __float128
# define none() fprintf(stderr, "\nUnexpected in \"%s\" at line %d\n", __func__, __LINE__)

# define startt clock_t start,end; start = clock()
# define endt end = clock(); fprintf(stderr, "\nFunction \"%s\" executed in %.2f seconds\n", __func__, (float)(end-start)/CLOCKS_PER_SEC)
# define checktime() ({ startt; init(); endt; })

using namespace std;

template <typename T> void read(T& val) { cin >> val; }
template <typename T> void read(vector<T>& vec) { for(int i=0; i<vec.size(); ++i) { read(vec[i]); } }
template <typename T> void readSafe(T& val) { cin >> val; }
template <typename T> void readSafe(vector<T>& vec) { for(int i=1; i+1<vec.size(); ++i) { readSafe(vec[i]); } }
template <typename T> void print(const T& val) { cout << val << " " ; }
template <typename T> void print(const vector<T>& vec) { for(int i=0; i<vec.size(); ++i) { print(vec[i]); } cout << endl; }
template <typename T> string toString(const T& val) { ostringstream ostr; ostr << val; return ostr.str(); }
inline long double fromString(const string& str) { long double res; istringstream(str) >> res; return res; }
inline bool isDigit(const char& ch) { return (ch >= '0' && ch <='9'); }
inline bool isAlpha(const char& ch) { return (ch >= 'a' && ch <='z' || ch >='A' && ch <= 'Z'); }
inline string trimString(string& str){ while(*str.begin()==' ') { str.erase(str.begin()); } while(*str.rbegin()==' ') {str.erase(str.end()-1); } return str;}
inline void skip() { while (cin.peek() == ' ' || cin.peek() == '\n' || cin.peek() == '\r' || cin.peek() == '\t') cin.get(); }

template <typename T> class Point {
public:
	T x, y, z, time; 
	Point<T> (const T& a = 0, const T& b = 0, const T& c = 0) : x(a), y(b), z(c) {};
	bool operator<(const Point<T>& b) const { return (y < b.y); }
};

void init()
{	
	int T; cin >> T;
	for(int q=1; q<=T; ++q) {
		int N; cin >> N;
		vector<Point<int> > vec(N);
		for(int i=0; i<N; ++i) {
		    scanf("%d %d", &vec[i].x, &vec[i].y);
		    vec[i].z = 0;
		}
		
        sort(vec.begin(), vec.end());
		
		bool fail = false;
		int L = 0, P = 0;
		for(int i=0; i<vec.size() && !fail; ++i, ++P) {
		    if (vec[i].y > L) {               
		        int need = (vec[i].y - L);
                for(int k=vec.size()-1; k >= 0 && need; --k)
                {
                    if (vec[k].x <= L && vec[k].z == 0)
                    {
                        ++P, ++L;
                        --need;
                        
                        vec[k].z = 1;
                        
                        k = vec.size();
                    }
                }
                
                if (need) {
                    fail = true;
                    break;
                }
		    }
		    
		    L += 2 - vec[i].z;
		    vec[i].z = 2;
		}		
						
		if (fail) {
		    printf("Case #%d: Too Bad\n", q);
		}
		else printf("Case #%d: %d\n", q, P);
	}
}

void test()
{

}

int main()
{
  freopen ("/home/idainet/code/in.txt", "r", stdin);
  freopen ("/home/idainet/code/out.log", "w", stderr);
  freopen ("/home/idainet/code/out.txt", "w", stdout);

   
   //checktime();
   init();
   
//   test();
   
   fflush(stdout);
   return 0;
} 
