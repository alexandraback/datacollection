#include <iostream>
#include <algorithm>
#include <limits>
#include <string>
#include <sstream>
#include <vector>
#include <map>
#include <set>
#include <numeric>
#include <cmath>
using namespace std;

#define forl(i, s, t) for(__typeof(s) i = s; i != t; i++)
#define rforl(i, s, t) for(__typeof(s) i = s; i != t; i--)
#define foreach(itr, c) forl(itr, (c).begin(), (c).end())
#define rforeach(itr, c) forl(itr, (c).rbegin(), (c).rend())

template<typename T> inline void step(T& i, T& t) { if(i < t) i++; else i--;}
template<typename T> inline int towards(T i, T t) { if(i < t) return ++i; else if(i > t) return --i; else return i;}
template<typename T> inline int away(T i, T t) { if(i < t) return --i; else if(i > t) return ++i; else return i;}
#define sforl(i, s, t) for(__typeof(s) i = s; i != t; step(i,t))

#define varcontent(v) #v << '=' << v
#define debug(v) cerr << varcontent(v) << endl
#define pdebug(v, w) cerr << '(' << varcontent(v) << ',' << varcontent(w) << ')' << endl

#define gcase int T; cin >> T; for(int gtest = 1; gtest <= T; gtest++)
#define gstate() cerr << "Case: " << gtest << '/' << T << endl
#define gout cout << "Case #" << gtest << ": "

int gcd(int a, int b) { if(b == 0) return a; return gcd(b, a % b); }

const int INF = numeric_limits<int>::max()/2;
const double EPS = INF*numeric_limits<double>::epsilon();

int main() {
	gcase {
		gstate();
		int N;
		cin >> N;
		multiset<pair<int,int> > lvl;
		forl(n, 0, N) {
			int fir, sec;
			cin >> fir >> sec;
			lvl.insert(pair<int,int>(fir,sec));
		}
		//sort(lvl.begin(), lvl.end());
		
		//foreach(i, lvl) cerr << i->first << ',' << i->second << endl;
		
		multiset<int> part;
		int cur = 0, ans = 0;
		bool bad = false;
		while(!lvl.empty() && !bad) {
			bad = true;
			set<pair<int,int> >::iterator itr = lvl.begin(), itr2 = lvl.begin();
			while(itr != lvl.end() && itr->first <= cur && itr->second > cur) {
				if(itr->second > itr2->second) itr2 = itr;
				itr++;
			}
			if(itr != lvl.end() && itr->second <= cur) {
				cur += 2;
				bad = false;
				lvl.erase(itr);
			}
			else if(!part.empty() && *(part.begin()) <= cur) {
				cur++;
				bad = false;
				part.erase(part.begin());
			}
			else if(itr2->first <= cur) {
				cur++;
				bad = false;
				part.insert(itr2->second);
				lvl.erase(itr2);
			}
			ans++;
		}
		while(!part.empty() && !bad) {
			bad = true;
			if(*(part.begin()) <= cur) {
				cur++;
				bad = false;
				part.erase(part.begin());
			}
			ans++;
		}
		
		if(bad) gout << "Too Bad" << endl;
		else gout << ans << endl;
	}
}
