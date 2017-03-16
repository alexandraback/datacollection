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

#define varcontent(v) #v << '=' << v
#define debug(v) cerr << varcontent(v) << endl
#define pdebug(v, w) cerr << '(' << varcontent(v) << ',' << varcontent(w) << ')' << endl

#define gcase int T; cin >> T; for(int gtest = 1; gtest <= T; gtest++)
#define gstate() cerr << "Case: " << gtest << '/' << T << endl
#define gout cout << "Case #" << gtest << ": "

const int INF = numeric_limits<int>::max()/2;
const double EPS = INF*numeric_limits<double>::epsilon();

int count(int A, int B) {
	set< pair<int,int> > done;
	forl(n, A, B) {
		int d = 1, m = n;
		while(m > 0) {
			m /= 10;
			d *= 10;
		}
		
		int t = 10;
		m = n;
		while(n / t > 0) {
			m = n/t + (d/t) * (n%t);
			if(n < m && m <= B) {
				done.insert(pair<int,int>(n,m));
				//pdebug(n, m);
			}
			t *= 10;
		}
	}
	return done.size();
}

int main() {
	gcase {
		gstate();
		int A, B;
		cin >> A >> B;
		gout << count(A, B) << endl;
	}
}
