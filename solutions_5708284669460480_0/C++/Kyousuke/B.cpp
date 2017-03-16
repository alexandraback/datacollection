//g++ --std=c++14 -Wall -Wno-sign-compare -O2 -s -march=native
#include <iostream>
#include <iterator>
#include <algorithm>
#include <limits>
#include <string>
#include <sstream>
#include <vector>
#include <map>
#include <set>
#include <numeric>
#include <iomanip>
#include <cmath>
using namespace std;

#define forl(i, s, t) for(__typeof(s) i = s; i != t; i++)
#define rforl(i, s, t) for(__typeof(s) i = s; i != t; i--)

#define rep(n) forl(rep_c, 0, n)
#define fill2d_nn(g, s, z, v) forl(i, 0, s) fill_n(g[i], z, v)
#define fill2d_n(g, s, v) fill2d_nn(g, s, s, v)
//#define read(s, t) forl(read_c, s, t) cin >> *read_c
//inline void read(ForwardIterator s, ForwardIterator e) { forl(i, s, e) cin >> *i; }
//#define read_n(x, n) forl(read_n_c, 0, n) cin >> x[read_n_c]
//#define rread_n(x, n) rforl(rread_n_c, n-1, -1) cin >> x[rread_n_c]

#define tpop(x) (x).top(); (x).pop()
#define fpop(x) (x).front(); (x).pop()
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)

template<typename T> inline void chmin(T& a, const T& b) { a = min(a, b); }
template<typename T> inline void chmax(T& a, const T& b) { a = max(a, b); }

template<typename T> T gcd(T a, T b) { if(b == (T)0) return a; return gcd(b, a % b); }
#define gcd_n(a, n) accumulate(a+1, a+n, a[0], gcd);
template <class ForwardIterator>
inline int gcd_r(ForwardIterator s, ForwardIterator e) { return accumulate(s+1, e, s[0], gcd); }

#ifdef DEBUG
#define varcontent(v) #v << '=' << v
#define debug(v) cerr << varcontent(v) << endl
#define pdebug(v, w) cerr << '(' << varcontent(v) << ',' << varcontent(w) << ')' << endl
#define dmsg(a) cerr << a << endl
#else
#define varcontent(v) 0
#define debug(v) 0
#define pdebug(v, w) 0
#define dmsg(a) 0
#endif

#define printarr(a, n) cerr << #a << " = ["; forloop(i, 0, n) cerr << a[i] << ' '; cerr.seekp(cerr.tellp()-1L); cerr << ']' << endl
#define printgrid(g, y, x) cerr << endl << #g << ':' << endl; forl(i, 0, y) { forl(j, 0, x) cerr << g[i][j] << ' '; cerr << endl; } cerr << endl
#define rprintgrid(g, x, y) cerr << endl << #g << ':' << endl; forl(i, 0, x) { forl(j, 0, y) cerr << g[j][i] << ' '; cerr << endl; } cerr << endl
/*inline void printgrid(RandomAccessIterator g, int y, int x) {
	cerr << endl << #g << ':' << endl;
	forloop(i, 0, y) {
		forloop(j, 0, x) cout<< g[i][j] << ' ';
		cout << endl;
	}
	cerr << endl;
}*/
/*inline void rprintgrid(RandomAccessIterator g, int x, int y) {
	cerr << endl << #g << ':' << endl;
	forloop(i, 0, x) {
		forloop(j, 0, y) cout<< g[j][i] << ' ';
		cout << endl;
	}
	cerr << endl;
}*/

const long long INF = numeric_limits<int>::max();
const double EPS = INF*numeric_limits<double>::epsilon();

int longest_suffix(string& target) {
	int sz = target.size();
	vector<string> suf(sz-1);
	forl(i, 1, sz) suf[i-1] = target.substr(i);
	sort(suf.begin(), suf.end());
	int longest = 0;
	for(auto& s : suf) {
		forl(i, 0, sz) if(s[i] != target[i]) {
			chmax(longest, i);
			break;
		}
	}
	return longest;
}

map<int,map<int,map<int,long double> > > cache;
long double calc_prob(map<char,int>& keys, const int K, const int ls, const string& word, int pos, int strokes, int num) {
	if(num < 0) return 0.0;
	if(pos == word.size()) return calc_prob(keys, K, ls, word, ls, strokes, num-1);
	if(strokes == 0) {
		if(num == 0) return 1.0;
		else return 0.0;
	}
	if(cache[pos][strokes].find(num) != cache[pos][strokes].end()) return cache[pos][strokes][num];
	
	long double prob = calc_prob(keys, K, ls, word, pos+1, strokes-1, num) * keys[word[pos]] / (long double)K;
	prob += calc_prob(keys, K, ls, word, 0, strokes-1, num) * (K - keys[word[pos]]) / (long double)K;
	/*forl(s, 0, strokes-1) {
		if(keys[word[pos]]) prob *= calc_prob(keys, K, ls, word, pos+1, strokes-s-1, num) * keys[word[pos]] / K;
		else prob = 0.0;
		if(prob == 0.0) break;
	}*/
	cache[pos][strokes][num] = prob;
	return prob;
}

void gcjmain() {
	cache.clear();
	int K, L, S;
	cin >> K >> L >> S;
	string keyboard, target;
	cin >> keyboard >> target;
	map<char,int> keys;
	for(auto c : keyboard) keys[c]++;
	int ls = longest_suffix(target);
	int cur = 0;
	int count = 0;
	forl(s, 0, S) {
		if(keys[target[cur]]) cur++;
		if(cur == L) {
			count++;
			cur = ls;
		}
	}
	long double prob = 0.0;
	forl(num, 1, count+1) {
		prob += num * calc_prob(keys, K, ls, target, 0, S, num);
		cerr << "prob of " << num << " is " << calc_prob(keys, K, ls, target, 0, S, num) << endl;
	}
	printf("%.7Lf\n", count - prob);
	//cout << count - prob << endl;
	/*int cur = 0;
	double prob = 1.0;
	int count = 0;
	forl(s, 0, S) {
		prob *= (double)keys[target[cur++]] / K;
		if(cur == L) {
			count++;
			cur = ls;
		}
	}
	for(auto c : target) if(keys[c] == 0) {
		count = 0;
		break;
	}
	if(count == 0) cout << 0.0 << endl;
	else {
		forl(i, 1, count+1) {
			
		}
		cerr << "count = " << count << endl;
		cerr << "prob = " << prob << endl;
		cout << count * (1-prob) << endl;
	}*/
}

int main() {
	int T;
	cin >> T;
	forl(t, 1, T+1) {
		cerr << "Case: " << t << '/' << T << endl;
		cout << "Case #" << t << ": ";
		gcjmain();
	}
}
