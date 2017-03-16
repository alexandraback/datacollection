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
#include      <vector>
#define endl '\n'
#define each(c, e) for (typeof(c.begin()) e = c.begin(); e != c.end(); ++e)
typedef long long ll;
using namespace std;

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

int aV[100000];

int E, R, N;
int g_nBest;

void dfs(vector<int> &vectState, int nCur, int nGot) {
	if ((int)vectState.size() == N) {
		g_nBest = max(g_nBest, nGot);
		return;
	}

	int sz = vectState.size();
	for (int i = 0; i <= E; i += 1) {
		vectState.push_back(i);
		int nNext = nCur - vectState[sz];
		if (nNext >= 0) {
			nNext = min(R + nNext, E);
			dfs(vectState, nNext, nGot + i * aV[sz]);
		}
		vectState.pop_back();
	}
}

int solve() {
	cin >> E >> R >> N;
	for (int i = 0; i < N; i += 1) cin >> aV[i];
	g_nBest = 0;
	vector<int> vect;
	dfs(vect, E, 0);
	return g_nBest;
}

int main(int argc, char **argv) {
	ios_base::sync_with_stdio(false), cin.tie(0);
	int T;
	cin >> T;
	for (int t = 1; t <= T; t += 1) {
		cout << "Case #" << t << ": " << solve() << endl;
	}
	return 0;
}
