#include      <algorithm>
#include      <cmath>
#include      <cstdarg>
#include      <cstdio>
#include      <cstdlib>
#include      <iomanip>
#include      <iostream>
#include      <iterator>
#include      <limits>
#include      <list>
#include      <map>
#include      <set>
#include      <queue>
#include      <vector>
// #define endl '\n'
#define each(c, e) for (typeof(c.begin()) e = c.begin(); e != c.end(); ++e)
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;

template<typename T1, typename T2> ostream& operator<<(ostream &o, const pair<T1, T2> &p) {return o << '(' << p.first << ", " << p.second << ')';}
template<typename I> ostream& print(ostream &o, I s, I e, int w = 5, int prec = 2, const string &sep = ", ", const string &lhs = "", const string &rhs = "") {
	o << lhs;
	if (s != e) o << setw(w) << setprecision(prec) << *(s++);
	for (; s != e; ++s) o << sep << setw(w) << setprecision(prec) << *s;
	return o << rhs;
}
template<typename T, template<typename E, typename A=std::allocator<E> > class C>
ostream& operator<<(ostream &o, const C<T>& c) {return print(o, c.begin(), c.end(), 0, 2, ", ", "[", "]");}
template<typename T, template<typename E, typename Compare = less<E>, typename Alloc = allocator<E> > class C>
ostream& operator<<(ostream &o, const C<T>& c) {return print(o, c.begin(), c.end(), 0, 2, ", ", "{", "}");}
template<typename K, typename T, template<typename E1, typename E2, typename Compare = std::less<E1>, class Allocator = std::allocator<std::pair<const E1, E2> > > class C>
ostream& operator<<(ostream &o, const C<K, T>& c) {return print(o, c.begin(), c.end(), 0, 2, ", ", "{", "}");}

ll sz = 0;

ll rec(const vector<ll> &v) {
	static map<vector<ll>, ll> MEMO;
	if (v.empty()) return 0;
	if (MEMO.count(v)) return MEMO[v];

	vector<ll> vs;
	for (int i = 0; i < (int) v.size(); i += 1) if (v[i] != 1) vs.push_back(v[i] - 1);
	ll r = rec(vs) + 1;

	for (int i = 0; i < (int) v.size(); i += 1) {
		for (ll s = 1; s < v[i]; s += 1) {
			vector<ll> vh(v.begin(), v.begin() + i);
			vh.push_back(s); vh.push_back(v[i] - s);
			vh.insert(vh.end(), v.begin() + i + 1, v.end());
			sort(vh.begin(), vh.end());
			r = min(r, rec(vh) + 1);
		}
	}

	return MEMO[v] = r;
}

ll solve() {
	set<pii> diners;

	{
		ll tmp, D;
		cin >> D;
		for (int i = 0; i < D; i += 1) {
			cin >> tmp;
			diners.insert(make_pair(tmp, ++sz));
		}
	}

	vector<ll> v;
	for (set<pii>::iterator it = diners.begin(); it != diners.end(); ++it) v.push_back(it->first);
	return rec(v);

	// ll r = diners.rbegin()->first, d = 1;
	// for (; diners.rbegin()->first != 1; d += 1) {
	// 	pii l = *diners.rbegin();
	// 	diners.erase(l);
	// 	diners.insert(make_pair(l.first / 2 + l.first % 2, ++sz));
	// 	diners.insert(make_pair(l.first / 2, ++sz));
	// 	r = min(r, d + diners.rbegin()->first);
	// }
	// return r;
}

int main(int argc, char **argv) {
	// ios_base::sync_with_stdio(false), cin.tie(0);
	int T;
	cin >> T;
	for (int t = 1; t <= T; t += 1) {
		cerr << "Solving case #" << t << endl;
		cout << "Case #" << t << ": " << solve() << endl;
	}
	
	return 0;
}
