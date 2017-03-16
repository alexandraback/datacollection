#include <algorithm> 
#include <cctype> 
#include <cmath> 
#include <cstdio> 
#include <cstdlib> 
#include <cstring> 
#include <deque> 
#include <iostream> 
#include <list> 
#include <map> 
#include <numeric> 
#include <queue> 
#include <set> 
#include <sstream> 
#include <stack> 
#include <string> 
#include <vector> 
#include <functional>

using namespace std; 

template <class _T> inline string tostr(const _T& a) { ostringstream os(""); os << a; return os.str(); }

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

const double pi = 3.1415926;
const ld eps = 1e-9;
const int N = (int)1e5+5;
const int INF = (int)1e9+10;

const double EPS = 0.00001;

int main() {
	freopen("input.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
    int t;
	cin >> t;
	for(int o = 0; o < t; o++) {
		string s; int n;
		cin >> s >> n;
		int k = 0, sum = 0;
		for(int i = 0; i < s.size(); i++) {
			k = 0; bool f = false;
			for(int j = i; j < s.size(); j++) {
				if(s[j] != 'a' && s[j] != 'i' && s[j] != 'e' && s[j] != 'o' && s[j] != 'u') k++;
				else k = 0;
				if(k >= n) f = true;
				if(f) sum++;
			}
		}
		cout << "Case #" << o+1 << ": " << sum << endl;
	}	
}