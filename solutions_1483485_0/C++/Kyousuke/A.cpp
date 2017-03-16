#include <iostream>
#include <algorithm>
#include <limits>
#include <string>
#include <sstream>
#include <vector>
#include <map>
#include <set>
#include <numeric>
using namespace std;

#define forl(i, s, t) for(__typeof(s) i = s; i != t; i++)
#define rforl(i, s, t) for(__typeof(s) i = s; i != t; i--)
#define foreach(itr, c) forl(itr, (c).begin(), (c).end())
#define rforeach(itr, c) forl(itr, (c).rbegin(), (c).rend())

#define gcase int T; cin >> T; for(int gtest = 1; gtest <= T; gtest++)
#define gstate() cerr << "Case: " << gtest << '/' << T << endl
#define gout cout << "Case #" << gtest << ": "

const int INF = numeric_limits<int>::max()/2;
const double EPS = INF*numeric_limits<double>::epsilon();

int main() {
	//char bm[26] = {'y', 'n', 'f', 'i', 'c', 'w', 'l', 'b', 'k', 'u', 'o', 'm', 'x', 's', 'e', 'v', 'z', 'p', 'd', 'r', 'j', 'g', 't', 'h', 'a', 'q'};
	char m[26] = {'y', 'h', 'e', 's', 'o', 'c', 'v', 'x', 'd', 'u', 'i', 'g', 'l', 'b', 'k', 'r', 'z', 't', 'n', 'w', 'j', 'p', 'f', 'm', 'a', 'q'};
	/*forl(i, 'a', 'z'+1) {
		forl(j, 0, 26) if(bm[j] == i) cerr << '\'' << (char)('a'+j) << '\'' << ", ";
	}*/
	gcase {
		gstate();
		string line;
		getline(cin>>ws, line);
		//cerr << line << endl;
		gout;
		foreach(i, line) {
			if((*i) >= 'a' && (*i) <= 'z') cout << m[(*i)-'a'];
			else cout << (*i);
		}
		cout << endl;
	}
}
